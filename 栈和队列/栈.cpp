#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
	int *stack;//ջ��ַ 
	int top;//ջ��ָ�� 
}Stack;


void InitStack(Stack *s)//ջ�ĳ�ʼ�� 
{
	s->stack=(int*)malloc(MAX*sizeof(int));//Ϊջ��̬�����ڴ�ռ� 
	s->top=-1;//ջ��ָ������Ϊ-1 
}

void JudgeEmpty(Stack s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s.top==-1)
	{
		printf("ջΪ��\n");	
	}
	else
	{
		printf("ջ��Ϊ��\n");
	}	
}


void PushStack(Stack *s,int e)//��ջ 
{
	if(s->top==MAX-1)
	{
		printf("ջ�������޷���ջ\n");
		exit(0); 
	}
	s->top++;//ջ��ָ���1 
	s->stack[s->top]=e;//��ջ 
	printf("��ջ�ɹ�\n");
}

void PopStack(Stack *s)//��ջ 
{
	if(s->top==-1)
	{
		printf("ջΪ�գ��޷���ջ\n");
		exit(0); 
	}
	int tmp=s->stack[s->top];//ջ��Ԫ�س�ջ 
	printf("��ջԪ��Ϊ��%d\n",tmp);
	s->top--;//ջ��Ԫ�ؼ�1 
}

int TopStack(Stack *s)//��ȡջ��Ԫ��
{
	if(s->top==-1)
	{
		printf("ջΪ��\n");
		exit(0); 
	}
	return s->stack[s->top];
} 

int LengthStack(Stack s)//��ȡջ�ĳ��� 
{
	return ++s.top;
 } 
 
 
int main()
{
	Stack s;
	InitStack(&s);
	JudgeEmpty(s);
	PushStack(&s,1);
	printf("ջ��Ԫ��Ϊ��%d\n",TopStack(&s));
	printf("ջ�ĳ���Ϊ��%d\n",LengthStack(s));
	
}
