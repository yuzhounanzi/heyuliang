#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
	int *stack;//栈基址 
	int top;//栈顶指针 
}Stack;


void InitStack(Stack *s)//栈的初始化 
{
	s->stack=(int*)malloc(MAX*sizeof(int));//为栈动态开辟内存空间 
	s->top=-1;//栈顶指针设置为-1 
}

void JudgeEmpty(Stack s)//判断栈是否为空
{
	if(s.top==-1)
	{
		printf("栈为空\n");	
	}
	else
	{
		printf("栈不为空\n");
	}	
}


void PushStack(Stack *s,int e)//入栈 
{
	if(s->top==MAX-1)
	{
		printf("栈已满，无法入栈\n");
		exit(0); 
	}
	s->top++;//栈顶指针加1 
	s->stack[s->top]=e;//入栈 
	printf("入栈成功\n");
}

void PopStack(Stack *s)//出栈 
{
	if(s->top==-1)
	{
		printf("栈为空，无法出栈\n");
		exit(0); 
	}
	int tmp=s->stack[s->top];//栈顶元素出栈 
	printf("出栈元素为：%d\n",tmp);
	s->top--;//栈顶元素减1 
}

int TopStack(Stack *s)//获取栈顶元素
{
	if(s->top==-1)
	{
		printf("栈为空\n");
		exit(0); 
	}
	return s->stack[s->top];
} 

int LengthStack(Stack s)//获取栈的长度 
{
	return ++s.top;
 } 
 
 
int main()
{
	Stack s;
	InitStack(&s);
	JudgeEmpty(s);
	PushStack(&s,1);
	printf("栈顶元素为：%d\n",TopStack(&s));
	printf("栈的长度为：%d\n",LengthStack(s));
	
}
