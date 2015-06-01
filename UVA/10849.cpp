#include<stdio.h>
int main()
{
    long long kase,Q,N,r1,r2,c1,c2;
    scanf("%lld",&kase);
    while(kase--)
    {
      scanf("%lld %lld",&Q,&N);
      while(Q--)
      {
         scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);
         if((r1+c1)%2!=(r2+c2)%2)
          printf("no move\n");
         else if(r1==r2&&c1==c2)
          printf("0\n");
         else if(((r1+c1)==(r2+c2))||((r1-c1)==(r2-c2)))
          printf("1\n");
         else
          printf("2\n");
      }
                
    }
    return 0;
}
