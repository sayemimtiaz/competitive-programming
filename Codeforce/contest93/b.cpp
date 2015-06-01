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

int main()
{
    int n,cnt,a[1000],i,j;
    while(scanf("%d",&n)==1)
    {
      rep(i,0,n-1)
       scanf("%d",&a[i]);
      sort(a,a+n);
      cnt=0;
      bool t[200]={0};
      for(i=0;i<n-1;i++)
       if(!t[i]&&!t[i+1]&&a[i]==a[i+1])
       {
         t[i]=t[i+1]=1;
        for(j=0;j<n-1;j++)
        if(!t[j]&&!t[j+1]&&a[j]==a[j+1])
        {t[i]=t[i+1]=t[j]=t[j+1]=1;cnt++;break;}
        if(j==n)
        t[i]=t[i+1]=0;
        }
       printf("%d\n",cnt);
    }
    return 0;
}
