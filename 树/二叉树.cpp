#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define elem char 
typedef struct Node{//����� 
	elem data;//������
	struct Node* lchild;//������
	struct Node* rchild;//������ 
}TreeNode;

void InitTree(TreeNode **t){//�����������Ľ�� 
	(*t)=(TreeNode*)malloc(sizeof(TreeNode));
	(*t)->lchild=NULL;
	(*t)->rchild=NULL;
}


typedef struct{//ջ 
	TreeNode* sta[MAX];//ջ���ŵ������Ľ�� 
	int top;
}Stack;


void InitStack(Stack **s)//ջ�ĳ�ʼ�� 
{
	(*s)=(Stack*)malloc(sizeof(Stack));
	(*s)->top=-1;
}

void desStack(Stack **s)//ջ������
{
	free(*s);
 } 

void CreatTree(TreeNode **tr){//�ǵݹ鴴��������
	printf("�����ַ��������ŷ���������������");
	elem s[MAX];
	gets(s);
	TreeNode *t;//��������� 
	int i=0;
	int temp;//��ʱ������Ϊ0������������Ϊ1���������� 
	Stack *st;//ջ 
	InitStack(&st);
	while(s[i]!='\0')
	{
		switch(s[i])
		{
			case'('://���������� 
				st->top++;
				st->sta[st->top]=t;//ǰһ�������ջ 
				temp=0;
				break;
			case','://����������
				temp=1;
				break; 
			case')'://�����������������ڵ��ջ
				st->top--;
				break; 
			default:
				InitTree(&t);
				t->data=s[i];
				if(i==0)
				{
					(*tr)=t;//����� 
				}
				else
				{
					switch(temp)
					{
						case 0:
							st->sta[st->top]->lchild=t;//���� 
							break;
						case 1:
							st->sta[st->top]->rchild=t;//�Һ���
							break;	
					}
				}
		}
		i++;
	}
	desStack(&st);
	printf("�����������ɹ�\n");
}


void creat_Tree(TreeNode **t){//�ݹ鷨����������
	elem e;
	scanf("%c",&e);
	if(e=='#')//�ݹ����������û������ 
	{
		return;
	}
	(*t)=(TreeNode*)malloc(sizeof(TreeNode));
	(*t)->data=e;	
	(*t)->lchild=NULL;
	(*t)->rchild=NULL;
	creat_Tree(&((*t)->lchild));
	creat_Tree(&((*t)->rchild));
}



void outputTree(TreeNode *tr){//��������������ŷ���ʾ
	if(tr==NULL)
	{
		return;
	 } 
	printf("%c",tr->data);
	if(tr->lchild==NULL&&tr->lchild==NULL)
	{
		return;
	}
	else
	{
		printf("(");
	}
	outputTree(tr->lchild);
	printf(",");
	outputTree(tr->rchild);
	printf(")");
}



int heightTree(TreeNode *tr){//����������ĸ߶�
	if(tr==NULL)
	{
		return 0;
	}
	else
	{
		int height1=heightTree(tr->lchild);
		int height2=heightTree(tr->rchild);
		return (height1>height2)? (height1+1):(height2+1); 
	}
}

void preTree(TreeNode *tr){//���������������
	if(tr==NULL)
	{
		return; 
	 }
	printf("%c",tr->data);
	preTree(tr->lchild);
	preTree(tr->rchild);	  
	
}


void midTree(TreeNode *tr){//���������������
	 if(tr==NULL)
	{
		return; 
	 }
	preTree(tr->lchild);
	printf("%c",tr->data);
	preTree(tr->rchild);
	
}

void behTree(TreeNode *tr){//�������ĺ������
 	if(tr==NULL)
	{
		return; 
	 }
	preTree(tr->lchild);
	preTree(tr->rchild);
	printf("%c",tr->data);
	
}


int main()
{
	TreeNode *tr;
	//CreatTree(&tr);
	creat_Tree(&tr);
	outputTree(tr);
	printf("\nheight:%d\n",heightTree(tr));
	preTree(tr);
	printf("\n");
	midTree(tr);
	printf("\n");
	behTree(tr);
	return 0;
}
