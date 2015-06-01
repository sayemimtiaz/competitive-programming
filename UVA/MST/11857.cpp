#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1000000
struct S
{
  long a,b,w;
}H[SIZE];
long par[SIZE],rank[SIZE],n;
bool cmp(S x,S y)
{
     return (x.w<y.w);
}
void makeset()
{
     long i;
     for(i=0;i<n;i++)
     {
       rank[i]=0;
       par[i]=i;
     }
}
void link(long x,long y)
{
     if(rank[x]>rank[y])
      par[y]=x;
     else
     {
         par[x]=y;
         if(rank[x]==rank[y])
            rank[y]++;
     }
}
long find(long x)
{
     if(x!=par[x])
       par[x]=find(par[x]);
     return par[x]; 
}
int main()
{
    long u,v,i,max,added,m;
    while(scanf("%ld %ld",&n,&m)==2&&(n||m))
    {
      makeset();
      for(i=0;i<m;i++)
        scanf("%ld %ld %ld",&H[i].a,&H[i].b,&H[i].w);
      sort(H,H+m,cmp);
      added=0;
      max=-1;
      for(i=0;i<m&&added<n;i++)
      {
          u=find(H[i].a);v=find(H[i].b);
          if(u!=v)
          {
            if(H[i].w>max)
             max=H[i].w;
             link(u,v);
             added++;
          }            
      }
      added=0;
      for(i=0;i<n&&added<2;i++)
       if(i==par[i])
        added++;
      if(added==2)
       printf("IMPOSSIBLE\n");
      else
       printf("%ld\n",max);
    }
    return 0;
}
