#ifndef LIBRARYMANAGE_H_INCLUDED
#define LIBRARYMANAGE_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Book//书籍信息结构
{
    char bookname[20];//书名
    char writername[20];//作者名
    int number;//编号
    int price;//价格
}Book;


typedef struct _Node//图书数据链表结点
{
    Book bo;//书籍数据
    struct _Node* pNext;//指向下一个结点的指针

}Node;

Node *pHead=NULL;//创建一个头结点指针
Node *pTail=NULL;//创建一个尾结点指针


void bookcharge();//图书管理系统函数
void Welcome();//显示图书系统界面
void Inputbook();//录入书籍信息
void Outputbook();//输出书籍信息
void Savebookmessage();//保存书籍信息
void Readbookmessage();//读取书籍信息
int Countbook();//统计所有书籍数目
void Searchbookmessage();//查找书籍信息
void Modifybookmessage();//修改书籍信息
void Deletebookmessage();//删除书籍信息

#endif // LIBRARYMANAGE_H_INCLUDED
