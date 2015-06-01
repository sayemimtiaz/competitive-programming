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
    int kase,n,kas=1,mile,juice;
    double a;
    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%d",&n); 
        mile=juice=0;
        while(n--)
        {
            scanf("%lf",&a);
            mile+=((floor(a/(double)30.00)+1)*10);
            juice+=((floor(a/(double)60.00)+1)*15);
        }
        printf("Case %d: ",kas++);
        if(mile<juice)
         printf("Mile %d\n",mile);
        else if(mile>juice)
         printf("Juice %d\n",juice);
        else
         printf("Mile Juice %d\n",mile);
    }
    return 0;
}
