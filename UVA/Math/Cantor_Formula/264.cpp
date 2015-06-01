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

int main()
{
    int h[5000],s,e,m,n,i;
    h[0]=0;
    for(i=1;i<=4775;i++)
     h[i]=i+h[i-1];
    while(~scanf("%d",&n))
    {
      s=1,e=4775;
      while(s<=e)
      {
        m=(s+e)/2;
        if(h[m-1]<n&&h[m]>=n)
         break;
        if(h[m]<n)
         s=m+1;
        else
         e=m-1;
         //printf("h[%d]=%d\n",m,h[m]);
      }
      if(m%2==0)
       printf("TERM %d IS %d/%d\n",n,m-h[m]+n,1+h[m]-n);
      else
        printf("TERM %d IS %d/%d\n",n,1+h[m]-n,m-h[m]+n);
    }
    return 0;
}
