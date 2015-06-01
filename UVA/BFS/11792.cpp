#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
vector<long>adj[12000];
queue <long> q;
bool imp[12000];
double bfs(long src)
{
     long u,v,i,s;
     long d[12000];
     bool vis[12000]={0};
     d[src]=0;
     vis[src]=1;
     q.push(src);
     s=0;
     while(!q.empty())
     {
        u=q.front();q.pop();
        for(i=0;i<adj[u].size();i++)
        {
          v=adj[u][i];
          if(!vis[v])
          {
                     vis[v]=1;
                     q.push(v);
                     d[v]=d[u]+1;
                     if(imp[v])
                       s+=d[v];
          }
        }
     }
     return s;
}
int main()
{
    long i,j,a,b,kase,ST,LI,src[1000],res;
    long hold,min;
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld %ld",&ST,&LI);
      long deg[12000]={0};
      bool e[12000]={0};
      j=0;
      while(LI--)
      {
        scanf("%ld",&a);
        e[a]=1;
        while(a)
        {
        scanf("%ld",&b);
        if(!b)
         break;
         deg[a]++;
         deg[b]++;
         adj[a].push_back(b); 
         adj[b].push_back(a);
         a=b;
         }
         e[a]=1;
      }
      for(i=1;i<=ST;i++)
        if(deg[i])
        {
          if(deg[i]==2&&e[i])
           {imp[i]=1;src[j++]=i;}
          else if(deg[i]>2)
           {imp[i]=1;src[j++]=i;}
        }
      min=2000000000;
      for(i=0;i<j;i++)
      {
         hold=bfs(src[i]);
         if(hold<min)
         {
           min=hold;
           res=src[i];
         }
      }
      printf("Krochanska is in: %ld\n",res);
      for(i=0;i<=ST;i++)
      {imp[i]=0; adj[i].clear();}
    }
    return 0;
}
