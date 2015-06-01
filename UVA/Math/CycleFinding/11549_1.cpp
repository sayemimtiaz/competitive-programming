#include<stdio.h>
#include<math.h>

#define MAX(a,b) (a>b)?a:b

double sq(double a,double b)
{
       double c=a*a;
       double d=pow(10,b-1);
       long f=c/d;
       while(f>9)
       {
        c=floor(c/10);
        f=c/d;
       }
       return c;
}
int main()
{
    int kase;
    double b,max,n,k,tortoise,hare;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%lf %lf",&n,&k);
      tortoise=k;
      b=hare=sq(k,n);
      max=k;
     // printf("%lf %lf\n",tortoise,hare);
      while(tortoise!=hare)
      {
        tortoise=b;
        b=sq(hare,n);
        max=MAX(max,b);
        hare=sq(b,n);
        max=MAX(max,hare);
        b=sq(tortoise,n);
       // printf("%lf %lf\n",tortoise,hare);
        max=MAX(max,tortoise);
      }
      printf("%0.lf\n",max);
    }
    return 0;
}
