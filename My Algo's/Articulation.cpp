//Finding Articulation point

#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
#define INF 200000000
typedef vector <long>vi;
vi grap[1000];
long tim,d[1000],sor,low[1000],par[1000],A,art[1000],cnt;
bool vis[1000],found[1000];
void dfs(long cur)
{
     long i,next;
     tim++;
     d[cur]=tim;
     vis[cur]=1;
     for(i=0;i<grap[cur].size();i++)
     {
       next=grap[cur][i];
       if(!vis[next])
       {
         dfs(next);
         if(low[next]>=d[cur]&&!found[cur]&&cur!=sor)
         {
            art[A++]=cur;
            found[cur]=1;
         }
         if(cur==sor)
          cnt++;
         if(low[next]<low[cur])
          low[cur]=low[next];
       }
        else if(d[next]<low[cur])
          low[cur]=d[next];
     }
     tim++;
}
int main()
{
    long i,n,e,a,b;
    while(scanf("%ld %ld",&n,&e)==2)
    {
        for(i=0;i<n;i++)
        {found[i]=vis[i]=0;low[i]=INF;}
        while(e--)
        {
          scanf("%ld %ld",&a,&b);
          grap[a].push_back(b);
          grap[b].push_back(a);
        }
        tim=A=cnt=0;
        for(i=0;i<n;i++)
         if(!vis[i])
         {
          sor=i;cnt=0;
          dfs(i); 
          if(cnt>1)
           {art[A++]=sor;}
          }
        for(i=0;i<A;i++)
         printf(" %ld",art[i]);
         printf("\n");
        for(i=0;i<n;i++)
        {grap[i].clear();}
                         
    }
    return 0;
}
