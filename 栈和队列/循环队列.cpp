#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
typedef struct{
	int *data;//队列基址 
	int front;//指向队头 
	int rear;//指向对尾 
}Queue; 

void InitQueue(Queue *q){//队列初始化 
	q->data=(int*)malloc(MAX_SIZE*sizeof(int));
	if(!q->data)
	{
		printf("初始化失败\n");
		exit(0);
	}
	q->front=0;//让队头和对尾都指向0,循环队列中会空出一个位置 
	q->rear=0;
	printf("初始化成功\n"); 
}


void enqueue(Queue *q,int e){//入队 
	if((q->rear+1)%MAX_SIZE==q->front)
	{
		printf("队满\n");
		exit(0);
	}
	q->rear=(q->rear+1)%MAX_SIZE;//队尾指针后移，如果到最后则回到头部
	q->data[q->rear]=e;//入队 
	printf("入队成功\n"); 
}

void dequeue(Queue *q){//出队
	if(q->front==q->rear)
	{
		printf("队空\n");
		exit(0);
	 } 
	int t;
	t=q->data[q->front];//获取队头元素
	printf("出队元素为：%d\n",t);
	q->front=(q->front+1)%MAX_SIZE;//队头指针后移，如果到最后则回到头部 
	printf("出队成功\n");
}

int lengQueue(Queue q){//获取队列长度 
	return (q.rear-q.front+MAX_SIZE)%MAX_SIZE;//队尾减对头 
}


int main()
{
	Queue q;
	InitQueue(&q);
	enqueue(&q,4);
	printf("循环队列长度为：%d\n",lengQueue(q));
	dequeue(&q);
}
