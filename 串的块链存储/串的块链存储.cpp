#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3
#define MAX_SIZE 10 
typedef struct Node{
	char s[MAX];//�ַ��� 
	Node* Next;//ָ����һ��� 
}LinkString;


LinkString* InitString(LinkString *L,char *s){//�������ĸ�ֵ 
	LinkString* pHead=(LinkString*)malloc(sizeof(LinkString));//ͷ���
	LinkString* cur=pHead;//��ʱ���ָ��ͷ��� 
	int num;//�����Ľ�����
	num=strlen(s)/MAX;//���㴴���Ľ�����
	if(strlen(s)%MAX!=0)
	{
		num++;//����ַ������ȳ��Խ�����洢�ַ�����Ϊ�㣬�ٶഴ��һ����� 
	 } 
	for(int i=0;i<num;i++)
	{
		LinkString* NewNode=(LinkString*)malloc(sizeof(LinkString));//�����½�� 
		for(int j=0;j<MAX;j++)//��ֵ 
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
	printf("��ֵ�ɹ�\n");
	return pHead;
} 


LinkString* CopyString(LinkString *L,LinkString *S){//���� 
	LinkString* pHead=(LinkString*)malloc(sizeof(LinkString));//ͷ���
	LinkString* Newcur=pHead;//ָ�򱻸��ƵĴ� 
	LinkString* cur=L->Next;//ָ��ԭ�� 
	while(cur)
	{
		LinkString* NewNode=(LinkString*)malloc(sizeof(LinkString));//�����½��
		Newcur->Next=NewNode;
		Newcur=Newcur->Next;
		for(int i=0;i<MAX;i++)//���� 
		{
			NewNode->s[i]=cur->s[i];
		}
		cur=cur->Next;
	 }
	 Newcur->Next=NULL;
	 printf("���Ƴɹ�\n");
	 LinkString* curr=pHead->Next;
	 return pHead; 
}


void DeleString(LinkString *L,int e){//ɾ�� 
	LinkString* cur=L;
	int num1=e/MAX+1;//ɾ��λ�����ĸ����
	int num2=e%MAX;//ɾ��λ���ڽ���ַ�����λ�� 
	for(int i=0;i<num1;i++)
	{
		cur=cur->Next;//ָ��Ŀ���� 
	}
	cur->s[num2-1]='*';//��ɾ�����ַ�����* 
	printf("ɾ���ɹ�\n");
}


void StrIndex(LinkString* L,char *s){//�ַ���ƥ�� 
	LinkString* cur=L->Next;
	int i=0,j=0;
	char temp[MAX_SIZE];//����һ����Ŵ����ݵ���ʱ��
	while(cur)//���������ݷŽ���ʱ���� 
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
	while(i<len1&&j<len2)//��֤��Խ�� 
	{
		if(temp[i]==s[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;//������������ݵ��¸�λ�� 
			j=0;
		}
	 }
	 if(j==len2)
	 {
	 	printf("ƥ��ɹ�,λ����%d\n",i-j);
	  }
	  else
	  {
	  	printf("ƥ��ʧ��\n");
	  }
}


void ReplaceString(LinkString *L,char *s,int e){//�ַ����滻,��eλ���滻 
	LinkString* cur=L;
	int num=(e/MAX)+1;//�滻λ�����ڽ��
	int leng=strlen(s);//�Ӵ�����
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
	printf("�滻�ɹ�\n");
	
}


void OutputString(LinkString *L)//��� 
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
	printf("������Ҫ��ֵ���ַ�����\n");
	scanf("%s",&s); 
	L=InitString(L,s);
	S=CopyString(L,S);
	OutputString(L);
	OutputString(S);
	printf("������Ҫƥ����ַ�����\n");
	scanf("%s",s_s);
	StrIndex(L,s_s);
	ReplaceString(L,"abcde",2);
	OutputString(L);
	return 0;
 } 
