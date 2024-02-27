#include<stdio.h>
#include<stdlib.h>
#define error -1;
#define maxblock 10//块的最大数量 
#define blocknum 5//每一块的元素数量 
#define MAXSIZE 10//哈希表的长度 

typedef struct{
	int val;//块中的最大元素 
	int add;//块的起始地址 
}block[];//分块 
typedef struct{
	int* elem;
	int length;
}List;

int searchlist(List *l,int key)//静态表二分查找 
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


int search(List *l,int key)//分块查找 
{
	int add;
	for(int i=0;i<maxblock;i++)//在块中查找 
	{
		if(key<block[i].val)
		{
			add=block[i].add;
		}
	}
	for(add;add<blocknum;add++)//在表中查找 
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


void insert(Tree *t,int key)//二叉排序树的插入
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

Tree* search(Tree *t,int key)//二叉排序树的查找
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

bool deleteTree(Tree *t,int key){//二叉排序树的删除 
	Tree* pre=NULL;//指向删除结点的父亲结点
	Tree* cur=t;
	while(cur!=NULL)//找到要删除的结点 
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
	if(cur->lchild==NULL&&cur->rchild==NULL)//要删除的结点是叶子结点 
	{
		if(pre->lchild==cur)//删除的是父结点的左孩子
		{
			free(cur);
			pre->lchild=NULL;	
		} 
		else//删除的是父结点的右孩子
		{
			free(cur);
			pre->rchild=NULL;
		}
	}
	if(cur->lchild!=NULL&&cur->rchild==NULL)//要删除的结点只有左孩子 
	{
		if(pre->lchild==cur)//删除的是父结点的左孩子
		{
			pre->lchild=cur->lchild;//父结点的左孩子连接删除结点的左孩子 
			free(cur);
		} 
		else//删除的是父结点的右孩子
		{
			pre->rchild=cur->lchild;//父结点的右孩子连接删除结点的左孩子 
			free(cur);
		}
	}
	if(cur->rchild!=NULL&&cur->lchild==NULL)//要删除的结点只有右孩子，和上述同理 
	{
		if(pre->lchild==cur)//删除的是父结点的左孩子
		{
			pre->lchild=cur->rchild;//父结点的左孩子连接删除结点的右孩子 
			free(cur);
		} 
		else//删除的是父结点的右孩子
		{
			pre->rchild=cur->rchild;//父结点的右孩子连接删除结点的右孩子 
			free(cur);
		}
	}
	if(cur->lchild!=NULL&&cur->rchild!=NULL)//删除的结点左右孩子都有
	//有两种方法，用删除结点的左子树中最大的（也就是最右边的结点）替换，或者用删除结点右子树中最小的（也就是最左边的结点）替换，这里用第一种 
	{
		Tree* temp=cur;//temp指向最大结点的前一个结点 
		Tree* leftmax=cur->lchild;
		while(leftmax->rchild!=NULL)//寻找左子树中最大的结点
		{
			temp=leftmax;
			leftmax=leftmax->rchild;	
		} 
		cur->val=leftmax->val;//将删除的结点的值替换为左子树中最大的结点，本质上变成了删除左子树中最大的结点
		if(temp!=cur)
		{
			free(leftmax);
			temp->rchild=NULL; 
		}
		else//有可能左子树中最大的就在删除结点的下一层 
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

typedef struct hash_list{//拉链法解决哈希表的冲突 
	List* elem;
}hash_list;

void inithash(hash_list *l){//哈希表的初始化 
	l->elem=(Node*)malloc(sizeof(Node)*MAXSIZE);
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		l->elem[i].next=NULL;
	}
}

int hash(int key){//哈希函数 
	return key%11;
}

void inserthash(hash_list *l,int key){//哈希表的插入 
	int add=hash(key);
	if(l->elem[add].next==NULL)//没有起冲突 
	{
		Node* temp=(Node*)malloc(sizeof(Node));
		temp->val=key;
		temp->next=NULL;
		l->elem[add].next=temp;
	}
	else//起冲突,用头插法 
	{
		Node* temp=(Node*)malloc(sizeof(Node));
		temp->val=key;
		temp->next=l->elem[add].next;
		l->elem[add].next=temp;
	}
}


Node* search(hash_list *l,int key){//哈希表的查找
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


