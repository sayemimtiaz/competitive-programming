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
#include<ctype.h>
#include<string>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define pb push_back
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
#define mems(x) memset(x,0,sizeof(x))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
vi adj[120];
qi q;

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


int main()
{
    int kase,n,m,i,a,b,g;
    while( scanf("%d %d",&n,&m)==2)
    {
      int d[120]={0};
      rep(i,1,m){
       scanf("%d %d",&a,&b);
       adj[a].pb(b),adj[b].pb(a);
       d[a]++,d[b]++;
      }
      g=0;
      while(1)
      {
        rep(i,1,n)
         if(d[i]==1){
          q.push(i);
          d[i]--;
          }
        if(q.empty())
         break;
        while(!q.empty()){
         a=q.front();q.pop();
         for(i=adj[a].size()-1;i>=0;i--)
          d[adj[a][i]]--;
          }
          g++;
      }
      printf("%d\n",g);
      rep(i,1,n)
       adj[i].clear();
    }
    return 0;
}
