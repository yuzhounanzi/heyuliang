#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100	//线性表的最大长度 
typedef struct{
	int *elem;//存储空间基址 
	int length;//线性表长度 
}Sqlist; //线性表的结构类型

//线性表的初始化
int InitList(Sqlist *L)
{
	L->elem=(int*)malloc(MAXSIZE*sizeof(int));//分配一个大小为MAXSIZE的空线性表 
	if(!L->elem)
	{
		exit(0);//分配失败，结束程序 
	}
	printf("分配成功\n");
	L->length=0;//空线性表长度为零	
	return 1;
 } 

//线性表的输入
int InputList(Sqlist *L)
{
	int i=0;
	printf("请输入线性表的元素（以-1作为结束）：\n");
	scanf("%d",&L->elem[i]);//输入线性表第一个元素
	while(L->elem[i]!=-1)
	{
		L->length++;//计算线性表的长度 
		i++;
		scanf("%d",&L->elem[i]);//当前元素不是-1继续输入 
	 } 
	 return 1; 
 } 
 
//线性表的输出
int  OutputList(Sqlist L)
{
	if(L.length==0)
	{
		printf("线性表为空\n");//线性表为空则退出 
		exit(0);
	}
	int i=0;
	for(i=0;i<L.length;i++)
	{
		printf("%d\n",L.elem[i]);//输出线性表的元素 
	 }
	printf("线性表的长度为%d\n",L.length);
	return 1;  
}

//将线性表内容输出到文件
int OfileList(Sqlist L)
{
	FILE *fp=fopen("text.txt","w+");
	if(fp==NULL)
	{
		printf("打开文件失败");
		exit(0);//打开文件失败则退出 
	}
	int i;
	for(i=0;i<L.length;i++)
	{
		fprintf(fp,"%d\n",L.elem[i]);//将元素输出到文件 
	}
	fclose(fp);
	printf("成功输出到文件\n");
	return 1;
 } 
 
//从文件中读入线性表
int IflieList(Sqlist *L) 
{
	FILE *fp=fopen("text.txt","r+");
	if(fp==NULL)
	{
		printf("打开文件失败");
		exit(0);//打开文件失败则退出 
	}
	int i;
	for(i=0;i<L->length;i++)
	{
		fscanf(fp,"%d\n",L->elem[i]);//将元素读入到文件  
	}
	fclose(fp);
	printf("成功读入文件\n");
	return 1;	
}

//线性表取值
int GetElem(Sqlist L,int i,int *e)
{
	if(i<1||i>L.length)
	{
		printf("i的值不合理"); 
		exit(0);//i的值不合理，退出 
	}
	*e=L.elem[i-1];//取出第i个值
	printf("第%d个值为%d\n",i,*e);
	return 1; 
 } 
 
//线性表的查找
int LocateElem(Sqlist L,int e)
{
	int i;
	for(i=0;i<L.length;i++)//查找线性表中数据为e的元素，输出序号 
	{
		if(L.elem[i]==e)
		{
			printf("查找成功，序号为%d\n",i+1);
			return 1;
		}
	}
	printf("查找失败");
 } 
 
//线性表的插入
int ListInsert(Sqlist *L,int i,int e)//在线性表第i的位置插入e 
{
	if(i<1||i>L->length)
	{
		printf("i的值不合理"); 
		exit(0);//i的值不合理，退出 
	}
	if(L->length==MAXSIZE)
	{
		printf("线性表已满");
		exit(0);//线性表已满，退出 
	}
	int j;
	for(j=L->length-1;j>=i-1;j--)
	{
		L->elem[j+1]=L->elem[j];//将新元素后面的元素后移一位 
	}
	L->elem[i-1]=e;//插入新元素
	L->length++;//表长增加1
	printf("插入成功\n");
	return 1; 
 } 
 
//线性表的删除
int ListDelete(Sqlist *L,int i)//删除第i个元素 
{
	if(i<1||i>L->length)
	{
		printf("i的值不合理"); 
		exit(0);//i的值不合理，退出 
	}
	int j;
	for(j=i-1;j<=L->length-2;j++)
	{
		L->elem[j]=L->elem[j+1];//将删除的元素后的元素前移一位 
	}
	L->length--;//长度减一
	printf("删除成功"); 
	return 1; 
 } 

//

 
int main()
{
	int i,e;
	Sqlist L;
	InitList(&L);//初始化线性表 
	InputList(&L);///输入线性表 
	OutputList(L);//输出线性表 
	OfileList(L);//将线性表输出到文件
	printf("请输入要取出的值的序号:");
	scanf("%d",&i);
	GetElem(L,i,&e);
	printf("请输入要查找的值\n:");
	scanf("%d",&e);
	LocateElem(L,e);
	printf("请输入要差入的值和序号:");
	scanf("%d%d",&e,&i);
	ListInsert(&L,i,e);
	printf("请输入要删除的值的序号:");
	scanf("%d%d",&i);
	ListDelete(&L,i);
	OutputList(L);
	return 0; 
}
