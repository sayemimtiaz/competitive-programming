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
    int kase,kas=1,l1,l2;
    bool isStart=0;
    char a[1000],b[1000];
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%s %s",&a,&b);
      l1=strlen(a);
      l2=strlen(b);
      if(l1>l2)
      {
        printf("MMM BRAINS\n");
        continue;
        }
      if(l1<l2)
      {
        printf("NO BRAINS\n");
        continue;
        }
      if(strcmp(a,b)>=0)
       {
        printf("MMM BRAINS\n");
        continue;
        }
       else
       {
        printf("NO BRAINS\n");
        continue;
        }
       
      
    }
    return 0;
}
