#include"librarymanage.h"
#include"readermanage.h"
//ͼ�����ϵͳ
void bookcharge()//ͼ�����ϵͳ����
{
     while(1)
    {
        Welcome();//��ʾϵͳ����
        char ch;
        ch=getch();
        switch(ch)
        {
            case '1':Inputbook();break;//¼���鼮��Ϣ
            case '2':Outputbook();break;//����鼮��Ϣ
            case '3':Savebookmessage();break;//�����鼮��Ϣ
            case '4':Readbookmessage();break;//��ȡ�鼮��Ϣ
            case '5':printf("�鼮����Ϊ��%d\n",Countbook());break;//ͳ�������鼮��Ŀ
            case '6':Searchbookmessage();break;//�����鼮��Ϣ
            case '7':Modifybookmessage();break;//�޸��鼮��Ϣ
            case '8':Deletebookmessage();break;//ɾ���鼮��Ϣ
            case '0':
                {
                    printf("�ټ���\n");
                    exit(0);
                }
                break;//�˳�ϵͳ
            default:
                printf("���������룺\n");
                break;
        }

    }
}


void Welcome()
{
    printf("\t��ӭʹ��ͼ�����ϵͳ\n");
    printf("\t��ѡ�����б�\n");
    printf("\t1.¼���鼮��Ϣ\n");
    printf("\t2.��ӡ�鼮��Ϣ\n");
    printf("\t3.�����鼮��Ϣ\n");
    printf("\t4.��ȡ�鼮��Ϣ\n");
    printf("\t5.ͳ�������鼮��Ŀ\n");
    printf("\t6.�����鼮��Ϣ\n");
    printf("\t7.�޸��鼮��Ϣ\n");
    printf("\t8.ɾ���鼮��Ϣ\n");
    printf("\t0.�˳�ϵͳ\n");

}

void Inputbook()//¼���鼮��Ϣ
{
    //����һ���½��
    Node* pNewNode=(Node*)malloc(sizeof(Node));
    pNewNode->pNext=NULL;
    if(pHead==NULL)
    {
        pHead=pNewNode;//������Ϊ�գ��½����Ϊͷ���
        pTail=pNewNode;//������Ϊ�գ��½����Ϊβ���
    }
    else
    {
        pTail->pNext=pNewNode;//������Ϊ�գ�β���pnextָ���½ڵ�
        pTail=pNewNode;//ָ��β����ָ��ָ���½��
    }
    pTail->pNext=NULL;
    printf("����������\n");
    scanf("%s",pNewNode->bo.bookname);
    printf("������������\n");
    scanf("%s",pNewNode->bo.writername);
    printf("��������\n");
    scanf("%d",&pNewNode->bo.number);
    printf("������۸�\n");
    scanf("%d",&pNewNode->bo.price);
    printf("����¼��ɹ�\n");
}

void Outputbook()//����鼮��Ϣ
{
    Node *temp=pHead;//��ȡָ��ͷ����ָ��
    if(temp==NULL)
    {
        printf("�鼮����Ϊ��\n");
    }
    while(temp!=NULL)
    {
        printf("�鼮��ţ�%d\t",temp->bo.number);
        printf("������%s\t",temp->bo.bookname);
        printf("��������%s\t",temp->bo.writername);
        printf("�۸�%d\n",temp->bo.price);
        temp=temp->pNext;//ָ����һ�����
    }
}

void Savebookmessage()//�����鼮��Ϣ
{
    FILE *fp;
    fp=fopen("book.data","w");//���ļ�
    if(fp==NULL)
    {
        printf("file open error");//������ļ�ʧ�����˳�
        exit(0);
    }
    Node *temp=pHead;//��ȡָ��ͷ����ָ��
    while(temp!=NULL)
    {
        fwrite(&temp->bo,1,sizeof(Book),fp);//д������
        temp=temp->pNext;//ָ����һ�����
    }
    fclose(fp);//�ر��ļ�
    printf("���ݱ���ɹ�\n");
}

void Readbookmessage()//���ļ���ȡ�鼮��Ϣ
{
    FILE *fp;
    fp=fopen("book.data","r");//���ļ�
    if(fp==NULL)
    {
        printf("file open error");//������ļ�ʧ�����˳�
        exit(0);
    }
    Book bo;
    while(fread(&bo,sizeof(Book),1,fp))
    {
        Node *pNewNode=(Node*)malloc(sizeof(Node));//����һ�����
        memcpy(&pNewNode->bo,&bo,sizeof(Book));
        pNewNode->pNext=NULL;
         if(pHead==NULL)
        {
            pHead=pNewNode;//������Ϊ�գ��½����Ϊͷ���
            pTail=pNewNode;//������Ϊ�գ��½����Ϊβ���
        }
        else
        {
            pTail->pNext=pNewNode;//������Ϊ�գ�β���pnextָ���½ڵ�
            pTail=pNewNode;//ָ��β����ָ��ָ���½��
        }
        pTail->pNext=NULL;

    }
    fclose(fp);//�ر��ļ�
    printf("��ȡ��Ϣ�ɹ�\n");
}


int Countbook()//ͳ�������鼮��Ŀ
{
    int count=0;
    Node *temp=NULL;
    temp=pHead;//����ָ��ͷ����ָ��
    while(temp!=NULL)//ָ��β������˳�ѭ��
    {
        count++;
        temp=temp->pNext;//ָ����һ�����
    }
    return count;

}

void Searchbookmessage()//�����鼮��Ϣ
{
    char BoName[20];
    int BoNumber;
    printf("�������鼮���ƣ�");
    scanf("%s",BoName);
    printf("�������鼮���:");
    scanf("%d",&BoNumber);
    Node* temp=NULL;//����һ�����ָ��
    temp=pHead;//��ָ��ָ��ͷ���
    while(1)
    {
        if(temp==NULL)//������ĩβ
        {
            printf("δ�ҵ��鼮��Ϣ\n");
            break;//����ѭ��
        }
        if(temp->bo.number==BoNumber||!strcmp(temp->bo.bookname,&BoName))
        {
            printf("�����鼮��Ϣ�ɹ�\n");
            printf("�鼮��ţ�%d\t",temp->bo.number);
            printf("������%s\t",temp->bo.bookname);
            printf("��������%s\t",temp->bo.writername);
            printf("�۸�%d\n",temp->bo.price);
            break;//����ѭ��
        }
        temp=temp->pNext;//ָ����һ�����
    }
}


void Modifybookmessage()//�޸��鼮��Ϣ
{
    int BoNumber;
    printf("�������鼮��ţ�");
    scanf("%d",&BoNumber);
    Node* temp=NULL;//����һ�����ָ��
    temp=pHead;//��ָ��ָ��ͷ���
    while(1)
    {
        if(temp==NULL)//������ĩβ
        {
            printf("δ�ҵ��鼮��Ϣ\n");
            break;//����ѭ��
        }
        if(temp->bo.number==BoNumber)
        {
            printf("�������޸ĺ��������");
            scanf("%s",temp->bo.bookname);
            printf("�������޸ĺ����������");
            scanf("%s",temp->bo.writername);
            printf("�������޸ĺ�ļ۸�");
            scanf("%d",&temp->bo.price);
            printf("�޸���Ϣ�ɹ�\n");
            break;//����ѭ��
        }
        temp=temp->pNext;//ָ����һ�����
    }
}


void Deletebookmessage()//ɾ���鼮��Ϣ
{
    int BoNumber;
    printf("������Ҫɾ�����鼮��ţ�");
    scanf("%d",&BoNumber);
    Node *temp1=NULL;//����һ�����ָ��
    Node *temp2=NULL;//����һ�����ָ��
    if(pHead->bo.number==BoNumber)//���Ҫɾ������ͷ���
    {
        temp1=pHead;//ָ��ͷ���
        pHead=pHead->pNext;//����һ�����Ϊͷ���
        free(temp1);//ɾ��ͷ���
        printf("ɾ�����ݳɹ�\n");
        return;
    }
    temp1=pHead;//
    while(temp1!=NULL)//���ɾ���Ĳ���ͷ���
    {
        if(temp1->pNext->bo.number==BoNumber)
        {
            temp2=temp1->pNext;//��temp2ָ��Ҫɾ���Ľ��
            temp1->pNext=temp2->pNext;//��temp1��temp2����һ���������
            free(temp2);//ɾ��temp2;
            printf("ɾ�����ݳɹ�\n");
            break;//����ѭ��
        }
        temp1=temp1->pNext;//ָ����һ�����
    }
    if(temp1==NULL)
    {
        printf("δ�ҵ�Ҫɾ������Ϣ\n");
    }
}


//   �û�����ϵͳ
void readcharge()//��ʾ���Ľ���
{
     while(1)
    {
        welcome();//��ʾ�û�ϵͳ����
        char ch;
        ch=getch();
        switch(ch)
        {
            case '1':lendbook();break;//����ͼ��
            case '2':returnbook();break;//�黹ͼ��
            case '3':findbook();break;//����ͼ��
            case '4':glancebook();break;//�鿴����ͼ��
            case '5':mylend();break;//�鿴�ҵĽ���*/
            case '0':
                {
                    printf("�ټ���\n");
                    exit(0);
                }
                break;//�˳�ϵͳ
            default:
                printf("���������룺\n");
                break;
        }

    }

}
void welcome()////��ʾ�û�ϵͳ����
{
    printf("\t��ӭʹ�ý���ϵͳ\n");
    printf("\t��ѡ�����б�\n");
    printf("\t1.����ͼ��\n");
    printf("\t2.�黹ͼ��\n");
    printf("\t3.����ͼ��\n");
    printf("\t4.�鿴����ͼ��\n");
    printf("\t5.�鿴�ҵĽ���\n");
    printf("\t0.�˳�ϵͳ\n");

}

void lendbook()//����ͼ��
{
    Readbookmessage();
    int number;
    printf("������Ҫ���ĵ�ͼ���ţ�");
    scanf("%d",&number);
    Node* temp=NULL;//����һ�����ָ��
    temp=pHead;//��ָ��ָ��ͷ���
    while(1)
    {
        if(temp==NULL)//������ĩβ
        {
            printf("δ�ҵ��鼮��Ϣ\n");
            break;//����ѭ��
        }
        if(temp->bo.number==number)
        {
            printf("�����鼮��Ϣ�ɹ�\n");
            //����һ���½��
            reader* pNewread=(reader*)malloc(sizeof(reader));
            pNewread->Next=NULL;
            if(phead==NULL)
            {
                phead=pNewread;//������Ϊ�գ��½����Ϊͷ���
                ptail=pNewread;//������Ϊ�գ��½����Ϊβ���

            }
            else
            {
                ptail->Next=pNewread;//������Ϊ�գ�β���nextָ���½ڵ�
                ptail=pNewread;//ָ��β����ָ��ָ���½��
            }
            pNewread->readernumber=number;
            strcpy(pNewread->readerbook,temp->bo.bookname);
            printf("���ĳɹ�\n");
            break;//����ѭ��
        }
        temp=temp->pNext;//ָ����һ�����
    }

}


void returnbook()//�黹ͼ��
{
    int Bonumber;
    printf("������Ҫ�黹��ͼ���ţ�");
    scanf("%d",&Bonumber);
    reader *temp1=NULL;//����һ�����ָ��
    reader *temp2=NULL;//����һ�����ָ��
    if(phead->readernumber==Bonumber)//���Ҫ�黹����ͷ���
    {
        temp1=phead;//ָ��ͷ���
        phead=phead->Next;//����һ�����Ϊͷ���
        free(temp1);//ɾ��ͷ���
        printf("�黹ͼ��ɹ�\n");
        return;
    }
    temp1=phead;//
    while(temp1!=NULL)//����黹�Ĳ���ͷ���
    {
        if(temp1->Next->readernumber==Bonumber)
        {
            temp2=temp1->Next;//��temp2ָ��Ҫ�黹��ͼ��
            temp1->Next=temp2->Next;//��temp1��temp2����һ���������
            free(temp2);//ɾ��temp2;
            printf("�黹ͼ��ɹ�\n");
            break;//����ѭ��
        }
        temp1=temp1->Next;//ָ����һ�����
    }
    if(temp1==NULL)
    {
        printf("δ�ҵ��黹��ͼ��\n");
    }
}


void findbook()//����ͼ��
{
    Readbookmessage();
    char boname[20];
    int bonumber;
    printf("������Ҫ���ҵ��鼮��ţ�");
    scanf("%d",&bonumber);
    printf("�������鼮���ƣ�");
    scanf("%s",boname);
    Node* temp=NULL;//����һ�����ָ��
    temp=pHead;//��ָ��ָ��ͷ���
    while(1)
    {
        if(temp==NULL)//������ĩβ
        {
            printf("δ�ҵ��鼮��Ϣ\n");
            break;//����ѭ��
        }
        if(temp->bo.number==bonumber||!strcmp(temp->bo.bookname,&boname))
        {
            printf("�����鼮��Ϣ�ɹ�\n");
            printf("�鼮��ţ�%d\t",temp->bo.number);
            printf("������%s\t",temp->bo.bookname);
            printf("��������%s\t",temp->bo.writername);
            printf("�۸�%d\n",temp->bo.price);
            break;//����ѭ��
        }
        temp=temp->pNext;//ָ����һ�����
    }

}


void glancebook()//�鿴����ͼ��
{
    Readbookmessage();;
    Outputbook();
}

void mylend()//�鿴�ҵĽ���*/
{
    reader *temp=phead;//��ȡָ��ͷ����ָ��
    if(temp==NULL)
    {
        printf("δ����ͼ��\n");
    }
    while(temp!=NULL)
    {
        printf("�鼮��ţ�%d\t",temp->readernumber);
        printf("������%s\t",temp->readerbook);
        temp=temp->Next;//ָ����һ�����
    }
}


int main()
{
    int x;
 	printf("��ӭ����ͼ���ϵͳ����1�������Աϵͳ����2�����û�ϵͳ");
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
