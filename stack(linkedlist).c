#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode,*LinkStackPtr;

typedef struct 
{
    LinkStackPtr top;
    int count;
} LinkStack;

Status Push(LinkStack *S,ElemType e);//进栈操作
Status Pop(LinkStack *S,ElemType *e);//出栈操作
int StackEmpty(LinkStack *S);//判断栈是否空的操作
Status ClearStack(LinkStack *S);//清空链栈的操作

int main()
{
    LinkStack StackTop;
    StackTop.top=NULL;
    StackTop.count=0;
    for(int i=1;i<=5;i++)
    {
        Push(&StackTop,i);
    }
    LinkStackPtr last=StackTop.top;
    while(last!=NULL)
    {
        printf("%d ",last->data);
        last=last->next;
    }
    printf("\n");
    int a=5;
    ElemType *e=&a;
    Pop(&StackTop,e);
    printf("%d\n",*e);
    last=StackTop.top;
    while(last!=NULL)
    {
        printf("%d ",last->data);
        last=last->next;
    }
    printf("\n");
    ClearStack(&StackTop);
    return 0;
}

Status Push(LinkStack *S,ElemType e)//进栈操作
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    s->next=S->top;
    S->top=s;
    S->count++;
    return OK;
}

Status Pop(LinkStack *S,ElemType *e)//出栈操作
{
    if(StackEmpty(S))
    {
        return ERROR;
    }
    *e=S->top->data;
    LinkStackPtr p=S->top;
    S->top=S->top->next;
    S->count--;
    free(p);   
    return OK;
}

int StackEmpty(LinkStack *S)//判断栈是否空的操作
{
    if(S=NULL)
    {
        return OK;
    }
    return ERROR;
}

Status ClearStack(LinkStack *S)//清空链栈的操作
{
    while(S->top!=NULL)
    {
        LinkStackPtr p=S->top;
        S->top=S->top->next;
        free(p);
    }
    S->count=0;
    return OK;
}