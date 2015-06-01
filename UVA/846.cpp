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
i64 H[1000000];
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
    int i;
    i64 a;
    for(i=1;;i++)
    {
      a=i/2;
      H[i]=2*((a*(a+1))/2);
      if(H[i]>INT_MX)
       break;
      if(i%2)
       H[i]+=ceil(i/(double)2.00);
    }
    H[0]=-1;
    int kase,x,y,d,m,s,e;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&x,&y);
      if(x==y){
       printf("0\n");continue;}
      d=y-x;
      s=1,e=i-1;
      while(s<=e)
      {
        m=(s+e)/2;
        if(H[m]>=d&&H[m-1]<=d)
         break;
        if(H[m]<d)
         s=m+1;
        else
         e=m-1;
      }
      printf("%d\n",m);
    }
    return 0;
}
