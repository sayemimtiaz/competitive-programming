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

int S,D,flow[40][40],path[40];
vector<int>adj[40];

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
       for(i=0;i<=D;i++)
       {
           
           if(path[i]==-2&&flow[u][i])
           {
             q.push(i);
             path[i]=u;
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
int pos(char *str)
{
    char store[8][5]={"XXL","XL",
      "L","M","S","XS"};
    for(int i=0;i<6;i++)
     if(!strcmp(store[i],str))
      return i+1;
}
int main()
{
    char s1[10],s2[10];
    int i,j,a,b,kase,N,M;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&N,&M);
      S=0,D=M+6+1;
      for(i=1;i<=M;i++)
      {
       flow[S][i]=1;
       scanf("%s %s",s1,s2);
       a=pos(s1),b=pos(s2);
       flow[i][M+a]=flow[i][M+b]=1;
      }
      for(i=1;i<=6;i++)
       flow[M+i][D]=N/6;
      
      if(maxflow()==M)
       printf("YES\n");
      else
       printf("NO\n");
      for(i=0;i<=D;i++){
       for(j=0;j<=D;j++)
        flow[i][j]=0;
        }
    }
    return 0;
}
