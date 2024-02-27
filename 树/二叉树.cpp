#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define elem char 
typedef struct Node{//树结点 
	elem data;//数据域
	struct Node* lchild;//左子树
	struct Node* rchild;//右子树 
}TreeNode;

void InitTree(TreeNode **t){//创建二叉树的结点 
	(*t)=(TreeNode*)malloc(sizeof(TreeNode));
	(*t)->lchild=NULL;
	(*t)->rchild=NULL;
}


typedef struct{//栈 
	TreeNode* sta[MAX];//栈里存放的是树的结点 
	int top;
}Stack;


void InitStack(Stack **s)//栈的初始化 
{
	(*s)=(Stack*)malloc(sizeof(Stack));
	(*s)->top=-1;
}

void desStack(Stack **s)//栈的销毁
{
	free(*s);
 } 

void CreatTree(TreeNode **tr){//非递归创建二叉树
	printf("输入字符串（括号法创建二叉树）：");
	elem s[MAX];
	gets(s);
	TreeNode *t;//二叉树结点 
	int i=0;
	int temp;//临时变量，为0操作左子树，为1操作右子树 
	Stack *st;//栈 
	InitStack(&st);
	while(s[i]!='\0')
	{
		switch(s[i])
		{
			case'('://操作左子树 
				st->top++;
				st->sta[st->top]=t;//前一个结点入栈 
				temp=0;
				break;
			case','://操作右子树
				temp=1;
				break; 
			case')'://子树创建结束，根节点出栈
				st->top--;
				break; 
			default:
				InitTree(&t);
				t->data=s[i];
				if(i==0)
				{
					(*tr)=t;//根结点 
				}
				else
				{
					switch(temp)
					{
						case 0:
							st->sta[st->top]->lchild=t;//左孩子 
							break;
						case 1:
							st->sta[st->top]->rchild=t;//右孩子
							break;	
					}
				}
		}
		i++;
	}
	desStack(&st);
	printf("二叉树创建成功\n");
}


void creat_Tree(TreeNode **t){//递归法创建二叉树
	elem e;
	scanf("%c",&e);
	if(e=='#')//递归结束，代表没有子树 
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



void outputTree(TreeNode *tr){//输出二叉树的括号法表示
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



int heightTree(TreeNode *tr){//计算二叉树的高度
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

void preTree(TreeNode *tr){//二叉树的先序遍历
	if(tr==NULL)
	{
		return; 
	 }
	printf("%c",tr->data);
	preTree(tr->lchild);
	preTree(tr->rchild);	  
	
}


void midTree(TreeNode *tr){//二叉树的中序遍历
	 if(tr==NULL)
	{
		return; 
	 }
	preTree(tr->lchild);
	printf("%c",tr->data);
	preTree(tr->rchild);
	
}

void behTree(TreeNode *tr){//二叉树的后序遍历
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
