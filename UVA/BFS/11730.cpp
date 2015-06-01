#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
long a[11]={2,3,5,7,11,13,17,19,23,29,31};
long adj[1000],d[1200],k,b;
queue <long> q;
bool vis[5000];
void fac(long t)
{
     bool found[50]={0};
     long i,cnt=0;
     k=0;
      for(i=0;i<11&&a[i]<=t;)
      {
        if(t%a[i]==0)
        {
         if(!found[a[i]])
         {found[a[i]]=1;adj[k++]=a[i];}
         t/=a[i];
         cnt++;
        }
        else
         i++;
      }
      if(t>1)
      {cnt++;
      adj[k++]=t;}
      if(cnt==1)
        k=0;
}
void bfs()
{
     long u,v,i;
     while(!q.empty())
     {
        u=q.front();q.pop();
        fac(u);
        for(i=0;i<k;i++)
        {
          v=u+adj[i];
          if(v<=b&&!vis[v])
          {vis[v]=1;q.push(v);d[v]=d[u]+1;}
        }
     }
}
int main()
{
    long s,t,i,kas=1,kase;
    scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%ld %ld",&s,&b);
      d[b]=-1;
      d[s]=0;
      vis[s]=1;
      q.push(s);
      bfs();
      printf("Case %ld: %ld\n",kas++,d[b]);
      memset(vis,0,sizeof(vis));
    }
    return 0;
}
