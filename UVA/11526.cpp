#include<stdio.h>
#include<math.h>
int main()
{
    long L,i,a,p,n,kase,cov;
    long long s;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld",&n);
       if(n<=0)
       {printf("0\n");continue;}
       s=n;L=sqrt(n);p=n;cov=1;
       for(i=2;i<=L;i++)
       {
           a=n/i;
           s+=((p-a)*(i-1));
           cov+=(p-a)+1;
           s+=a;
           p=a;
       }
       s+=((n-cov)*L);
       printf("%lld\n",s);
    }
    return 0;
}
