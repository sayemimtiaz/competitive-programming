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
struct SS
{
int a,b,d;
}S[50009];

bool cmp(SS x,SS y)
{
 return x.a>y.a;
}
bool cmp1(SS x,SS y)
{
 return x.b>y.b;
}

int main()
{
    int kaes,n,k,i;
    while(scanf("%d %d",&n,&k)==2)
    {
      rep(i,0,n-1){
       scanf("%d %d",&S[i].a,&S[i].b);
       S[i].d=i+1;
       }
      sort(S,S+n,cmp);
      sort(S,S+k,cmp1);
      printf("%d\n",S[0].d);
    }
    return 0;
}
