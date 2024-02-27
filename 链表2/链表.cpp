#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Node{
	int id;
	char name[10];
	char group[10];
	int score;
	_Node* next;//ָ����һ������ָ�� 
	_Node* prior;//ָ��ǰһ����� 
}Node;//������ 

typedef struct{
	Node* pHead;//ָ��ͷ����ָ�� 
	int length;//������ 
}Linklist;


void creatLinklist(Linklist *L)//�����ʼ�� 
{
	Node* NewNode=(Node*)malloc(sizeof(Node));//�½���� 
	L->pHead=NewNode;//�½����Ϊͷ��� 
	L->length=0;//������Ϊ�� 
	printf("��ʼ���ɹ�\n"); 
}

/*
void readfileLinklist(Linklist *L)//���ļ��ж������� 
{
	FILE* fp=fopen("linear.txt","r");//���ļ�
	if(fp==NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(1); 
	 }
	Node* currentNode=L->pHead;//��ǰ���ָ��ͷ���  
	Node No;
	while(fread(&No,sizeof(Node),1,fp))//���ļ��ж�ȡ���� 
	{
		L->newNode=(Node*)malloc(sizeof(Node));//�����½��
		memcpy(&L->newNode,&No,sizeof(Node));//���ļ��е����ݸ��½�� 
		L->newNode->next=NULL;//�½��ָ��� 
		currentNode->next=L->newNode;//����ǰһ�����
		currentNode=L->newNode;//��ǰ���ָ���½ڵ�
		L->length++; 
	 }
	 printf("��ȡ�ļ��ɹ�\n"); 
	
} 
*/

void searchLinklist(Linklist L,int r)//���������е�r������
{
	Node* temporaryNode=L.pHead;//�õ�ǰ���ָ��ͷ���
	if(temporaryNode->next==NULL)
	{
		printf("����Ϊ��\n");//����Ϊ�����˳� 
		exit(1);
	}
	int i;
	for(i=0;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//ͨ��ѭ������ʱ�ڵ�ָ��Ŀ���� 
	 }
	 printf("���ҳɹ�\n"); 
	 printf("id is %d\n",temporaryNode->id);
	 printf("name is %s\n",temporaryNode->name);
	 printf("grope is %s\n",temporaryNode->group);
	 printf("score is %d\n",temporaryNode->score); 
 } 

void insertLinklist(Linklist *L,int r)//���������
{
	Node* temporaryNode=L->pHead;//�õ�ǰ���ָ��ͷ���
	int i=1;
	for(i=1;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//ͨ��ѭ���õ�ǰ�ڵ�ָ��Ŀ����ǰһ����� 	
	}
	Node* NewNode=(Node*)malloc(sizeof(Node));//�½����
	NewNode->next=temporaryNode->next;//�½�������һ�����ָ��ǰ������һ�����Ϊ
	temporaryNode->next=NewNode;//��ǰ������һ�����ָ���½����
	printf("����ɹ�\n");	
} 


void deleteLinklist(Linklist *L,int r)//ɾ����r�����
{
	Node* temporaryNode=L->pHead;//��ǰ���ָ��ͷ���
	Node* tempNode;//��ʱ��� 
	int i=1;
	for(i=1;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//ͨ��ѭ���õ�ǰ�ڵ�ָ��Ŀ����ǰһ����� 	
	}
	tempNode=temporaryNode->next;//��ʱ���ָ��ǰ������һ����� 
	temporaryNode->next=temporaryNode->next->next;//��ǰ���ָ����һ��������һ�����
	free(tempNode);//ɾ����ʱ���
	printf("ɾ���ɹ�\n"); 
 }
 
void delete_Linklist(Linklist *L,int s)//ɾ��scoreС��s�Ľ��
{
	Node* temporaryNode=L->pHead;//��ǰ���ָ��ͷ���
	Node* tempNode;//��ʱ���
	while(temporaryNode->next!=NULL)//��һ����㲻Ϊ��
	{
		if(temporaryNode->next->score<s)//�����һ������е�scoreС��s����ɾ����� 
		{
			tempNode=temporaryNode->next;
			temporaryNode->next=temporaryNode->next->next;
			free(tempNode);
		}
		else
		{
			temporaryNode=temporaryNode->next;//��ǰ���ָ����һ�����
		} 			
	}		
}  


void outputLinklist(Linklist L)//��������� 
{
	Node* temporaryNode=L.pHead;//��ǰ���ָ��ͷ���
	while(temporaryNode->next!=NULL)//��һ����㲻Ϊ�� 
	{
		temporaryNode=temporaryNode->next;//��ǰ���ָ����һ����� 
		printf("id is %d\n",temporaryNode->id);
	 	printf("name is %s\n",temporaryNode->name);
	 	printf("grope is %s\n",temporaryNode->group);
	 	printf("score is %d\n",temporaryNode->score); 
	}
	exit(0);
}


void del_Linklist(Linklist *L,int r)//˫�������ɾ�� 
{
	Node* temporaryNode=L->pHead;//��ǰ���ָ��ͷ���
	int i;
	for(i=0;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//ͨ��ѭ��ָ��Ŀ���� 
	}
	temporaryNode->prior->next=temporaryNode->next;//Ŀ�����ǰ���ĺ��ΪĿ����ĺ�� 
	temporaryNode->next->prior=temporaryNode->prior;//Ŀ����ĺ�̵�ǰ��ΪĿ�����ǰ�� 
	free(temporaryNode);//�ͷ�Ŀ����
	printf("ɾ���ɹ�\n"); 
}

void insert_Linklist(Linklist *L,int r)//˫������Ĳ���
{
	Node* temporaryNode=L->pHead;//��ǰ���ָ��ͷ���
	int i;
	for(i=1;i<r;i++)
	{
		temporaryNode=temporaryNode->next;//ͨ��ѭ��ָ��Ŀ��λ�õ�ǰһ����� 
	} 
	Node* NewNode=(Node*)malloc(sizeof(Node));//�½����
	NewNode->next=temporaryNode->next;//�½��ĺ��Ϊ��ǰ���ĺ��
	temporaryNode->next->prior=NewNode;//��ǰ���ĺ�̵�ǰ��Ϊ�½��
	temporaryNode->next=NewNode;//��ǰ���ĺ��Ϊ�½��
	NewNode->prior=temporaryNode;//�½���ǰ��Ϊ��ǰ���
	printf("����ɹ�"); 
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
