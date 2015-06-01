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

int H[100000];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
inline int Fun(int n)
{
  int s=0;
  while(n)
  {
    s+=(n%10)*(n%10);
    n/=10;
  }
  return s;
}
int main()
{
    int i,cnt,Hare,Tortoise,l,h;
    H[1]=1;
    for(i=2;i<=405;i++)
    {
      Tortoise=i;
      Hare=Fun(i);
      cnt=1;
      while(Hare!=Tortoise&&Tortoise!=1)
      {
        Tortoise=Fun(Tortoise);
        Hare=Fun(Fun(Hare));
        cnt++;
      }
      if(Tortoise!=1)
       cnt=0;
      H[i]=cnt;
    }
    for(i=406;i<=99999;i++)
    {
      H[i]=H[Fun(i)];
      if(H[i])
       H[i]++;
    }
    bool flag=0;
    while(scanf("%d %d",&l,&h)==2)
    {
      if(flag)
       printf("\n");
      else
       flag=1;
      
      for(i=l;i<=h;i++)
       if(H[i])
       printf("%d %d\n",i,H[i]);
    }
    return 0;
}
