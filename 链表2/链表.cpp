#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Node{
	int id;
	char name[10];
	char group[10];
	int score;
	_Node* next;//指向下一个结点的指针 
	_Node* prior;//指向前一个结点 
}Node;//链表结点 

typedef struct{
	Node* pHead;//指向头结点的指针 
	int length;//链表长度 
}Linklist;


void creatLinklist(Linklist *L)//链表初始化 
{
	Node* NewNode=(Node*)malloc(sizeof(Node));//新建结点 
	L->pHead=NewNode;//新结点作为头结点 
	L->length=0;//链表长度为零 
	printf("初始化成功\n"); 
}

/*
void readfileLinklist(Linklist *L)//从文件中读入数据 
{
	FILE* fp=fopen("linear.txt","r");//打开文件
	if(fp==NULL)
	{
		printf("打开文件失败\n");
		exit(1); 
	 }
	Node* currentNode=L->pHead;//当前结点指向头结点  
	Node No;
	while(fread(&No,sizeof(Node),1,fp))//从文件中读取内容 
	{
		L->newNode=(Node*)malloc(sizeof(Node));//创建新结点
		memcpy(&L->newNode,&No,sizeof(Node));//将文件中的内容给新结点 
		L->newNode->next=NULL;//新结点指向空 
		currentNode->next=L->newNode;//链接前一个结点
		currentNode=L->newNode;//当前结点指向新节点
		L->length++; 
	 }
	 printf("读取文件成功\n"); 
	
} 
*/

void searchLinklist(Linklist L,int r)//查找链表中第r个内容
{
	Node* temporaryNode=L.pHead;//让当前结点指向头结点
	if(temporaryNode->next==NULL)
	{
		printf("链表为空\n");//链表为空则退出 
		exit(1);
	}
	int i;
	for(i=0;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//通过循环让临时节点指向目标结点 
	 }
	 printf("查找成功\n"); 
	 printf("id is %d\n",temporaryNode->id);
	 printf("name is %s\n",temporaryNode->name);
	 printf("grope is %s\n",temporaryNode->group);
	 printf("score is %d\n",temporaryNode->score); 
 } 

void insertLinklist(Linklist *L,int r)//链表结点插入
{
	Node* temporaryNode=L->pHead;//让当前结点指向头结点
	int i=1;
	for(i=1;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//通过循环让当前节点指向目标结点前一个结点 	
	}
	Node* NewNode=(Node*)malloc(sizeof(Node));//新建结点
	NewNode->next=temporaryNode->next;//新建结点的下一个结点指向当前结点的下一个结点为
	temporaryNode->next=NewNode;//当前结点的下一个结点指向新建结点
	printf("插入成功\n");	
} 


void deleteLinklist(Linklist *L,int r)//删除第r个结点
{
	Node* temporaryNode=L->pHead;//当前结点指向头结点
	Node* tempNode;//临时结点 
	int i=1;
	for(i=1;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//通过循环让当前节点指向目标结点前一个结点 	
	}
	tempNode=temporaryNode->next;//临时结点指向当前结点的下一个结点 
	temporaryNode->next=temporaryNode->next->next;//当前结点指向下一个结点的下一个结点
	free(tempNode);//删除临时结点
	printf("删除成功\n"); 
 }
 
void delete_Linklist(Linklist *L,int s)//删除score小于s的结点
{
	Node* temporaryNode=L->pHead;//当前结点指向头结点
	Node* tempNode;//临时结点
	while(temporaryNode->next!=NULL)//下一个结点不为空
	{
		if(temporaryNode->next->score<s)//如果下一个结点中的score小于s，则删除结点 
		{
			tempNode=temporaryNode->next;
			temporaryNode->next=temporaryNode->next->next;
			free(tempNode);
		}
		else
		{
			temporaryNode=temporaryNode->next;//当前结点指向下一个结点
		} 			
	}		
}  


void outputLinklist(Linklist L)//输出链表结点 
{
	Node* temporaryNode=L.pHead;//当前结点指向头结点
	while(temporaryNode->next!=NULL)//下一个结点不为空 
	{
		temporaryNode=temporaryNode->next;//当前结点指向下一个结点 
		printf("id is %d\n",temporaryNode->id);
	 	printf("name is %s\n",temporaryNode->name);
	 	printf("grope is %s\n",temporaryNode->group);
	 	printf("score is %d\n",temporaryNode->score); 
	}
	exit(0);
}


void del_Linklist(Linklist *L,int r)//双向链表的删除 
{
	Node* temporaryNode=L->pHead;//当前结点指向头结点
	int i;
	for(i=0;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//通过循环指向目标结点 
	}
	temporaryNode->prior->next=temporaryNode->next;//目标结点的前驱的后继为目标结点的后继 
	temporaryNode->next->prior=temporaryNode->prior;//目标结点的后继的前驱为目标结点的前驱 
	free(temporaryNode);//释放目标结点
	printf("删除成功\n"); 
}

void insert_Linklist(Linklist *L,int r)//双向链表的插入
{
	Node* temporaryNode=L->pHead;//当前结点指向头结点
	int i;
	for(i=1;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//通过循环指向目标位置的前一个结点 
	} 
	Node* NewNode=(Node*)malloc(sizeof(Node));//新建结点
	NewNode->next=temporaryNode->next;//新结点的后继为当前结点的后继
	temporaryNode->next->prior=NewNode;//当前结点的后继的前驱为新结点
	temporaryNode->next=NewNode;//当前结点的后继为新结点
	NewNode->prior=temporaryNode;//新结点的前驱为当前结点
	printf("插入成功"); 
}
 
 

int main()
{
	Linklist L;
	creatLinklist(&L);
	//searchLinklist(L,4);
	insertLinklist(&L,1);
	deleteLinklist(&L,1);
	outputLinklist(L);
	delete_Linklist(&L,100); 
	del_Linklist(&L,4);
	insert_Linklist(&L,4);
}
