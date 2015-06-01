#include<stdio.h>
int main()
{
    long kase,i,n,m,t,temp,trip,R,a[9000],wait;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld %ld %ld",&n,&t,&m);
       for(i=1;i<=m;i++)
        scanf("%ld",&a[i]);
       temp=m%n;
       if(!temp)
        temp=n;
       R=a[temp]+(2*t);
       trip=1+((m-temp)/n);
       for(i=2;i<=trip;i++)
       {
         if(a[temp+n]>R)
          R+=(a[temp+n]-R)+(2*t);
         else
          R+=(2*t);
         temp+=n;
       }
       printf("%ld %ld\n",R-t,trip);
    }
    return 0;
}
