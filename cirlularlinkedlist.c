#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

void CreatListTail(LinkList *L,int n);//尾插法创建整表单链表

int main()
{
    LinkList space1,space2;
    CreatListTail(&space1,10);
    system("pause");
    CreatListTail(&space2,10); //创建两个头结点+10个Node的链表
    LinkList rear1=space1,rear2=space2;   //定义两个尾指针
    while(rear1->next!=NULL)
    {
        rear1=rear1->next;
    }
    while(rear2->next!=NULL)
    {
        rear2=rear2->next;
    }
    rear1->next=space1;
    rear2->next=space2;       //创建了两个循环链表
    LinkList last1=space1->next;
    LinkList last2=space2->next;
    while(last1!=space1)
    {
        printf("%d ",last1->data);
        last1=last1->next;
    }
    printf("\n");
    while(last2!=space2)
    {
        printf("%d ",last2->data);
        last2=last2->next;
    }
    printf("\n");
    LinkList p=rear1->next;    //将两个循环链表合并为一个循环链表
    rear1->next=rear2->next->next;
    LinkList q=rear2->next;
    rear2->next=p;
    free(q);
    LinkList last=space1->next;
    while(last!=space1)
    {
        printf("%d ",last->data);
        last=last->next;
    }
    printf("\n");
    return 0;
}

void CreatListTail(LinkList *L,int n)  //尾插法创建整表单链表
{
    srand(time(NULL));//time(NULL)表示不用参数，直接返回当前时间，srand用来初始化随机数种子
    *L=(LinkList)malloc(sizeof(Node)); //*L为链表的头结点地址
    LinkList r=*L;
    for(int i=0;i<n;i++)
    {
        LinkList p=(Node*)malloc(sizeof(Node));
        p->data=rand()%100+1;//rand()%100表示获得0-99的随机数，+1则位1-100
        r->next=p;
        r=p;
    }
    r->next=NULL;
}