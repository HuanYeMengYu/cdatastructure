#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0

typedef int ElemType;   //线性表的链式储存结构
typedef struct Node
{
ElemType data;
struct Node *next;
}Node;
typedef struct Node *LinkList;

//void CreatListHead(LinkList *L,int n);  头插法创建整表单链表
void CreatListTail(LinkList *L,int n);  //尾插法创建整表单链表,更符合正常人思维(传指针)
int GetElem(LinkList L,int i,ElemType *e);   //获得元素的操作（传值即可）
int ListInsert(LinkList *L,int i,ElemType e);//插入元素的操作(传指针)
int ListDelete(LinkList *L,int i,ElemType *e);  //删除元素的操作(传指针)
int ClearList(LinkList *L);  //清除单链表的操作(传指针)

int main()
{
LinkList L;
//CreatListHead(&L,10);
CreatListTail(&L,10);
int a=5;
ElemType *e=&a;
GetElem(L,2,e);
printf("%d\n",*e);
ListInsert(&L,2,999);
printf("%d\n",L->next->next->data);
ListDelete(&L,2,e);
printf("%d\n",*e);
printf("%d\n",L->next->next->data);
ClearList(&L);
return 0;
}

//void CreatListHead(LinkList *L,int n)  //头插法创建整表单链表
//{
//srand(time(NULL));   //time(NULL)表示不用参数，直接返回当前时间，srand用来初始化随机数种子
//*L=(LinkList)malloc(sizeof(Node));
//*L->next=NULL;
//for(int i=0;i<n;i++)
//    {
//        LinkList p=(LinkList)malloc(sizeof(Node));
//        p->data=rand()%100+1; //rand()%100表示获得0-99的随机数，+1则位1-100
//        p->next=L->next;
//        (*L)->next=p;
//    }
//}

void CreatListTail(LinkList *L,int n)  //尾插法创建整表单链表,更符合正常人思维
{
    srand(time(NULL));//time(NULL)表示不用参数，直接返回当前时间，srand用来初始化随机数种子
    *L=(LinkList)malloc(sizeof(Node));
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

int GetElem(LinkList L,int i,ElemType *e)  //获得元素的操作
{
    LinkList p=L->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
    {
        return ERROR;
    }
    *e=p->data;
    return OK;
}

int ListInsert(LinkList *L,int i,ElemType e)  //插入元素的操作
{
LinkList p=*L;
int j=1;
while(p&&j<i)
{
    p=p->next;
    j++;
}
if(!p||j>i)
{
    return ERROR;
}
LinkList s=(LinkList)malloc(sizeof(Node));
s->data=e;
s->next=p->next;
p->next=s;
return OK;
}

int ListDelete(LinkList *L,int i,ElemType *e)  //删除元素的操作
{
    LinkList p=*L;
    int j=1;
    while(p->next&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i)
    {
        return ERROR;
    }
    LinkList q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
    return OK;
}

int ClearList(LinkList *L)  //清除单链表的操作
{
    LinkList p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return OK;
}
