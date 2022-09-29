#include <stdio.h>

#define MAXSIZE 20          //线性表的顺序存储结构（利用数组构造的）,构造一个线性表
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;//线性表当前长度
}SqList;

#define OK 1
#define ERROR 0

int GetElem(SqList *L,int i,ElemType *e);  //获得元素的操作
int ListInsert(SqList *L,int i,ElemType e);  //插入操作(包括在末尾添加)
int ListDelete(SqList *L,int i,ElemType *e);  //删除元素操作

int main()
{
SqList L;
L.length=10;
for(int i=0;i<10;i++)
{
L.data[i]=i+1;
}
int a=5;
ElemType *e=&a;
GetElem(&L,5,e);
printf("%d\n",*e);
ListInsert(&L,2,999);
for(int j=0;j<L.length;j++)
{
printf("%d ",L.data[j]);
}
printf("\n");
ListDelete(&L,2,e);
printf("%d\n",*e);
for(int m=0;m<L.length;m++)
{
printf("%d ",L.data[m]);
}
printf("\n");
    return 0;
}

int GetElem(SqList *L,int i,ElemType *e)        //获得元素的操作
{
    if(L->length==0||i<1||i>L->length)   //算法的健壮性
    {
        return ERROR;
    }
    *e=L->data[i-1];  //用指针来获得取出的结果，而函数返回值用来表示函数状态
    return OK;
}

int ListInsert(SqList *L,int i,ElemType e)  //插入操作(包括在末尾添加)
{
if(L->length==MAXSIZE||i<1||i>L->length+1)  //算法的健壮性
{
    return ERROR;
}
if(i<=L->length)   //若插入位置非末尾，则需进行移位操作
{
    for(int k=L->length-1;k>=i-1;k--)      //后面的元素全部向后移一位
    {
        L->data[k+1]=L->data[k];
    }
}
L->data[i-1]=e;   //将新元素插入
L->length++;
return OK;
}

int ListDelete(SqList *L,int i,ElemType *e){     //删除元素操作
if (L->length==0||i<1||i>L->length)           //算法的健壮性
{
return ERROR;
}
*e=L->data[i-1];
if(i<L->length)                    //若删除元素非末尾，则进行移位操作
{
    for(int k=i;k<L->length;k++)
    {
        L->data[k-1]=L->data[k];  //移位
    }
}
L->length--;      //线性表长度缩短，实际上数组里线性表末尾多出来一位之前末尾的值仍然存在，
return OK;          //只是我们认为长度-1了，线性表就删掉了一位
}

