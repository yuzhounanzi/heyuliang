#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct{
	int plate[MAX_SIZE];//盘子的数量
	int top;//栈顶指针 
}Stack;

void InitStack(Stack *s){//栈的初始化 ,用栈来模拟柱子 
	s->top=-1;//栈顶指向-1 
} 

void PushStack(Stack *s,int e){//入栈 
	if(s->top==MAX_SIZE-1)
	{
		printf("栈满\n");
		exit(0);
	}
	s->top++;
	s->plate[s->top]=e;
}

void PopStack(Stack *s,int *t){//出栈 
	if(s->top==-1)
	{
		printf("栈为空\n");
		exit(0);
	}
	*t=s->plate[s->top];//获取栈顶元素
	s->top--; 
}

void ShowStack(Stack s)//输出栈的内容 
{
	if(s.top==-1)
	{
		printf("栈为空");
		exit(0);
	}
	int i=s.top;
	while(i!=-1)
	{
		printf("%d号盘\n",s.plate[i]);
		i--;
	}
}

//将n个盘子从a柱子移动到c柱子，b柱子为辅助 
int Hanoi(int n,Stack *a,Stack *c,Stack *b){
	int t;
	if(n==1)//当只剩最上面的盘子需要移动时 
	{
		PopStack(a,&t);//从a柱直接移到c柱 
		PushStack(c,t);
		return 0;
	}
	//第一步，将n-1个盘子从a柱移到b柱 
	Hanoi(n-1,a,b,c);
	//第二步，将a柱剩下的一个盘子移到c柱
	PopStack(a,&t);
	PushStack(c,t);
	//第三步，将第一步的n-1个盘子从b柱移到c柱
	Hanoi(n-1,b,c,a);
	return 0; 
}


int main()
{
	int num,i;
	Stack a,b,c;//a，b，c三个柱子，用栈来模拟 
	InitStack(&a); //初始化 
	InitStack(&b);
	InitStack(&c);
	printf("请输入盘子个数：\n");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		PushStack(&a,i);//将num个盘子入栈，即放入a柱 ，盘子从下到上的序号为1到num 
	}
	printf("a柱：\n");
	ShowStack(a);
	Hanoi(num,&a,&c,&b);//移动盘子
	printf("c柱：\n");
	ShowStack(c);
	return 0; 
}










