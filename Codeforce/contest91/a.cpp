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

bool isLuck(int n)
{
     int a;
  while(n)
  {
   a=n%10;
   if(a!=4&&a!=7)
    return false;
    n/=10;
  }
  return true;
}
int main()
{
    int a[1000],c,i,n;
    c=0;
    for(i=1;i<=1000;i++)
     if(isLuck(i))
      a[c++]=i;
    while(~scanf("%d",&n))
    {
                          bool flag=0;
      for(i=0;a[i]<=n&&i<c;i++)
       if(n%a[i]==0){
        printf("YES\n");flag=1;break;}
        if(!flag)
         printf("NO\n");
    }
    return 0;
}
