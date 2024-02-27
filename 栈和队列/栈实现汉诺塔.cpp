#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct{
	int plate[MAX_SIZE];//���ӵ�����
	int top;//ջ��ָ�� 
}Stack;

void InitStack(Stack *s){//ջ�ĳ�ʼ�� ,��ջ��ģ������ 
	s->top=-1;//ջ��ָ��-1 
} 

void PushStack(Stack *s,int e){//��ջ 
	if(s->top==MAX_SIZE-1)
	{
		printf("ջ��\n");
		exit(0);
	}
	s->top++;
	s->plate[s->top]=e;
}

void PopStack(Stack *s,int *t){//��ջ 
	if(s->top==-1)
	{
		printf("ջΪ��\n");
		exit(0);
	}
	*t=s->plate[s->top];//��ȡջ��Ԫ��
	s->top--; 
}

void ShowStack(Stack s)//���ջ������ 
{
	if(s.top==-1)
	{
		printf("ջΪ��");
		exit(0);
	}
	int i=s.top;
	while(i!=-1)
	{
		printf("%d����\n",s.plate[i]);
		i--;
	}
}

//��n�����Ӵ�a�����ƶ���c���ӣ�b����Ϊ���� 
int Hanoi(int n,Stack *a,Stack *c,Stack *b){
	int t;
	if(n==1)//��ֻʣ�������������Ҫ�ƶ�ʱ 
	{
		PopStack(a,&t);//��a��ֱ���Ƶ�c�� 
		PushStack(c,t);
		return 0;
	}
	//��һ������n-1�����Ӵ�a���Ƶ�b�� 
	Hanoi(n-1,a,b,c);
	//�ڶ�������a��ʣ�µ�һ�������Ƶ�c��
	PopStack(a,&t);
	PushStack(c,t);
	//������������һ����n-1�����Ӵ�b���Ƶ�c��
	Hanoi(n-1,b,c,a);
	return 0; 
}


int main()
{
	int num,i;
	Stack a,b,c;//a��b��c�������ӣ���ջ��ģ�� 
	InitStack(&a); //��ʼ�� 
	InitStack(&b);
	InitStack(&c);
	printf("���������Ӹ�����\n");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		PushStack(&a,i);//��num��������ջ��������a�� �����Ӵ��µ��ϵ����Ϊ1��num 
	}
	printf("a����\n");
	ShowStack(a);
	Hanoi(num,&a,&c,&b);//�ƶ�����
	printf("c����\n");
	ShowStack(c);
	return 0; 
}










