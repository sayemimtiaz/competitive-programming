#include<stdio.h>
#include<math.h>
long d[30000];
int main()
{
    long i,j,a,s,kase,n;
    d[0]=0;
    d[1]=1;
    for(i=2;i<=10000;i++)
    {
      s=sqrt(i);
      a=i-s*s;
      d[i]=d[a]+1;
        for(j=s-1;j>=1;j--)
        {
          a=i-j*j;
          if(d[i]>(d[a]+1))
            d[i]=d[a]+1;
        }
    }
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld",&a);
       printf("%ld\n",d[a]);
    }
    return 0;
}
