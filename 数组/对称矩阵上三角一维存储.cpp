#include<stdio.h>
int main()
{
/*
	int mat[4][4]={{0,4,5,6},{4,1,7,8},{5,7,2,9},{6,8,9,3}};//�Գƾ���
	int ma[10];
	int k=0;
	for(int j=0;j<4;j++)//����������һά�洢,�������Խ��� 
	{
		for(int i=0;i<j;i++)
		{
			ma[k]=mat[i][j];
			k++;		
		}	
	} 
	for(int k=0;k<6;k++)
	{
		printf("%d",ma[k]);
	}
	return 0; 
*/
	int n;//nά�Գƾ��������Ǵ洢 ,�������Խ�Ԫ�� 
	while(scanf("%d",&n)!=EOF)
	{
		int matrix[100][100];
		int ma[100];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&matrix[i][j]);
			}
		}
		int m=n;
		m-=1;
		int num=0;//һά�����е����� 
		while(m!=0)
		{
			num=num+m;
			m--;
		}
		int k=0;
		for(int j=0;j<n;j++)//j��ʾ�� 
		{
			for(int i=0;i<j;i++)//�� 
			{
				ma[k]=matrix[i][j];
				k++;
			}
		}
		for(int k=0;k<num;k++)
		{
			printf("%d ",ma[k]);
		}
		
	}
		
}
