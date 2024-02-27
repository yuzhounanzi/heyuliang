#include<stdio.h>
#define MAX 100
typedef struct{
	int row;//行数
	int column;//列数
	int value;//值 
}Tri;

typedef struct{
	Tri va[MAX];//稀疏矩阵
	int ro,col,num;//稀疏矩阵总行数，总列数，不为零的元素总数 
}Matrix;


void Tmatrix(Matrix *ma1,Matrix *ma2)//稀疏矩阵的转置 
{
	ma2->ro=ma1->col;//转置后的矩阵行数为原矩阵的列数
	ma2->col=ma1->ro;//转置后的矩阵列数为原矩阵的行数
	ma2->num=ma1->num;//总数不变
	int co=0;
	int temp=0;//指向转置矩阵 
	for(co=0;co<ma1->col;co++)//按列数遍历 
	{
		for(int nu=0;nu<ma1->num;nu++)
		{
			if(ma1->va[nu].column==co)//若数据在此列，则转置
			{
				ma2->va[temp].row=ma1->va[nu].column;
				ma2->va[temp].column=ma1->va[nu].row;
				ma2->va[temp].value=ma1->va[nu].value;
				temp++;
			} 
		}
	 } 
}


