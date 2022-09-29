#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;
typedef struct Node
{
    ElemType data;
    struct Node *prior;
    struct Node *next;
}Node,*LinkList;

Status MakeList(LinkList *L,int n);//生成一个双向链表
Status ListInsert(LinkList *L,int i,ElemType e);//插入元素的操作
Status ListDelete(LinkList *L,int i);//删除结点的操作

int main()
{
    LinkList L;
    MakeList(&L,10);//生成一个头结点+10个结点双向链表
    LinkList last=L->next;
    while(last->next)
    {
        printf("%d ",last->data);
        last=last->next;
    }
    printf("%d ",last->data);
    printf("\n");
    last=L;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=L;   //把双向链表也变为循环链表
    ListInsert(&L,3,999);
    last=L;
    for(int i=0;i<3;i++)
    {
        last=last->next;
    }
    printf("%d\n",last->data);
    ListDelete(&L,3);
    last=L->next;
    while (last!=L)
    {
        printf("%d ",last->data);
        last=last->next;
    }
    printf("\n");
    
    return 0;
}

Status MakeList(LinkList *L,int n)//生成一个双向链表
{
    srand(time(NULL));//time(NULL)表示不用参数，直接返回当前时间，srand用来初始化随机数种子
    *L=(LinkList)malloc(sizeof(Node));
    LinkList r=*L;
    for(int i=0;i<n;i++)
    {
        LinkList p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;//rand()%100表示获得0-99的随机数，+1则位1-100
        p->prior=r;
        r->next=p;
        r=p;
    }
    r->next=NULL;
    return OK;
}

Status ListInsert(LinkList *L,int i,ElemType e)//插入元素的操作
{
    LinkList r=*L;
    for(int j=1;j<i;j++)
    {
        r=r->next;
    }
    LinkList s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->prior=r;
    s->next=r->next;
    r->next->prior=s;
    r->next=s;
    return OK;
}

Status ListDelete(LinkList *L,int i)//删除结点的操作
{
    LinkList r=*L;
    for(int j=0;j<i;j++)
    {
        r=r->next;
    }
    r->prior->next=r->next;
    r->next->prior=r->prior;
    free(r);
    return OK;
}