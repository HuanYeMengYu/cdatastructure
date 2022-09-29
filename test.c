#include <stdio.h>

int main()
{
    int a[4] = { 1, 2, 3, 4 };
    int *ptr1 = (int *)(&a + 1);
    int *ptr2 = (int *)((int)a + 4);
    printf("%d\n",ptr1[-1]);
    printf("%d",*ptr2);
    return 0;
}
 //系统开发、机器学习、机器人