#ifndef LIBRARYMANAGE_H_INCLUDED
#define LIBRARYMANAGE_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Book//�鼮��Ϣ�ṹ
{
    char bookname[20];//����
    char writername[20];//������
    int number;//���
    int price;//�۸�
}Book;


typedef struct _Node//ͼ������������
{
    Book bo;//�鼮����
    struct _Node* pNext;//ָ����һ������ָ��

}Node;

Node *pHead=NULL;//����һ��ͷ���ָ��
Node *pTail=NULL;//����һ��β���ָ��


void bookcharge();//ͼ�����ϵͳ����
void Welcome();//��ʾͼ��ϵͳ����
void Inputbook();//¼���鼮��Ϣ
void Outputbook();//����鼮��Ϣ
void Savebookmessage();//�����鼮��Ϣ
void Readbookmessage();//��ȡ�鼮��Ϣ
int Countbook();//ͳ�������鼮��Ŀ
void Searchbookmessage();//�����鼮��Ϣ
void Modifybookmessage();//�޸��鼮��Ϣ
void Deletebookmessage();//ɾ���鼮��Ϣ

#endif // LIBRARYMANAGE_H_INCLUDED
