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
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

struct Node
{
  int nn;
  int d;
}N[5009];

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

qi q;
vi adj[10009];
bool vis[10009];
int n;

inline int MAX(int a,int b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

bool cmp(Node a,Node b)
{
  return a.d<b.d;
}
inline void init()
{
  for(int i=1;i<=n;i++)
   N[i].nn=i,N[i].d=0,vis[i]=0;
}

void bfs()
{
  int u,v,i;
  while(!q.empty())
  {
    u=q.front();
    q.pop();
    for(i=adj[u].size()-1;i>=0;i--)
    {
      v=adj[u][i];
      if(!vis[v])
        vis[v]=1,N[v].d=N[u].d+1,q.push(v);
    }
  }
}
inline void call(int a)
{
      init();
      q.push(a);
      vis[a]=1;
      N[a].d=0;
      bfs();
      sort(N+1,N+n+1,cmp);
}
int main()
{
    int i,K,k,T[20009],O[20009],j,a,max,C[20009];
    while(~scanf("%d",&n))
    {
      for(i=1;i<=n;i++)
      {
        scanf("%d",&K);
        while(K--)
        {
          scanf("%d",&a);
          adj[i].pb(a);
        }
      }
     call(a);
     call(N[n].nn);
     max=N[n].d;
     k=2;
     O[1]=N[n].nn;
     C[N[n].nn]=N[n].d;
     for(i=n-1;i>=1;i--)
      {if(max==N[i].d)
      O[k++]=N[i].nn;
      C[N[i].nn]=N[i].d;
      }

     call(N[n].nn);
     max=N[n].d;
     O[k++]=N[n].nn;
     for(i=n-1;i>=1;i--)
      if(max!=N[i].d)
       break;
      else
      O[k++]=N[i].nn;
      
      a=1;
      max=INT_MX;
      for(i=1;i<=n;i++)
       if(abs(C[N[i].nn]-N[i].d)<=1)
       {
        if(MAX(C[N[i].nn],N[i].d)<max)
        {
        max=MAX(C[N[i].nn],N[i].d);a=1;
        T[a++]=N[i].nn;
        }
      else if(MAX(C[N[i].nn],N[i].d)==max){
        T[a++]=N[i].nn;}
        }
         
      sort(T+1,T+a);
      sort(O+1,O+k);
      
      printf("Best Roots  :");
      printf(" %d",T[1]);
      for(i=2;i<a;i++)
       if(T[i]!=T[i-1])
       printf(" %d",T[i]);
       printf("\n");
      
       printf("Worst Roots : ");
       printf("%d",O[1]);
      for(i=2;i<k;i++)
         if(O[i]!=O[i-1])
          printf(" %d",O[i]);
      printf("\n");
      
      for(i=1;i<=n;i++)
       adj[i].clear();  
    }
    return 0;
}
