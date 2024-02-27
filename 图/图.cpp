#include<stdio.h>
#include<stdlib.h>
#define NUM 100//ͼ�����������
#define MAX 65535//�ڽӾ�������� 
typedef int EdgeType;//������ 
typedef int VerTexType;//�������� 
typedef struct MGraph{
	VerTexType Vex[NUM];//����
	EdgeType Edge[NUM][NUM];//�ڽӾ���
	int Vexnum,Edgenum;//������������ 
}MGraph;//�ڽӾ���

void creat_M(MGraph *G){//�ڽӾ����� 
	printf("�����붥������");
	scanf("%d",&G->Vexnum);
	printf("�����������");
	scanf("%d",&G->Edgenum);
	for(int i=0;i<G->Vexnum;i++)
	{
		G->Vex[i]=i;//������� 
	}
	for(int i=0;i<G->Vexnum;i++)
	{
		for(int j=0;j<G->Vexnum;j++)
		{
			G->Edge[i][j]=MAX;//��Ȩֵ��ʼ��Ϊ���� 
		}
	}
	for(int k=0;k<G->Edgenum;k++)
	{
		int v1,v2;
		EdgeType e;
		//printf("������ߵ����������Ȩֵ��");
		scanf("%d%d%d",&v1,&v2,&e);
		G->Edge[v1][v2]=e;
		G->Edge[v2][v1]=e;//����ͼ 
	}
} 


typedef struct EdgeNode{//�߱�ڵ� 
	VerTexType Edgevex;
	struct EdgeNode* next;//ָ����һ���߱�ڵ� 
}EdgeNode;
typedef struct VexNode{
	VerTexType Vex;
	EdgeNode* firstEdge;//�߱� 
}VexNode;
typedef struct LGraph{//�ڽӱ� 
	VexNode vexs[NUM];
	int vexnum,edgenum;
}LGraph;


void creat_L(LGraph *G){//�ڽӱ�Ľ��� 
	printf("�����붥������");
	scanf("%d",&G->vexnum);
	printf("�����������");
	scanf("%d",&G->edgenum);
	for(int i=0;i<G->vexnum;i++)
	{
		G->vexs[i].Vex=i;//������� 
		G->vexs[i].firstEdge=NULL;//�߱�Ϊ�� 
	}
	for(int j=0;j<G->edgenum;j++)
	{
		printf("����������ӵĽ�㣺");
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		EdgeNode* Edge=(EdgeNode*)malloc(sizeof(EdgeNode));//�߱���
		Edge->Edgevex=v2;
		Edge->next=G->vexs[v1].firstEdge;
		G->vexs[v1].firstEdge=Edge;
	}
}

bool visited[NUM];
void DFS_M(MGraph *G,int v){//�ڽӾ�������������� 
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

void DFS_L(LGraph *G,int v){//�ڽӱ������������ 
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
}Queue;//����

void initq(Queue *q){
	q->front=-1;
	q->rear=-1;
}

void enqueue(Queue *q,int e){//��� 
	q->rear++;
	q->val[q->rear]=e;
} 

void dequeue(Queue *q,int *e){//���� 
	q->front++;
	(*e)=q->val[q->front];
}


void BFS_M(MGraph *G){//�ڽӾ������������� 
	Queue q;
	initq(&q);
	for(int i=0;i<G->Vexnum;i++)//��ÿ������������ 
	{
		if(visited[i]!=true)//δ���ʹ� 
		{
			visited[i]=true;//����
			printf("%d",G->Vex[i]);
			enqueue(&q,i);//���
			while(q.front!=q.rear)
			{
				int t; 
				dequeue(&q,&t);//���׳���
				for(int j=0;j<G->Vexnum;j++)
				{
					if(G->Edge[t][j]!=MAX&&visited[j]!=true)
					{
						visited[j]=true;//����
						printf("%d",G->Vex[j]);
						enqueue(&q,j);//��� 
					}	
				}		
			} 
		}
	}
}

/*
void BFS_L(LGraph *G,int s)//�ڽӱ�����������
{
	Queue q;
	initq(&q);
	EdgeNode *v;
	for(int i=0;i<G->vexnum;i++)//��ÿ��������з��� 
	{
		if(visited[s]==false)
		{
			visited[s]=true;
			visit[s];//��� 
			enqueue(&q,s);//��� 
			while(q.front!=q.rear)//���в�Ϊ�� 
			{
				int t;
				dequeue(&q,&t);
				v=Graph->G[t].FirstEdge;//ָ��߱� 
				while(v!=NULL)//�߱�Ϊ�� 
				{
					if(visited[v->AdjV]==false)
					{
						visited[v->AdjV]==true;
						visit[v->AdjV];
						enqueue(&q,v->AdjV);//��� 
					}
					v=v->Next;
				}
			}
		}
	}
}

*/

typedef struct close{
	VerTexType start;//���
	int val;//�ߵ�Ȩֵ 
	bool visit;//���Ƿ��������У�trueΪ�� 
}closed[NUM];


int MIN(MGraph *G,closed close){//��ȡclose����Ȩֵ��С�ı� 
	int min=65535; 
	int minend;//��¼�±� 
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


void Prim(MGraph *G,int s){//�ڽӾ��������ķ�㷨,��s��ʼ,�ٽ�����ޱ���Ϊ����� 
	closed close;//close����
	for(int i=0;i<G->Vexnum;i++)//��ʼ��close����,���������������㶼�б�,close[i]��ʾ�յ�Ϊi�����Ϊstart 
	{
		if(i==s)
		{
			close[i].start=s;
			close[i].val=MAX;//��㵽������Ϊ���� 
		    close[i].visit=true;//��㵽����Ѿ������� 
		}
		else
		{
			close[i].start=s;
			close[i].val=G->Edge[s][i];	
			close[i].visit=false;
		}	
	}
	for(int j=1;j<G->Vexnum;j++)//��1��ʼ����Ϊ���������s 
	{
		int end=MIN(G,close);//��ȡ��ǰclose������Ȩֵ��С�ıߵ��յ㣬������Ϊ��С��������һ���� 
		int start=close[end].start;
		int val=close[end].val;
		printf("%d->%d,%d\n",start,end,val);
		close[end].visit=true;//������Ϊ����һ���� 
		for(int k=0;k<G->Vexnum;k++)//����close���� 
		{
			if((G->Edge[end][k])<close[k].val)//���ղŻ�ȡ�ıߵ��յ㵽k��ȨֵС��close[k]��start��k��Ȩֵ�������
			{
				close[k].start=end;
				close[k].val=G->Edge[end][k];	
			} 
		}
	} 
}


void floyd(MGraph *G){//�ڽӾ���ĸ��������㷨
	int i,j;
	EdgeType D[NUM][NUM];//���·�� 
	EdgeType P[NUM][NUM];//�ڽӵ� 
	for(i=0;i<G->Vexnum;i++)//��ʼ�������������� 
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
	for(mid=0;mid<G->Vexnum;mid++)//�м�� 
	{
		for(start=0;start<G->Vexnum;start++)//��� 
		{
			for(end=0;end<G->Vexnum;start++)//�յ� 
			{
				if(D[start][end]>(D[start][mid]+D[mid][end]))//��start��end����start��mid��end������D���� 
				{
					D[start][end]=D[start][mid]+D[mid][end];
					P[start][end]=P[start][mid];//����start���ڽӵ� 
				}
			}
		}
	}
	int v,w;
	int k;
	scanf("%d%d",&v,&w);//�����ѯ������յ�
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
