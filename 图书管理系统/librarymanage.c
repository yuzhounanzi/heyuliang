#include"librarymanage.h"
#include"readermanage.h"
//图书管理系统
void bookcharge()//图书管理系统函数
{
     while(1)
    {
        Welcome();//显示系统界面
        char ch;
        ch=getch();
        switch(ch)
        {
            case '1':Inputbook();break;//录入书籍信息
            case '2':Outputbook();break;//输出书籍信息
            case '3':Savebookmessage();break;//保存书籍信息
            case '4':Readbookmessage();break;//读取书籍信息
            case '5':printf("书籍总数为：%d\n",Countbook());break;//统计所有书籍数目
            case '6':Searchbookmessage();break;//查找书籍信息
            case '7':Modifybookmessage();break;//修改书籍信息
            case '8':Deletebookmessage();break;//删除书籍信息
            case '0':
                {
                    printf("再见！\n");
                    exit(0);
                }
                break;//退出系统
            default:
                printf("请重新输入：\n");
                break;
        }

    }
}


void Welcome()
{
    printf("\t欢迎使用图书管理系统\n");
    printf("\t请选择功能列表\n");
    printf("\t1.录入书籍信息\n");
    printf("\t2.打印书籍信息\n");
    printf("\t3.保存书籍信息\n");
    printf("\t4.读取书籍信息\n");
    printf("\t5.统计所有书籍数目\n");
    printf("\t6.查找书籍信息\n");
    printf("\t7.修改书籍信息\n");
    printf("\t8.删除书籍信息\n");
    printf("\t0.退出系统\n");

}

void Inputbook()//录入书籍信息
{
    //创建一个新结点
    Node* pNewNode=(Node*)malloc(sizeof(Node));
    pNewNode->pNext=NULL;
    if(pHead==NULL)
    {
        pHead=pNewNode;//若链表为空，新建结点为头结点
        pTail=pNewNode;//若链表为空，新建结点为尾结点
    }
    else
    {
        pTail->pNext=pNewNode;//若链表不为空，尾结点pnext指向新节点
        pTail=pNewNode;//指向尾结点的指针指向新结点
    }
    pTail->pNext=NULL;
    printf("请输入书名\n");
    scanf("%s",pNewNode->bo.bookname);
    printf("请输入作者名\n");
    scanf("%s",pNewNode->bo.writername);
    printf("请输入编号\n");
    scanf("%d",&pNewNode->bo.number);
    printf("请输入价格\n");
    scanf("%d",&pNewNode->bo.price);
    printf("数据录入成功\n");
}

void Outputbook()//输出书籍信息
{
    Node *temp=pHead;//获取指向头结点的指针
    if(temp==NULL)
    {
        printf("书籍数据为空\n");
    }
    while(temp!=NULL)
    {
        printf("书籍编号：%d\t",temp->bo.number);
        printf("书名：%s\t",temp->bo.bookname);
        printf("作者名：%s\t",temp->bo.writername);
        printf("价格：%d\n",temp->bo.price);
        temp=temp->pNext;//指向下一个结点
    }
}

void Savebookmessage()//保存书籍信息
{
    FILE *fp;
    fp=fopen("book.data","w");//打开文件
    if(fp==NULL)
    {
        printf("file open error");//如果打开文件失败则退出
        exit(0);
    }
    Node *temp=pHead;//获取指向头结点的指针
    while(temp!=NULL)
    {
        fwrite(&temp->bo,1,sizeof(Book),fp);//写入数据
        temp=temp->pNext;//指向下一个结点
    }
    fclose(fp);//关闭文件
    printf("数据保存成功\n");
}

void Readbookmessage()//从文件读取书籍信息
{
    FILE *fp;
    fp=fopen("book.data","r");//打开文件
    if(fp==NULL)
    {
        printf("file open error");//如果打开文件失败则退出
        exit(0);
    }
    Book bo;
    while(fread(&bo,sizeof(Book),1,fp))
    {
        Node *pNewNode=(Node*)malloc(sizeof(Node));//创建一个结点
        memcpy(&pNewNode->bo,&bo,sizeof(Book));
        pNewNode->pNext=NULL;
         if(pHead==NULL)
        {
            pHead=pNewNode;//若链表为空，新建结点为头结点
            pTail=pNewNode;//若链表为空，新建结点为尾结点
        }
        else
        {
            pTail->pNext=pNewNode;//若链表不为空，尾结点pnext指向新节点
            pTail=pNewNode;//指向尾结点的指针指向新结点
        }
        pTail->pNext=NULL;

    }
    fclose(fp);//关闭文件
    printf("读取信息成功\n");
}


int Countbook()//统计所有书籍数目
{
    int count=0;
    Node *temp=NULL;
    temp=pHead;//设置指向头结点的指针
    while(temp!=NULL)//指向尾结点则退出循环
    {
        count++;
        temp=temp->pNext;//指向下一个结点
    }
    return count;

}

void Searchbookmessage()//查找书籍信息
{
    char BoName[20];
    int BoNumber;
    printf("请输入书籍名称：");
    scanf("%s",BoName);
    printf("请输入书籍编号:");
    scanf("%d",&BoNumber);
    Node* temp=NULL;//创建一个结点指针
    temp=pHead;//让指针指向头结点
    while(1)
    {
        if(temp==NULL)//遍历到末尾
        {
            printf("未找到书籍信息\n");
            break;//跳出循环
        }
        if(temp->bo.number==BoNumber||!strcmp(temp->bo.bookname,&BoName))
        {
            printf("查找书籍信息成功\n");
            printf("书籍编号：%d\t",temp->bo.number);
            printf("书名：%s\t",temp->bo.bookname);
            printf("作者名：%s\t",temp->bo.writername);
            printf("价格：%d\n",temp->bo.price);
            break;//跳出循环
        }
        temp=temp->pNext;//指向下一个结点
    }
}


void Modifybookmessage()//修改书籍信息
{
    int BoNumber;
    printf("请输入书籍编号：");
    scanf("%d",&BoNumber);
    Node* temp=NULL;//创建一个结点指针
    temp=pHead;//让指针指向头结点
    while(1)
    {
        if(temp==NULL)//遍历到末尾
        {
            printf("未找到书籍信息\n");
            break;//跳出循环
        }
        if(temp->bo.number==BoNumber)
        {
            printf("请输入修改后的书名：");
            scanf("%s",temp->bo.bookname);
            printf("请输入修改后的作者名：");
            scanf("%s",temp->bo.writername);
            printf("请输入修改后的价格：");
            scanf("%d",&temp->bo.price);
            printf("修改信息成功\n");
            break;//跳出循环
        }
        temp=temp->pNext;//指向下一个结点
    }
}


void Deletebookmessage()//删除书籍信息
{
    int BoNumber;
    printf("请输入要删除的书籍编号：");
    scanf("%d",&BoNumber);
    Node *temp1=NULL;//创建一个结点指针
    Node *temp2=NULL;//创建一个结点指针
    if(pHead->bo.number==BoNumber)//如果要删除的是头结点
    {
        temp1=pHead;//指向头结点
        pHead=pHead->pNext;//让下一个结点为头结点
        free(temp1);//删除头结点
        printf("删除数据成功\n");
        return;
    }
    temp1=pHead;//
    while(temp1!=NULL)//如果删除的不是头结点
    {
        if(temp1->pNext->bo.number==BoNumber)
        {
            temp2=temp1->pNext;//让temp2指向要删除的结点
            temp1->pNext=temp2->pNext;//让temp1和temp2的下一个结点链接
            free(temp2);//删除temp2;
            printf("删除数据成功\n");
            break;//跳出循环
        }
        temp1=temp1->pNext;//指向下一个结点
    }
    if(temp1==NULL)
    {
        printf("未找到要删除的信息\n");
    }
}


//   用户借阅系统
void readcharge()//显示借阅界面
{
     while(1)
    {
        welcome();//显示用户系统界面
        char ch;
        ch=getch();
        switch(ch)
        {
            case '1':lendbook();break;//借阅图书
            case '2':returnbook();break;//归还图书
            case '3':findbook();break;//查找图书
            case '4':glancebook();break;//查看所有图书
            case '5':mylend();break;//查看我的借阅*/
            case '0':
                {
                    printf("再见！\n");
                    exit(0);
                }
                break;//退出系统
            default:
                printf("请重新输入：\n");
                break;
        }

    }

}
void welcome()////显示用户系统界面
{
    printf("\t欢迎使用借阅系统\n");
    printf("\t请选择功能列表\n");
    printf("\t1.借阅图书\n");
    printf("\t2.归还图书\n");
    printf("\t3.查找图书\n");
    printf("\t4.查看所有图书\n");
    printf("\t5.查看我的借阅\n");
    printf("\t0.退出系统\n");

}

void lendbook()//借阅图书
{
    Readbookmessage();
    int number;
    printf("请输入要借阅的图书编号：");
    scanf("%d",&number);
    Node* temp=NULL;//创建一个结点指针
    temp=pHead;//让指针指向头结点
    while(1)
    {
        if(temp==NULL)//遍历到末尾
        {
            printf("未找到书籍信息\n");
            break;//跳出循环
        }
        if(temp->bo.number==number)
        {
            printf("查找书籍信息成功\n");
            //创建一个新结点
            reader* pNewread=(reader*)malloc(sizeof(reader));
            pNewread->Next=NULL;
            if(phead==NULL)
            {
                phead=pNewread;//若链表为空，新建结点为头结点
                ptail=pNewread;//若链表为空，新建结点为尾结点

            }
            else
            {
                ptail->Next=pNewread;//若链表不为空，尾结点next指向新节点
                ptail=pNewread;//指向尾结点的指针指向新结点
            }
            pNewread->readernumber=number;
            strcpy(pNewread->readerbook,temp->bo.bookname);
            printf("借阅成功\n");
            break;//跳出循环
        }
        temp=temp->pNext;//指向下一个结点
    }

}


void returnbook()//归还图书
{
    int Bonumber;
    printf("请输入要归还的图书编号：");
    scanf("%d",&Bonumber);
    reader *temp1=NULL;//创建一个结点指针
    reader *temp2=NULL;//创建一个结点指针
    if(phead->readernumber==Bonumber)//如果要归还的是头结点
    {
        temp1=phead;//指向头结点
        phead=phead->Next;//让下一个结点为头结点
        free(temp1);//删除头结点
        printf("归还图书成功\n");
        return;
    }
    temp1=phead;//
    while(temp1!=NULL)//如果归还的不是头结点
    {
        if(temp1->Next->readernumber==Bonumber)
        {
            temp2=temp1->Next;//让temp2指向要归还的图书
            temp1->Next=temp2->Next;//让temp1和temp2的下一个结点链接
            free(temp2);//删除temp2;
            printf("归还图书成功\n");
            break;//跳出循环
        }
        temp1=temp1->Next;//指向下一个结点
    }
    if(temp1==NULL)
    {
        printf("未找到归还的图书\n");
    }
}


void findbook()//查找图书
{
    Readbookmessage();
    char boname[20];
    int bonumber;
    printf("请输入要查找的书籍编号：");
    scanf("%d",&bonumber);
    printf("请输入书籍名称：");
    scanf("%s",boname);
    Node* temp=NULL;//创建一个结点指针
    temp=pHead;//让指针指向头结点
    while(1)
    {
        if(temp==NULL)//遍历到末尾
        {
            printf("未找到书籍信息\n");
            break;//跳出循环
        }
        if(temp->bo.number==bonumber||!strcmp(temp->bo.bookname,&boname))
        {
            printf("查找书籍信息成功\n");
            printf("书籍编号：%d\t",temp->bo.number);
            printf("书名：%s\t",temp->bo.bookname);
            printf("作者名：%s\t",temp->bo.writername);
            printf("价格：%d\n",temp->bo.price);
            break;//跳出循环
        }
        temp=temp->pNext;//指向下一个结点
    }

}


void glancebook()//查看所有图书
{
    Readbookmessage();;
    Outputbook();
}

void mylend()//查看我的借阅*/
{
    reader *temp=phead;//获取指向头结点的指针
    if(temp==NULL)
    {
        printf("未借阅图书\n");
    }
    while(temp!=NULL)
    {
        printf("书籍编号：%d\t",temp->readernumber);
        printf("书名：%s\t",temp->readerbook);
        temp=temp->Next;//指向下一个结点
    }
}


int main()
{
    int x;
 	printf("欢迎进入图书馆系统，按1进入管理员系统，按2进入用户系统");
 	scanf("%d",&x);
 	if(x==1)
    {
       bookcharge();
    }
    if(x==2)
    {
        readcharge();
    }
    return 0;
}
