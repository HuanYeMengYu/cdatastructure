#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 10
#define MAXK 1e9//e几代表10的几次幂，e前面的为系数，默认是1不能省略

double myfunction1(int n,double a[],double x);
double myfunction2(int n,double a[],double x);

int main()
{
double a[MAXN];
for(int i=0;i<MAXN;i++)
{a[i]=(double)i;}
clock_t start1,end1,start2,end2;      //clock_t为clock()函数的返回类型，返回值为程序运行到clock函数调用时经过的时间
printf("%d\n",CLK_TCK);   //CLK_TCK为常数，代表该机器每秒的打点数
double time1,time2;
start1=clock();
for(int j=0;j<MAXK;j++){myfunction1(MAXN-1,a,1.1);}  //程序执行1e7次，防止时间过短检测不到
end1=clock();
start2=clock();
for(int k=0;k<MAXK;k++)
{myfunction2(MAXN-1,a,1.1);}
end2=clock();
time1=((double)(end1-start1))/CLK_TCK;//计算出time的单位为秒
time2=((double)(end2-start2))/CLK_TCK;
printf("%lld\n",(end1-start1)/MAXK);
printf("%lf\n",time1);
printf("%lld\n",(end2-start2)/MAXK);
printf("%lf\n",time2);
    return 0;
}

double myfunction1(int n,double a[],double x){
double p=a[0];
for(int i=1;i<=n;i++)
{
    p+=a[i]*pow(x,i);
}
return p;
}

double myfunction2(int n,double a[],double x){
double p=a[n];
for(int i=n-1;i>=0;i--)
{
p+=a[i]*pow(x,i);
}
return p;
}
//发现第一种算法比第二种慢