#include <stdio.h>
#include <time.h>

#define MAXSIZE 10
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;  //指示栈顶元素在数组里的位置
} Stack;
typedef struct  //两栈共享空间结构
{
    ElemType data[MAXSIZE];
    int top1,top2;
} DoubleStack;


Status Push(Stack *S,ElemType e);//进栈操作
Status Pop(Stack *S,ElemType *e);//出栈操作
Status DPush(DoubleStack *DS,ElemType e,int StackNumber);//两栈共享空间结构的进栈操作
Status DPop(DoubleStack *DS,ElemType *e,int StackNumber);//两栈共享空间结构的出栈操作

int main()
{
    Stack S;
    S.top=0;
    for(int i=0;i<5;i++)
    {
        S.data[i]=i;
        S.top++;
        printf("%d ",S.data[i]);
    }
    printf("\n");
    Push(&S,999);
    printf("%d\n",S.data[S.top]);
    int a=5;
    ElemType *e=&a;
    Pop(&S,e);
    printf("%d\n",*e);
    for(int i=0;i<5;i++)
    {
        printf("%d ",S.data[i]);
    }
    printf("\n");
    DoubleStack DS;
    DS.top1=-1;
    DS.top2=MAXSIZE;
    for(int i=0;i<5;i++)
    {
        DS.data[DS.top1+1]=i;
        DS.top1++;
    }
    for(int i=0;i<3;i++)
    {
        DS.data[DS.top2-1]=i;
        DS.top2--;
    }
    DPush(&DS,999,1);
    printf("%d\n",DS.data[DS.top1]);
    DPop(&DS,e,1); 
    for(int i=0;i<MAXSIZE;i++)
    {
        printf("%d ",DS.data[i]);
    }
    printf("\n");
    return 0;
}

Status Push(Stack *S,ElemType e)//进栈操作
{
    if(S->top==MAXSIZE-1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}

Status Pop(Stack *S,ElemType *e)//出栈操作
{
    if(S->top==-1)
    {
        return ERROR;
    }
    *e=S->data[S->top];
    S->data[(S->top)--]=0;
    return OK;
}

Status DPush(DoubleStack *DS,ElemType e,int StackNumber)//两栈共享空间结构的进栈操作
{
    if(DS->top1+1==DS->top2)
    {
        return ERROR;
    }
    if(StackNumber==1)
    {
        DS->data[++DS->top1]=e;
    }
    else if(StackNumber==2)
    {
        DS->data[--DS->top2]=e;
    }
    return OK;
}

Status DPop(DoubleStack *DS,ElemType *e,int StackNumber)//两栈共享空间结构的出栈操作
{
    if(StackNumber==1)
    {
        if(DS->top1==-1)
        {
            return ERROR;
        }  //注意实质上没有把元素删掉，只是把top的位置移动了，元素仍在数组里
        *e=DS->data[DS->top1];   //只是我们认为栈内已经没有该元素了
        DS->data[(DS->top1)--]=0;
    }else if(StackNumber==2)
            {
                if(DS->top2==MAXSIZE)
                {
                    return ERROR;
                }
                *e=DS->data[DS->top2++];
            }
    return OK;
}