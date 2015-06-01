#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<cctype>
#include<string>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define pb push_back
#define mem(x) memset(x,sizeof(x),0)
#define PI acos(-1.0)
#define INF 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

vi adj[800],grap[105];
vector<pair<int,int> >edg[1005];
si s;
int n,e,S,D,flow[800][800],path[800];
bool taken[105][1005];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int bfs()
{
    int i,u,v,cf,tf;
    qi q;
    for(i=0;i<=D;i++)
     path[i]=-2;
    q.push(S);
    path[S]=-1;
    while(!q.empty())
    {
       u=q.front();
       q.pop();
       if(u==D)
       { 
         cf=INF;
         v=D;
         while(path[v]!=-1)
         {
           cf=MIN(cf,flow[path[v]][v]);
          // printf("Edge %ld %ld costs %ld\n",path[v],v,flow[path[v]][v]);
           v=path[v];
         }
         while(!q.empty())
          q.pop();
         return cf;
       }
       for(i=adj[u].size()-1;i>=0;i--)
       {
           v=adj[u][i];
        //    printf("%d\n",flow[u][v]);
           if(path[v]==-2&&flow[u][v])
           {
             q.push(v);
             path[v]=u;
           }
       }
       
    }
    return 0;
}

void maxflow()
{
    int cf,v,i,j,totalflow=0;
    pair<int,int>next;
    while(cf=bfs())
    {
       totalflow+=cf;
        v=D;
       while(path[v]!=-1)
       {
           flow[path[v]][v]-=cf;
           flow[v][path[v]]+=cf;
        //   printf("%d ",v);
           v=path[v];
       }
    //   printf("\n");
    }
    for(i=1;i<=e;i++)
    {
      for(j=1;j<=n;j++)
      {
        if(flow[j+e][i])
        {
          next=edg[i][0];
          if(j==next.first)
           grap[next.second].pb(j);
          else
            grap[next.first].pb(j);
        }
      }               
    }
}
void reset_()
{
     int i;
     for(i=0;i<=D;i++)
        adj[i].clear();
      while(!s.empty())
        s.pop();
      for(i=1;i<=e;i++)
       edg[i].clear();
      memset(taken,0,sizeof(taken));
       memset(flow,0,sizeof(flow));
      for(i=1;i<=n;i++)
      grap[i].clear(); 
}
void dfs(int u)
{
  int i,v;  
  for(i=grap[u].size()-1;i>=0;i--)
  {
    v=grap[u][i];
    if(!taken[u][i])
    {
     taken[u][i]=1;
     dfs(v);
    }
  }
  s.push(u);
}

int main()
{
    int v,kase,i,a,b,j;
    bool flag,isStart=0;
    char ch;
    scanf("%d",&kase);
    while(kase--)
    {
     scanf("%d %d",&n,&e);
     S=0,D=n+e+1;
     int degree[105]={0};
     for(i=1;i<=e;i++)
     {
       adj[S].pb(i);
       flow[S][i]=1;
       scanf("%d %d %c",&a,&b,&ch);
       degree[a]++,degree[b]++;
       edg[i].pb(make_pair(a,b));
       adj[i].pb(b+e),adj[b+e].pb(i);;
       flow[i][b+e]=1;
       if(ch=='U')
        adj[i].pb(a+e),adj[a+e].pb(i),flow[i][a+e]=1;
     }
     for(i=1;i<=n;i++)
      adj[i+e].pb(D),flow[i+e][D]=degree[i]/2;
       maxflow();
      if(isStart)
        printf("\n");
      else
        isStart=1;
      dfs(a);
      if(s.size()==e+1)
      {
          a=s.top();s.pop();
           printf("%d",a);
        while(!s.empty())
        {
           a=s.top();s.pop();
           printf(" %d",a);
        }
        printf("\n");
      }
      else
       printf("No euler circuit exist\n");
       
    reset_();
    }
    return 0;
}
