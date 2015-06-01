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
    double n,a,b,c,d;
    double i;
    while(scanf("%lf",&n)&&n)
    {
      bool minus=0;
      if(n<0){minus=1;
       n=-n;}
      a=log10(n);
      bool flag=0;
      double L=sqrt(n);
      for(i=2.00;i<=L;i++)
      {
        b=a/log10(i);
        // printf("%lf\n",ceil(b));
       // c=pow(i,floor(b));
       // d=pow(i,ceil(b));
       c=b-floor(b+eps);
        if(c>-eps&&c<eps&&(!minus||fmod(floor(b+eps),2)!=0))
        {flag=1;
         printf("%0.lf\n",b);
         break;}
      }
      if(!flag)
       printf("1\n");
    }
    return 0;
}
