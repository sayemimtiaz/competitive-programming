#include<stdio.h>
long d[1000];
long gcd(long a,long b)
{
     if(b==0)
       return a;
     return gcd(b,a%b);
     
}
long other(long n)
{
     long i,s=0;
     for(i=1;i<n;i++)
      s+=gcd(i,n);
      return s;
}
int main()
{
    long i,n;
    d[1]=0;
    for(i=2;i<=500;i++)
     d[i]=d[i-1]+other(i);
     while(scanf("%ld",&n)==1&&n)
     {
       printf("%ld\n",d[n]);
     }
    return 0;
}
