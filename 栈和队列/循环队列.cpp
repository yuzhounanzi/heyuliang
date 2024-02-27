#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
typedef struct{
	int *data;//���л�ַ 
	int front;//ָ���ͷ 
	int rear;//ָ���β 
}Queue; 

void InitQueue(Queue *q){//���г�ʼ�� 
	q->data=(int*)malloc(MAX_SIZE*sizeof(int));
	if(!q->data)
	{
		printf("��ʼ��ʧ��\n");
		exit(0);
	}
	q->front=0;//�ö�ͷ�Ͷ�β��ָ��0,ѭ�������л�ճ�һ��λ�� 
	q->rear=0;
	printf("��ʼ���ɹ�\n"); 
}


void enqueue(Queue *q,int e){//��� 
	if((q->rear+1)%MAX_SIZE==q->front)
	{
		printf("����\n");
		exit(0);
	}
	q->rear=(q->rear+1)%MAX_SIZE;//��βָ����ƣ�����������ص�ͷ��
	q->data[q->rear]=e;//��� 
	printf("��ӳɹ�\n"); 
}

void dequeue(Queue *q){//����
	if(q->front==q->rear)
	{
		printf("�ӿ�\n");
		exit(0);
	 } 
	int t;
	t=q->data[q->front];//��ȡ��ͷԪ��
	printf("����Ԫ��Ϊ��%d\n",t);
	q->front=(q->front+1)%MAX_SIZE;//��ͷָ����ƣ�����������ص�ͷ�� 
	printf("���ӳɹ�\n");
}

int lengQueue(Queue q){//��ȡ���г��� 
	return (q.rear-q.front+MAX_SIZE)%MAX_SIZE;//��β����ͷ 
}


int main()
{
	Queue q;
	InitQueue(&q);
	enqueue(&q,4);
	printf("ѭ�����г���Ϊ��%d\n",lengQueue(q));
	dequeue(&q);
}
