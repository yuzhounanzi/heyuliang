#include<stdio.h>
int main()
{
/*
	int mat[4][4]={{0,4,5,6},{4,1,7,8},{5,7,2,9},{6,8,9,3}};//对称矩阵
	int ma[10];
	int k=0;
	for(int j=0;j<4;j++)//矩阵上三角一维存储,不包括对角线 
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
	int n;//n维对称矩阵上三角存储 ,不包括对角元素 
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
		int num=0;//一维数组中的总数 
		while(m!=0)
		{
			num=num+m;
			m--;
		}
		int k=0;
		for(int j=0;j<n;j++)//j表示列 
		{
			for(int i=0;i<j;i++)//行 
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
