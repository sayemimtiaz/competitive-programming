#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct E
{
  long u,v;
  double cost;
}edge[1005000];
long par[1010],rank[1010],n;
int cmp(const void *a,const void *b)
{
    E *x=(E*)a;
    E *y=(E*) b;
    if(x->cost<y->cost)
      return -1;
    if(x->cost>y->cost)
      return 1;
    return 0;
}
void make_set()
{
     long i;
     for(i=1;i<=n;i++)
     {
        rank[i]=0;
        par[i]=i;
     }
}
void link(long a,long b)
{
     if(rank[a]>rank[b])
      par[b]=a;
     else
     {
         par[a]=b;
         if(rank[a]==rank[b])
          rank[b]++;
     }
}
long find(long a)
{
     if(a!=par[a])
      par[a]=find(par[a]);
     return par[a];
}
int main()
{
    long kase,kas=1,u,v,state,i,j,e;
    double r,a[1010],b[1010],road,rail;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld %lf",&n,&r);
       make_set();
       for(i=1;i<=n;i++)
        scanf("%lf %lf",&a[i],&b[i]);
       e=0;
       for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
           edge[e].u=i;edge[e].v=j;
           edge[e].cost=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
           e++;
        }
       qsort(edge,e,sizeof(E),cmp);
       j=0;road=rail=0;state=1;
       for(i=0;i<e;i++)
       {
          if(j==n-1)
           break;
          u=find(edge[i].u); v=find(edge[i].v);
          if(u!=v)
          {
             if(edge[i].cost<=r)
               road+=edge[i].cost;
             else
             { 
               state++;
               rail+=edge[i].cost;
             }
             link(u,v);
          }             
       }
       printf("Case #%ld: %ld %0.lf %0.lf\n",kas++,state,road,rail);
    }
    return 0;
}
