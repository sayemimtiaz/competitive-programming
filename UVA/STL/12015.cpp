#include<cstdio>
#include<algorithm>
using namespace std;
struct S
{
   char str[150];
   long v;
}H[100];
bool cmp(S a,S b)
{
     //Use < to sort in increasing order
     return a.v>b.v;
}
int main()
{
    long kase,i,kas=1;
    scanf("%ld",&kase);
    while(kase--)
    {
      for(i=0;i<10;i++)
       scanf("%s %ld",H[i].str,&H[i].v);
       stable_sort(H,H+10,cmp);
       printf("Case #%ld:\n%s\n",kas++,H[0].str);
       for(i=1;i<10&&H[i].v==H[0].v;i++)
        printf("%s\n",H[i].str);
    }
    return 0;
}
