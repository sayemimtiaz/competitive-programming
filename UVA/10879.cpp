#include<stdio.h>
#include<math.h>
int main()
{
    long kase,kas=1,n,i,j;
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld",&n);
      printf("Case #%ld: %ld",kas++,n);
      j=0;
       for(i=2;j<2&&i<=sqrt(n);i++)
        if(n%i==0)
        {
            printf(" = %ld * %ld",i,(n/i));
            j++;
        }
       printf("\n");                      
    }
    return 0;
}
