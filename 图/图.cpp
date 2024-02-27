#include<stdio.h>
#include<stdlib.h>
#define NUM 100//图顶点最大数量
#define MAX 65535//邻接矩阵无穷大 
typedef int EdgeType;//边类型 
typedef int VerTexType;//顶点类型 
typedef struct MGraph{
	VerTexType Vex[NUM];//顶点
	EdgeType Edge[NUM][NUM];//邻接矩阵
	int Vexnum,Edgenum;//顶点数，边数 
}MGraph;//邻接矩阵

void creat_M(MGraph *G){//邻接矩阵建立 
	printf("请输入顶点数：");
	scanf("%d",&G->Vexnum);
	printf("请输入边数：");
	scanf("%d",&G->Edgenum);
	for(int i=0;i<G->Vexnum;i++)
	{
		G->Vex[i]=i;//顶点序号 
	}
	for(int i=0;i<G->Vexnum;i++)
	{
		for(int j=0;j<G->Vexnum;j++)
		{
			G->Edge[i][j]=MAX;//将权值初始化为无穷 
		}
	}
	for(int k=0;k<G->Edgenum;k++)
	{
		int v1,v2;
		EdgeType e;
		//printf("请输入边的两个顶点和权值：");
		scanf("%d%d%d",&v1,&v2,&e);
		G->Edge[v1][v2]=e;
		G->Edge[v2][v1]=e;//无向图 
	}
} 


typedef struct EdgeNode{//边表节点 
	VerTexType Edgevex;
	struct EdgeNode* next;//指向下一个边表节点 
}EdgeNode;
typedef struct VexNode{
	VerTexType Vex;
	EdgeNode* firstEdge;//边表 
}VexNode;
typedef struct LGraph{//邻接表 
	VexNode vexs[NUM];
	int vexnum,edgenum;
}LGraph;


void creat_L(LGraph *G){//邻接表的建立 
	printf("请输入顶点数：");
	scanf("%d",&G->vexnum);
	printf("请输入边数：");
	scanf("%d",&G->edgenum);
	for(int i=0;i<G->vexnum;i++)
	{
		G->vexs[i].Vex=i;//顶点序号 
		G->vexs[i].firstEdge=NULL;//边表为空 
	}
	for(int j=0;j<G->edgenum;j++)
	{
		printf("请输入边连接的结点：");
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		EdgeNode* Edge=(EdgeNode*)malloc(sizeof(EdgeNode));//边表结点
		Edge->Edgevex=v2;
		Edge->next=G->vexs[v1].firstEdge;
		G->vexs[v1].firstEdge=Edge;
	}
}

bool visited[NUM];
void DFS_M(MGraph *G,int v){//邻接矩阵深度优先搜索 
	printf("%d",v);
	visited[v]=true;
	for(int i=0;i<G->Vexnum;i++)
	{
		if(G->Edge[v][i]!=MAX&&visited[i]!=true)
		{
			DFS_M(G,i);
		}
	}
}

void DFS_L(LGraph *G,int v){//邻接表深度优先搜索 
	printf("%d",v);
	visited[v]=true;
	EdgeNode* p;
	p=G->vexs[v].firstEdge;
	while(p)
	{
		if(visited[p->Edgevex]!=true)
		{
			DFS_L(G,p->Edgevex);
		}
		p=p->next;
	}
}

typedef struct{
	int val[NUM];
	int front;
	int rear;
}Queue;//队列

void initq(Queue *q){
	q->front=-1;
	q->rear=-1;
}

void enqueue(Queue *q,int e){//入队 
	q->rear++;
	q->val[q->rear]=e;
} 

void dequeue(Queue *q,int *e){//出队 
	q->front++;
	(*e)=q->val[q->front];
}


void BFS_M(MGraph *G){//邻接矩阵广度优先搜索 
	Queue q;
	initq(&q);
	for(int i=0;i<G->Vexnum;i++)//对每个顶点做访问 
	{
		if(visited[i]!=true)//未访问过 
		{
			visited[i]=true;//访问
			printf("%d",G->Vex[i]);
			enqueue(&q,i);//入队
			while(q.front!=q.rear)
			{
				int t; 
				dequeue(&q,&t);//队首出队
				for(int j=0;j<G->Vexnum;j++)
				{
					if(G->Edge[t][j]!=MAX&&visited[j]!=true)
					{
						visited[j]=true;//访问
						printf("%d",G->Vex[j]);
						enqueue(&q,j);//入队 
					}	
				}		
			} 
		}
	}
}

/*
void BFS_L(LGraph *G,int s)//邻接表广度优先搜索
{
	Queue q;
	initq(&q);
	EdgeNode *v;
	for(int i=0;i<G->vexnum;i++)//对每个顶点进行访问 
	{
		if(visited[s]==false)
		{
			visited[s]=true;
			visit[s];//输出 
			enqueue(&q,s);//入队 
			while(q.front!=q.rear)//队列不为空 
			{
				int t;
				dequeue(&q,&t);
				v=Graph->G[t].FirstEdge;//指向边表 
				while(v!=NULL)//边表不为空 
				{
					if(visited[v->AdjV]==false)
					{
						visited[v->AdjV]==true;
						visit[v->AdjV];
						enqueue(&q,v->AdjV);//入队 
					}
					v=v->Next;
				}
			}
		}
	}
}

*/

typedef struct close{
	VerTexType start;//起点
	int val;//边的权值 
	bool visit;//边是否已在树中，true为在 
}closed[NUM];


int MIN(MGraph *G,closed close){//获取close数组权值最小的边 
	int min=65535; 
	int minend;//记录下标 
	for(int i=0;i<G->Vexnum;i++)
	{
		if((close[i].val<min)&&close[i].visit!=true)
		{
			minend=i;
			min=close[i].val;
		}
	}
	return minend;
}


void Prim(MGraph *G,int s){//邻接矩阵的普里姆算法,从s开始,临界矩阵无边设为无穷大 
	closed close;//close数组
	for(int i=0;i<G->Vexnum;i++)//初始化close数组,假设起点和其他顶点都有边,close[i]表示终点为i，起点为start 
	{
		if(i==s)
		{
			close[i].start=s;
			close[i].val=MAX;//起点到起点距离为无穷 
		    close[i].visit=true;//起点到起点已经在树中 
		}
		else
		{
			close[i].start=s;
			close[i].val=G->Edge[s][i];	
			close[i].visit=false;
		}	
	}
	for(int j=1;j<G->Vexnum;j++)//从1开始是因为不考虑起点s 
	{
		int end=MIN(G,close);//获取当前close数组中权值最小的边的终点，此条边为最小生成树的一条边 
		int start=close[end].start;
		int val=close[end].val;
		printf("%d->%d,%d\n",start,end,val);
		close[end].visit=true;//此条边为树的一条边 
		for(int k=0;k<G->Vexnum;k++)//更新close数组 
		{
			if((G->Edge[end][k])<close[k].val)//若刚才获取的边的终点到k的权值小于close[k]中start到k的权值，则更新
			{
				close[k].start=end;
				close[k].val=G->Edge[end][k];	
			} 
		}
	} 
}


void floyd(MGraph *G){//邻接矩阵的弗洛伊德算法
	int i,j;
	EdgeType D[NUM][NUM];//最短路径 
	EdgeType P[NUM][NUM];//邻接点 
	for(i=0;i<G->Vexnum;i++)//初始化两个辅助数组 
	{
		for(j=0;j<G->Vexnum;j++)
		{
			D[i][j]=G->Edge[i][j];
			P[i][j]=j; 
		}
	}
//	for(i=0;i<G->Vexnum;i++)
//	{
//		for(j=0;j<G->Vexnum;j++)
//		{
//			printf("%d ",D[i][j]);
//		}
//		printf("\n");
//	}
	int mid,start,end;
	for(mid=0;mid<G->Vexnum;mid++)//中间点 
	{
		for(start=0;start<G->Vexnum;start++)//起点 
		{
			for(end=0;end<G->Vexnum;start++)//终点 
			{
				if(D[start][end]>(D[start][mid]+D[mid][end]))//若start到end大于start到mid到end，更新D矩阵 
				{
					D[start][end]=D[start][mid]+D[mid][end];
					P[start][end]=P[start][mid];//更新start的邻接点 
				}
			}
		}
	}
	int v,w;
	int k;
	scanf("%d%d",&v,&w);//输入查询的起点终点
	printf("%d",v);
	k=P[v][w];
	while(k!=w)
	{
		printf("->%d",k);
		k=P[k][w];	
	} 
	printf("->%d",w);
}



int main()
{
	MGraph G1;
	creat_M(&G1);
	BFS_M(&G1);
//	DFS_M(&G1,0);
//	Prim(&G1,0);
//	floyd(&G1);
//	LGraph G2;
//	creat_L(&G2);
//	DFS_L(&G2,0);
	return 0;
}
