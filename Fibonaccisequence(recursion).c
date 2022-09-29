#include <stdio.h>

int Fbi(int i);//斐波那契数列的递归函数

int main()
{
    int i;
    printf("递归显示斐波那契数列：\n");
    for(int i=0;i<40;i++)
    {
        printf("%d ",Fbi(i));
    }
    printf("\n");
    return 0;
}

int Fbi(int i)//斐波那契数列的递归函数
{
    if(i<2)
    {
        return i==0?0:1;
    }
    return Fbi(i-1)+Fbi(i-2);
}