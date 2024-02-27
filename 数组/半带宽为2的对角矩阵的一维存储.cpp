#include<stdio.h>
#include<math.h>
int main()
{
	int n;//n维矩阵 
	while(scanf("%d",&n)!=EOF)//半带宽为2的对角矩阵的一维存储 
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
		int num=n;//存储元素的总数
		m-=1;
		for(int b=0;b<2;b++)
		{
			num=num+m*2;
			m--;
		}
		int k=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(abs(i-j)<=2)
				{
					ma[k]=matrix[i][j];
					k++;
				}
			}
		}
		for(k=0;k<num;k++)
		{
			printf("%d ",ma[k]);
		}
	}
	return 0;
 } 
