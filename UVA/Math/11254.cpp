#include<stdio.h>
#include<math.h>
int main()
{
    long a,i,n;
    while(scanf("%ld",&n)==1&&n!=-1)
    {
        n=2*n;
        for(i=sqrt(n);i>=1;i--)
        {
          a=n+i-(i*i);
          if(a%(2*i)==0)
          {
            a/=(2*i);
            break;
          }
        }
        printf("%ld = %ld + ... + %ld\n",n/2,a,a+i-1);
    }
    return 0;
}
