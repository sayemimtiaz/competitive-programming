//Tarzan's Algorithm

#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef vector <long>vi;
vi grap1[1000],grap2[1000];
struct S
{
  long node;
  long f;
}N[1000];
long tim;
bool vis[1000];
int cmp(const void *a,const void *b)
{
    S *x=(S*)a;
    S *y=(S*)b;
    return (y->f-x->f);
}
void dfs1(long cur)
{
     long i,next;
     tim++;
     vis[cur]=1;
     for(i=0;i<grap1[cur].size();i++)
     {
       next=grap1[cur][i];
       if(!vis[next])
         dfs1(next);
     }
     tim++;
     N[cur-1].f=tim;
}
void dfs2(long cur)
{
     long i,next;
     printf(" %ld",cur);
     vis[cur]=1;
     for(i=0;i<grap2[cur].size();i++)
     {
       next=grap2[cur][i];
       if(!vis[next])
         dfs2(next);
     }
}
int main()
{
    long i,n,e,a,b;
    while(scanf("%ld %ld",&n,&e)==2)
    {
        for(i=0;i<n;i++)
        {
           vis[i+1]=0;
           N[i].node=i+1;
        }
        while(e--)
        {
          scanf("%ld %ld",&a,&b);
          grap1[a].push_back(b);
          grap2[b].push_back(a);
        }
        tim=0;
        for(i=1;i<=n;i++)
         if(!vis[i])
          dfs1(i);
        qsort(N,n,sizeof(S),cmp);
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
           if(!vis[N[i-1].node])
           { dfs2(N[i-1].node);
             printf("\n");
           }
        }
        for(i=1;i<=n;i++)
        { grap1[i].clear();grap2[i].clear();}
                         
    }
    return 0;
}
