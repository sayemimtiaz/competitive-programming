#include<stdio.h>

int main()
{
    int kase,d,b,n,i;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&d,&b);
      b--;n=1;i=1;
      while(i<d)
      {
        if(b%2){
         n=2*n+1;
         b/=2;
         }
        else
        { n=2*n;
         if(b%2==0)
          b/=2;
         else
          b=(b/2)+1;
        }
        i++;
      }
      printf("%d\n",n);
    }
    scanf("%d",&n);
    return 0;
}
