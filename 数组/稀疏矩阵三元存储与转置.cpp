#include<stdio.h>
#define MAX 100
typedef struct{
	int row;//����
	int column;//����
	int value;//ֵ 
}Tri;

typedef struct{
	Tri va[MAX];//ϡ�����
	int ro,col,num;//ϡ�����������������������Ϊ���Ԫ������ 
}Matrix;


void Tmatrix(Matrix *ma1,Matrix *ma2)//ϡ������ת�� 
{
	ma2->ro=ma1->col;//ת�ú�ľ�������Ϊԭ���������
	ma2->col=ma1->ro;//ת�ú�ľ�������Ϊԭ���������
	ma2->num=ma1->num;//��������
	int co=0;
	int temp=0;//ָ��ת�þ��� 
	for(co=0;co<ma1->col;co++)//���������� 
	{
		for(int nu=0;nu<ma1->num;nu++)
		{
			if(ma1->va[nu].column==co)//�������ڴ��У���ת��
			{
				ma2->va[temp].row=ma1->va[nu].column;
				ma2->va[temp].column=ma1->va[nu].row;
				ma2->va[temp].value=ma1->va[nu].value;
				temp++;
			} 
		}
	 } 
}


