#include<cstdio>
#include<algorithm>
using namespace std;
struct Finalist
{
       int id;
       int point;
}F[120];
int P[120][120];
bool cmp(Finalist a,Finalist b)
{
     if(a.point!=b.point)
     return (a.point>b.point);
     return (a.id<b.id);
}
int main()
{
    int G,i,j,temp,K,S,Q;
    while(scanf("%d %d",&G,&Q)&&(G||Q))
    {
       for(i=1;i<=G;i++)
         for(j=1;j<=Q;j++)
         {
           scanf("%d",&temp);
           P[i][temp]=j;
         }
       scanf("%d",&S);
       while(S--)
       {
         for(i=1;i<=Q;i++)
        {
         F[i].id=i;
         F[i].point=0;
        }
         scanf("%d",&K);
         for(j=1;j<=K;j++)
         {
            scanf("%d",&temp);
            for(i=1;i<=G;i++)
            {
               F[P[i][j]].point+=temp;
               //printf("Points of %d who was %dth in Grand prix %d is now: %d\n",P[i][j],j,i,F[P[i][j]].point);
            }
         }
         sort(&F[1],F+Q+1,cmp);
         printf("%d",F[1].id);
         for(i=2;F[i-1].point==F[i].point&&i<=Q;i++)
          printf(" %d",F[i].id);
          printf("\n");
       }
    }
    return 0;
}
