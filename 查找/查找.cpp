#include<stdio.h>
#include<stdlib.h>
#define error -1;
#define maxblock 10//���������� 
#define blocknum 5//ÿһ���Ԫ������ 
#define MAXSIZE 10//��ϣ��ĳ��� 

typedef struct{
	int val;//���е����Ԫ�� 
	int add;//�����ʼ��ַ 
}block[];//�ֿ� 
typedef struct{
	int* elem;
	int length;
}List;

int searchlist(List *l,int key)//��̬����ֲ��� 
{
	int low=0;
	int high=l->length-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(l->elem[mid]==key)
		{
			return mid;
		}
		else if(key<l->elem[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return error;
}


int search(List *l,int key)//�ֿ���� 
{
	int add;
	for(int i=0;i<maxblock;i++)//�ڿ��в��� 
	{
		if(key<block[i].val)
		{
			add=block[i].add;
		}
	}
	for(add;add<blocknum;add++)//�ڱ��в��� 
	{
		if(l->elem[add]==key)
		{
			return add;
		}
	}
}




typedef struct Node{
	int val;
	struct Node* lchild;
	struct Node* rchild;
}Tree;


void insert(Tree *t,int key)//�����������Ĳ���
{
	if(t==NULL)
	{
		t=(Node*)malloc(sizeof(Node));
		t->val=key;
		t->lchild=NULL;
		t->rchild=NULL;
	}	
	else if(key<t->val)
	{
		insert(t->lchild,key);
	}
	else
	{
		insert(t->rchild,key);
	}
} 

Tree* search(Tree *t,int key)//�����������Ĳ���
{
	if(t==NULL)
	{
		return NULL;
	}	
	else
	{
		if(t->val==key)
		{
			return t;
		}
		if(key<t->val)
		{
			search(t->lchild,key);
		}
		else
		{
			search(t->rchild,key);
		}
	}
} 

bool deleteTree(Tree *t,int key){//������������ɾ�� 
	Tree* pre=NULL;//ָ��ɾ�����ĸ��׽��
	Tree* cur=t;
	while(cur!=NULL)//�ҵ�Ҫɾ���Ľ�� 
	{
		if(key==cur->val)
		{
			break;
		}
		pre=cur;
		if(key<cur->val)
		{
			cur=cur->lchild;
		}
		else
		{
			cur=cur->rchild;
		}
	} 
	if(cur==NULL)
	{
		return false;
	}
	if(cur->lchild==NULL&&cur->rchild==NULL)//Ҫɾ���Ľ����Ҷ�ӽ�� 
	{
		if(pre->lchild==cur)//ɾ�����Ǹ���������
		{
			free(cur);
			pre->lchild=NULL;	
		} 
		else//ɾ�����Ǹ������Һ���
		{
			free(cur);
			pre->rchild=NULL;
		}
	}
	if(cur->lchild!=NULL&&cur->rchild==NULL)//Ҫɾ���Ľ��ֻ������ 
	{
		if(pre->lchild==cur)//ɾ�����Ǹ���������
		{
			pre->lchild=cur->lchild;//��������������ɾ���������� 
			free(cur);
		} 
		else//ɾ�����Ǹ������Һ���
		{
			pre->rchild=cur->lchild;//�������Һ�������ɾ���������� 
			free(cur);
		}
	}
	if(cur->rchild!=NULL&&cur->lchild==NULL)//Ҫɾ���Ľ��ֻ���Һ��ӣ�������ͬ�� 
	{
		if(pre->lchild==cur)//ɾ�����Ǹ���������
		{
			pre->lchild=cur->rchild;//��������������ɾ�������Һ��� 
			free(cur);
		} 
		else//ɾ�����Ǹ������Һ���
		{
			pre->rchild=cur->rchild;//�������Һ�������ɾ�������Һ��� 
			free(cur);
		}
	}
	if(cur->lchild!=NULL&&cur->rchild!=NULL)//ɾ���Ľ�����Һ��Ӷ���
	//�����ַ�������ɾ�����������������ģ�Ҳ�������ұߵĽ�㣩�滻��������ɾ���������������С�ģ�Ҳ��������ߵĽ�㣩�滻�������õ�һ�� 
	{
		Tree* temp=cur;//tempָ��������ǰһ����� 
		Tree* leftmax=cur->lchild;
		while(leftmax->rchild!=NULL)//Ѱ�������������Ľ��
		{
			temp=leftmax;
			leftmax=leftmax->rchild;	
		} 
		cur->val=leftmax->val;//��ɾ���Ľ���ֵ�滻Ϊ�����������Ľ�㣬�����ϱ����ɾ�������������Ľ��
		if(temp!=cur)
		{
			free(leftmax);
			temp->rchild=NULL; 
		}
		else//�п��������������ľ���ɾ��������һ�� 
		{
			temp->lchild=leftmax->lchild;
			free(leftmax);
		}
	}
} 


typedef struct Node{
	int val;
	struct Node* next;
}Node,List;

typedef struct hash_list{//�����������ϣ��ĳ�ͻ 
	List* elem;
}hash_list;

void inithash(hash_list *l){//��ϣ��ĳ�ʼ�� 
	l->elem=(Node*)malloc(sizeof(Node)*MAXSIZE);
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		l->elem[i].next=NULL;
	}
}

int hash(int key){//��ϣ���� 
	return key%11;
}

void inserthash(hash_list *l,int key){//��ϣ��Ĳ��� 
	int add=hash(key);
	if(l->elem[add].next==NULL)//û�����ͻ 
	{
		Node* temp=(Node*)malloc(sizeof(Node));
		temp->val=key;
		temp->next=NULL;
		l->elem[add].next=temp;
	}
	else//���ͻ,��ͷ�巨 
	{
		Node* temp=(Node*)malloc(sizeof(Node));
		temp->val=key;
		temp->next=l->elem[add].next;
		l->elem[add].next=temp;
	}
}


Node* search(hash_list *l,int key){//��ϣ��Ĳ���
	int add=hash(key);
	Node* temp=l->elem[add].next;
	while(temp!=NULL)
	{
		if(temp->val==key)
		{
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}



int main()
{
	
//	Tree* root;
//	insert(root,0);
//	search(root,0);
//	deleteTree(root,0);
	return 0;
}


