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

vi v,b;

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

void LIS()
{
     int sz=v.size();
     int s,e,m;
     
     vector<int>p(sz);
     b.pb(0);
     for(size_t i=1;i<sz;i++)
     {
        if(v[i]>v[b.back()]){
         p[i]=b.back();
         b.pb(i);
         continue;}
        for(s=0,e=b.size()-1;s<e;){
         m=(s+e)/2;
         if(v[b[m]]<v[i]) s=m+1; else e=m;}
        if(v[b[s]]>v[i]){
          if(s>0) p[i]=b[s-1];
          b[s]=i;}
     }
     sz=b.size();
     for(s=sz,e=b.back();s--;e=p[e]) b[s]=e;
     printf("%d\n-\n",sz);
     for(s=0;s<sz;s++)
      printf("%d\n",v[b[s]]);
}

int main()
{
    int a;
      while(~scanf("%d",&a))
        v.pb(a);
      LIS();
     // getchar();
    return 0;
}
