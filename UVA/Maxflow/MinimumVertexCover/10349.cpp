#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
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

#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 int
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x,a) memset(x,a,sizeof(x))
#define swap(a,b) a^=b,b^=a,a^=b
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
typedef pair<int,int>pii;



inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b) {return (a>b)?b:a;}
inline dle dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
vi adj[500];
int D,path[500],flow[500][500];

int bfs()
{
    int i,u,v,cf,tf;
    queue<int>q;
    for(i=0;i<=D;i++)
     path[i]=-2;
    q.push(0);
    path[0]=-1;
    while(!q.empty())
    {
       u=q.front();
       q.pop();
       if(u==D)
       { 
         cf=INT_MX;
         v=D;
         while(path[v]!=-1)
         {
           cf=MIN(cf,flow[path[v]][v]);
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
       v=D;
       while(path[v]!=-1)
       {
           flow[path[v]][v]=0;
           flow[v][path[v]]=1;
           v=path[v];
       }
    }
    return totalflow;
    
}
int main()
{
    struct PP
    {
      int x,y;
    }WW[500],BB[500];
    int h,w,i,j,kase,a,b,B,W,S;
    char str[100];
    S1(kase);
    while(kase--)
    {
      S2(h,w);
      B=W=0;
      getchar();
      rep(i,1,h){
       gets(str);
       rep(j,1,w)
        {
         if(str[j-1]=='*')
         {
           a=i%2;b=j%2;
           if(a&&a==b) WW[++W].x=i,WW[W].y=j;
           else if(a&&!b) BB[++B].x=i,BB[B].y=j;
           else if(!a&&a==b) WW[++W].x=i,WW[W].y=j;
           else BB[++B].x=i,BB[B].y=j;
           
         }
       }
       }
       S=0;D=B+W+1;
       rep(i,1,W)
        adj[S].pb(i),flow[S][i]=1;
       rep(i,1,W)
        rep(j,1,B)
         if(abs(WW[i].x-BB[j].x)+abs(WW[i].y-BB[j].y)==1)
         {
           adj[i].pb(W+j);flow[i][W+j]=1;
           adj[W+j].pb(i);
         }
        rep(i,1,B)
        adj[i+W].pb(D),flow[i+W][D]=1;
        a=maxflow();b=D-2*a-1;
        printf("%d\n",a+b);
        rep(i,0,D)
         adj[i].clear();  
    }
    return 0;
}
