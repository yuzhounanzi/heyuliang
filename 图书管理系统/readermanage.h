#ifndef READERMANAGE_H_INCLUDED
#define READERMANAGE_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Reader//用户数据链表结点
{
    char readerbook[20];//借阅书籍名
    int readernumber;//j借阅书籍编号
    struct _Reader* Next;//指向下一个结点的指针

}reader;

reader *phead=NULL;//创建一个头结点指针
reader *ptail=NULL;//创建一个尾结点指针

void readcharge();//用户管理系统
void welcome();//显示用户界面
void lendbook();//借阅图书
void returnbook();//归还图书
void findbook();//查找图书
void glancebook();//查看所有图书
void mylend();//查看我的借阅


#endif // READERMANAGE_H_INCLUDED
