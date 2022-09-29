#include <stdio.h>

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct 
{
    ElemType data;
    int cur;
}StaticLinkList[MAXSIZE]; //定义结构体数组，与下面同理
  //struct STRUCT{
          //int a;
          //int b;
  //   }a[10];    只需要把结构变量定义给一个数组，即可得到结构体数组
//typedef与#define不同，typedef属于c语句，不在预处理里，由编译器处理
//并不是完全的文本替换

Status InitList(StaticLinkList space);//初始化静止链表的cur
int Malloc_SSL(StaticLinkList space);//取备用链表第一个结点的下标，并且改变指向备用链表的头指针
Status ListInsert(StaticLinkList space,int i,ElemType e);//插入元素的操作(新加元素也用这个)
int ListLength(StaticLinkList space); //返回当前静止链表的长度
Status ListDelete(StaticLinkList space,int i);//删除元素的操作
void Free_SSL(StaticLinkList space,int k);//释放操作（把删除的元素变为备用链表的头结点）

int main()
{
    StaticLinkList space;
    InitList(space);
    for(int i=1;i<=5;i++)
    {
        space[i].data=i;
    }
    space[MAXSIZE-1].cur=1;
    space[0].cur=6;
    space[5].cur=0;      //注意初始化的时候还要改一下指针
    int p=MAXSIZE-1;
    for(int i=1;i<=5;i++)
    {
        printf("%d ",space[space[p].cur].data);
        p=space[p].cur;
    }
    printf("\n");
    ListInsert(space,3,999);
    printf("%d\n",space[space[2].cur]);
    ListDelete(space,3);
    p=MAXSIZE-1;
    for(int i=1;i<=5;i++)
    {
        printf("%d ",space[space[p].cur].data);
        p=space[p].cur;
    }
    printf("\n");
    return 0;
}

Status InitList(StaticLinkList space)  //初始化静止链表的cur
{
    for(int i=0;i<MAXSIZE;i++)
    {
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0;
    return OK;
}

int Malloc_SSL(StaticLinkList space)  //取备用链表第一个结点的下标，并且改变指向备用链表的头指针
{
    int i=space[0].cur;
    if(space[0].cur)
    {
        space[0].cur=space[i].cur;
    }
    return i;
}

Status ListInsert(StaticLinkList space,int i,ElemType e)//插入元素的操作
{
    int k=MAXSIZE-1;  //k首先是最后一个元素的下标
    if(i<1||i>ListLength(space)+1)
    {
        return ERROR;
    }
    int j=Malloc_SSL(space);
    if(j)
    {
        space[j].data=e;
        for(int m=1;m<=i-1;m++)
        {
            k=space[k].cur;
        }
        space[j].cur=space[k].cur;
        space[k].cur=j;
        return OK;
    }
    return ERROR;
}

int ListLength(StaticLinkList space)  //返回当前静止链表的长度
{
    int j=0;
    int i=space[MAXSIZE-1].cur;
    while(i)
    {
        i=space[i].cur;
        j++;
    }
    return j;
}

Status ListDelete(StaticLinkList space,int i)//删除元素的操作
{
    if(i<1||i>ListLength(space))
    {
        return ERROR;
    }
    int k=MAXSIZE-1;
    for(int j=1;j<=i-1;j++)
    {
        k=space[k].cur;
    }
    int j=space[k].cur;
    space[k].cur=space[j].cur;
    Free_SSL(space,j);
    return OK;
}

void Free_SSL(StaticLinkList space,int k)//释放操作（把删除的元素变为备用链表的头结点）
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}