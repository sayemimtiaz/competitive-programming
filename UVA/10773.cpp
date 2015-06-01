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
#define eps 0.00000001

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
    int kase,kas=1,a,b,x,y,temp;
   long  double oc,d,u,v,od;
    bool isStart=0;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%Lf %Lf %Lf",&d,&v,&u);
       printf("Case %d: ",kas++);
        if(u>-eps&&u<eps)
       {
         printf("can't determine\n");
         continue;
       }
       od=(u*u)-(v*v);
       if(od<-eps)
       {
         printf("can't determine\n");
         continue;
       }
       od=sqrtl(od);
       if(od>-eps&&od<eps)
       {
         printf("can't determine\n");
         continue;
       }
       od=d/od;
       oc=d/u;
       oc=od-oc;
      if(oc>-eps&&oc<eps)
       {
         printf("can't determine\n");
         continue;
       }
       printf("%0.3Lf\n",oc);       
      
    }
    return 0;
}
