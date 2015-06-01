#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 10010
#define MININT -2147483647
vector<pair<long,long> >adj[MAXN];
long dis[MAXN],par[MAXN];
void dijkstra(long src)
{
     long i,u;
     priority_queue<pair<long,long> >pq;
     pair<long,long>nodotmp,next;
     for(i=1;i<MAXN;i++)
     {
       par[i]=i;
       dis[i]=MININT;
     }
     dis[src]=0;
     pq.push(make_pair(0,src));
     while(!pq.empty())
     {
       nodotmp=pq.top();
       pq.pop();
       u=nodotmp.second;
         for(i=adj[u].size()-1;i>=0;i--)
         {
           next=adj[u][i];
           if(par[u]!=next.first&&dis[next.first]<dis[u]+next.second)
           {
             dis[next.first]=dis[u]+next.second;
             par[next.first]=u;
             pq.push(make_pair(dis[next.first],next.first));
           }
         }
     }
}
int main()
{
    char str[1000];
    long a,b,c,i;
    while(gets(str))
    {
      if(str[0]=='\0')
      {printf("0\n");continue;}
      do
      {
        sscanf(str,"%ld %ld %ld",&a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
      }while(gets(str)&&str[0]!='\0');
      dijkstra(1);
      a=dis[1];b=1;
      for(i=2;i<MAXN;i++)
      if(dis[i]!=MININT&&dis[i]>a)
      {
        a=dis[i];
        b=i;
      }
      dijkstra(b);
      a=MININT;
      for(i=1;i<MAXN;i++)
      if(dis[i]!=MININT&&dis[i]>a)
        a=dis[i];
      printf("%ld\n",a);
      for(i=1;i<MAXN;i++)
       adj[i].clear();
    }
    return 0;
}
