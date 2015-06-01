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

struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
map<int,int>m;

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
    int kase,max,n,cnt,a,i,lp;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      max=cnt=0;
      bool flag=0;
      for(i=1;i<=n;i++)
      {
        scanf("%d",&a);
        if(m.find(a)==m.end())
          m[a]=i,cnt++;
        else
        {
          lp=m[a];
          if(flag&&lp<i-cnt)
           cnt++;
          else  
           max=MAX(max,cnt),cnt=i-lp;
          m[a]=i;
          flag=1; 
        }
      }
        
       max=MAX(max,cnt);
       m.clear();
      printf("%d\n",max);
    }
    return 0;
}
