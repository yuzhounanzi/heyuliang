#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3
#define MAX_SIZE 10 
typedef struct Node{
	char s[MAX];//字符串 
	Node* Next;//指向下一结点 
}LinkString;


LinkString* InitString(LinkString *L,char *s){//块链串的赋值 
	LinkString* pHead=(LinkString*)malloc(sizeof(LinkString));//头结点
	LinkString* cur=pHead;//临时结点指向头结点 
	int num;//创建的结点个数
	num=strlen(s)/MAX;//计算创建的结点个数
	if(strlen(s)%MAX!=0)
	{
		num++;//如果字符串长度除以结点最大存储字符数不为零，再多创建一个结点 
	 } 
	for(int i=0;i<num;i++)
	{
		LinkString* NewNode=(LinkString*)malloc(sizeof(LinkString));//创建新结点 
		for(int j=0;j<MAX;j++)//赋值 
		{
			if(s[i*3+j]=='\0')
			{
				NewNode->s[j]='\0';
				break;
			}
			NewNode->s[j]=s[i*3+j];
		}
		cur->Next=NewNode;
		cur=cur->Next;
	}
	cur->Next=NULL;
	printf("赋值成功\n");
	return pHead;
} 


LinkString* CopyString(LinkString *L,LinkString *S){//复制 
	LinkString* pHead=(LinkString*)malloc(sizeof(LinkString));//头结点
	LinkString* Newcur=pHead;//指向被复制的串 
	LinkString* cur=L->Next;//指向原串 
	while(cur)
	{
		LinkString* NewNode=(LinkString*)malloc(sizeof(LinkString));//创建新结点
		Newcur->Next=NewNode;
		Newcur=Newcur->Next;
		for(int i=0;i<MAX;i++)//复制 
		{
			NewNode->s[i]=cur->s[i];
		}
		cur=cur->Next;
	 }
	 Newcur->Next=NULL;
	 printf("复制成功\n");
	 LinkString* curr=pHead->Next;
	 return pHead; 
}


void DeleString(LinkString *L,int e){//删除 
	LinkString* cur=L;
	int num1=e/MAX+1;//删除位置在哪个结点
	int num2=e%MAX;//删除位置在结点字符串的位置 
	for(int i=0;i<num1;i++)
	{
		cur=cur->Next;//指向目标结点 
	}
	cur->s[num2-1]='*';//将删除的字符换成* 
	printf("删除成功\n");
}


void StrIndex(LinkString* L,char *s){//字符串匹配 
	LinkString* cur=L->Next;
	int i=0,j=0;
	char temp[MAX_SIZE];//创建一个存放串内容的临时串
	while(cur)//将串的数据放进临时数组 
	{
		for(i=0;i<MAX;i++)
		{
			temp[j]=cur->s[i];
			j++;
		}
		cur=cur->Next;
	}
	int len1=strlen(temp);
	int len2=strlen(s);
	i=0;
	j=0;
	while(i<len1&&j<len2)//保证不越界 
	{
		if(temp[i]==s[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;//不相等主串回溯到下个位置 
			j=0;
		}
	 }
	 if(j==len2)
	 {
	 	printf("匹配成功,位置在%d\n",i-j);
	  }
	  else
	  {
	  	printf("匹配失败\n");
	  }
}


void ReplaceString(LinkString *L,char *s,int e){//字符串替换,在e位置替换 
	LinkString* cur=L;
	int num=(e/MAX)+1;//替换位置所在结点
	int leng=strlen(s);//子串长度
	for(int i=0;i<num;i++)
	{
		cur=cur->Next;
	 } 
	 int j=e%MAX-1;
	 int i=0; 
	while(i<leng)
	{
		if(j==MAX)
		{
			cur=cur->Next;
			j=0;
		}
		cur->s[j]=s[i];
		j++;
		i++;
	}
	printf("替换成功\n");
	
}


void OutputString(LinkString *L)//输出 
{
	LinkString* cur=L->Next;
	int i;
	while(cur!=NULL)
	{
		for(i=0;i<MAX;i++)
		{
			printf("%c",cur->s[i]);
		}
		cur=cur->Next;
	}
}



int main()
{
	LinkString *L=NULL;
	LinkString *S=NULL;
	char s[MAX_SIZE],s_s[MAX_SIZE]; 
	printf("请输入要赋值的字符串：\n");
	scanf("%s",&s); 
	L=InitString(L,s);
	S=CopyString(L,S);
	OutputString(L);
	OutputString(S);
	printf("请输入要匹配的字符串：\n");
	scanf("%s",s_s);
	StrIndex(L,s_s);
	ReplaceString(L,"abcde",2);
	OutputString(L);
	return 0;
 } 
