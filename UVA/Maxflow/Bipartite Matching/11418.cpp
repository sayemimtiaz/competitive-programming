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

int flow[60][60],path[60],S,D;
char store[28][28][1000];
vector<int>adj[60];

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
    queue<long>q;
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
           if(path[v]==-2&&flow[u][v])
           {
             q.push(v);
             path[v]=u;
           }
       }
       
    }
    return 0;
}

int maxflow()
{
    int cf,v,totalflow=0;
    while(cf=bfs())
    {
       totalflow+=cf;
      // printf("%d\n",cf);
       v=D;
       while(path[v]!=-1)
       {
           flow[path[v]][v]-=cf;
           flow[v][path[v]]+=cf;
        //   printf("%d ",v);
           v=path[v];
       }
      // printf("\n");
    }
    return totalflow;
    
}
int main()
{
    int kase,kas=1,i,j,k,l,v,n;
    char str[1000];
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      S=0,D=53;
      for(i=1;i<=n;i++)
      {
        adj[0].pb(i);
        flow[0][i]=1;
        scanf("%d",&k);
        for(j=0;j<k;j++)
        { 
          scanf("%s",str);
          str[0]=toupper(str[0]);
          if(str[0]-'A'+1>n)
           continue;
          for(l=1;str[l]!='\0';l++)
           str[l]=tolower(str[l]);
          strcpy(store[i][str[0]-'A'],str);
          adj[i].pb(n+str[0]-'A'+1),adj[n+1+str[0]-'A'].pb(i);
          flow[i][n+1+str[0]-'A']=1;
        }
      }
      for(j=1;j<=26;j++)
       adj[j+n].pb(D),flow[j+n][D]=1;
      maxflow();
     printf("Case #%d:\n",kas++);
      for(i=1;i<=26;i++)
       for(j=1;j<=n;j++)
       {
        if(flow[i+n][j]){
          printf("%s\n",store[j][i-1]);break;}
       }
       for(i=0;i<=D;i++){
        adj[i].clear();  
         for(j=0;j<=D;j++)        
          flow[i][j]=0;
          }       
    }
    return 0;
}
