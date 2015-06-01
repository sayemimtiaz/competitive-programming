#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long a[100009];
int main()
{
    long n,i,m1,m2,tt;
    double res;
    while(scanf("%ld",&n)&&n)
    {
      for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
      res=0;
      for(i=1;i<n;i++)
      {
         m1=labs(a[i]);m2=labs(a[i-1]);
        if((a[i-1]<0&&a[i]<0)||(a[i-1]>=0&&a[i]>=0))
         a[i]=a[i]+a[i-1];
        else
        {
         tt=a[i];
         a[i]=labs(m1-m2);
         if((m1>m2&&tt<0)||(m1<m2&&a[i-1]<0))
          a[i]=-a[i];
         }
        res+=m2;
      }
      printf("%0.lf\n",res);
    }
    return 0;
}
