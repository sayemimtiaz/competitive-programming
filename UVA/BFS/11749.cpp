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
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 1000009
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))

struct Point
{
  dle x,y;
};
struct Edge
{
  int u,v,c;
}E[SIZE];

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

qi q;
vi adj[550];
bool vis[550];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
inline dle dis(Point a,Point b)
{
  //Without sqrt()
  return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int bfs(int start)
{
	int i,next,u,cnt=0;
	vis[start]=0;
	q.push(start);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		cnt++;
		for(i=adj[u].size()-1;i>=0;i--)
		{
			next=adj[u][i];
			if(vis[next])
				q.push(next),vis[next]=0;
		}
	}
	return cnt;;
}
int main()
{
    int n,m,i,j,cnt,max;
    while(scanf("%d %d",&n,&m)&&(n||m))
    {
      scanf("%d %d %d",&E[0].u,&E[0].v,&E[0].c);
      max=E[0].c;
      for(i=1;i<m;i++){
       scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].c);
       if(E[i].c>max)
        max=E[i].c;
       }
       for(i=0;i<m;i++)
        if(E[i].c==max){
         adj[E[i].u].pb(E[i].v),adj[E[i].v].pb(E[i].u);
         vis[E[i].u]=vis[E[i].v]=1;
         }
        max=0;
       for(i=1;i<=n;i++)
        if(vis[i]){
         cnt=bfs(i);
         if(cnt>max)
          max=cnt;
          }
        printf("%d\n",max);
        for(i=1;i<=n;i++)
         adj[i].clear();
        mems(vis);
    }
    return 0;
}
