#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100	//���Ա����󳤶� 
typedef struct{
	int *elem;//�洢�ռ��ַ 
	int length;//���Ա��� 
}Sqlist; //���Ա�Ľṹ����

//���Ա�ĳ�ʼ��
int InitList(Sqlist *L)
{
	L->elem=(int*)malloc(MAXSIZE*sizeof(int));//����һ����СΪMAXSIZE�Ŀ����Ա� 
	if(!L->elem)
	{
		exit(0);//����ʧ�ܣ��������� 
	}
	printf("����ɹ�\n");
	L->length=0;//�����Ա���Ϊ��	
	return 1;
 } 

//���Ա������
int InputList(Sqlist *L)
{
	int i=0;
	printf("���������Ա��Ԫ�أ���-1��Ϊ��������\n");
	scanf("%d",&L->elem[i]);//�������Ա��һ��Ԫ��
	while(L->elem[i]!=-1)
	{
		L->length++;//�������Ա�ĳ��� 
		i++;
		scanf("%d",&L->elem[i]);//��ǰԪ�ز���-1�������� 
	 } 
	 return 1; 
 } 
 
//���Ա�����
int  OutputList(Sqlist L)
{
	if(L.length==0)
	{
		printf("���Ա�Ϊ��\n");//���Ա�Ϊ�����˳� 
		exit(0);
	}
	int i=0;
	for(i=0;i<L.length;i++)
	{
		printf("%d\n",L.elem[i]);//������Ա��Ԫ�� 
	 }
	printf("���Ա�ĳ���Ϊ%d\n",L.length);
	return 1;  
}

//�����Ա�����������ļ�
int OfileList(Sqlist L)
{
	FILE *fp=fopen("text.txt","w+");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��");
		exit(0);//���ļ�ʧ�����˳� 
	}
	int i;
	for(i=0;i<L.length;i++)
	{
		fprintf(fp,"%d\n",L.elem[i]);//��Ԫ��������ļ� 
	}
	fclose(fp);
	printf("�ɹ�������ļ�\n");
	return 1;
 } 
 
//���ļ��ж������Ա�
int IflieList(Sqlist *L) 
{
	FILE *fp=fopen("text.txt","r+");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��");
		exit(0);//���ļ�ʧ�����˳� 
	}
	int i;
	for(i=0;i<L->length;i++)
	{
		fscanf(fp,"%d\n",L->elem[i]);//��Ԫ�ض��뵽�ļ�  
	}
	fclose(fp);
	printf("�ɹ������ļ�\n");
	return 1;	
}

//���Ա�ȡֵ
int GetElem(Sqlist L,int i,int *e)
{
	if(i<1||i>L.length)
	{
		printf("i��ֵ������"); 
		exit(0);//i��ֵ�������˳� 
	}
	*e=L.elem[i-1];//ȡ����i��ֵ
	printf("��%d��ֵΪ%d\n",i,*e);
	return 1; 
 } 
 
//���Ա�Ĳ���
int LocateElem(Sqlist L,int e)
{
	int i;
	for(i=0;i<L.length;i++)//�������Ա�������Ϊe��Ԫ�أ������� 
	{
		if(L.elem[i]==e)
		{
			printf("���ҳɹ������Ϊ%d\n",i+1);
			return 1;
		}
	}
	printf("����ʧ��");
 } 
 
//���Ա�Ĳ���
int ListInsert(Sqlist *L,int i,int e)//�����Ա��i��λ�ò���e 
{
	if(i<1||i>L->length)
	{
		printf("i��ֵ������"); 
		exit(0);//i��ֵ�������˳� 
	}
	if(L->length==MAXSIZE)
	{
		printf("���Ա�����");
		exit(0);//���Ա��������˳� 
	}
	int j;
	for(j=L->length-1;j>=i-1;j--)
	{
		L->elem[j+1]=L->elem[j];//����Ԫ�غ����Ԫ�غ���һλ 
	}
	L->elem[i-1]=e;//������Ԫ��
	L->length++;//������1
	printf("����ɹ�\n");
	return 1; 
 } 
 
//���Ա��ɾ��
int ListDelete(Sqlist *L,int i)//ɾ����i��Ԫ�� 
{
	if(i<1||i>L->length)
	{
		printf("i��ֵ������"); 
		exit(0);//i��ֵ�������˳� 
	}
	int j;
	for(j=i-1;j<=L->length-2;j++)
	{
		L->elem[j]=L->elem[j+1];//��ɾ����Ԫ�غ��Ԫ��ǰ��һλ 
	}
	L->length--;//���ȼ�һ
	printf("ɾ���ɹ�"); 
	return 1; 
 } 

//

 
int main()
{
	int i,e;
	Sqlist L;
	InitList(&L);//��ʼ�����Ա� 
	InputList(&L);///�������Ա� 
	OutputList(L);//������Ա� 
	OfileList(L);//�����Ա�������ļ�
	printf("������Ҫȡ����ֵ�����:");
	scanf("%d",&i);
	GetElem(L,i,&e);
	printf("������Ҫ���ҵ�ֵ\n:");
	scanf("%d",&e);
	LocateElem(L,e);
	printf("������Ҫ�����ֵ�����:");
	scanf("%d%d",&e,&i);
	ListInsert(&L,i,e);
	printf("������Ҫɾ����ֵ�����:");
	scanf("%d%d",&i);
	ListDelete(&L,i);
	OutputList(L);
	return 0; 
}
