#include<stdio.h>
#define MIN(a,b) (a<b)?a:b
#define MAX_INT 2147483647
int cost[100];
inline int CostInBase(int n,int b)
{
  int i,C;
  i=0;
  C=0;
  while(n>=b)
  {
    C+=cost[n%b];
   // printf("%d",n%b);
    n/=b;
  }
  //printf("%d\n",n);
  C+=cost[n%b];
  //printf("Cost for base %d is %d\n",b,C);
  return C;
}
int main()
{
    bool flag=0;
    int kase,kas=1,i,q,n,mn,O[100];
    scanf("%d",&kase);
    while(kase--)
    {
       if(flag)
        printf("\n");
       else
       flag=1;
       for(i=0;i<36;i++)
        scanf("%d",&cost[i]);
       scanf("%d",&q);
       printf("Case %d:\n",kas++);
       while(q--)
       {
          scanf("%d",&n);
          mn=MAX_INT;
          for(i=2;i<=36;i++)
          {
            O[i]=CostInBase(n,i);
            mn=MIN(mn,O[i]);
          }
       printf("Cheapest base(s) for number %d:",n);
       for(i=2;i<=36;i++)
          if(O[i]==mn)
           printf(" %d",i);
         printf("\n");
       }          
    }
    return 0;
}
