#ifndef READERMANAGE_H_INCLUDED
#define READERMANAGE_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Reader//�û�����������
{
    char readerbook[20];//�����鼮��
    int readernumber;//j�����鼮���
    struct _Reader* Next;//ָ����һ������ָ��

}reader;

reader *phead=NULL;//����һ��ͷ���ָ��
reader *ptail=NULL;//����һ��β���ָ��

void readcharge();//�û�����ϵͳ
void welcome();//��ʾ�û�����
void lendbook();//����ͼ��
void returnbook();//�黹ͼ��
void findbook();//����ͼ��
void glancebook();//�鿴����ͼ��
void mylend();//�鿴�ҵĽ���


#endif // READERMANAGE_H_INCLUDED
