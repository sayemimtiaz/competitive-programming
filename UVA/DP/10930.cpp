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
int w[35000];
int main()
{
    int i,j,n,kas=0,sum,a[50];
    bool A;
    while(~scanf("%d",&n))
    {
      A=1;
      printf("Case #%d:",++kas);
     scanf("%d",&a[1]);
     printf(" %d",a[1]);
     sum=a[1];
     for(i=2;i<=n;i++)
     {
        scanf("%d",&a[i]);
        if(a[i]<=a[i-1])
         A=0;
        sum+=a[i];
        printf(" %d",a[i]);
     }
     printf("\n");
     if(!A)
     {printf("This is not an A-sequence.\n");continue;}
     for(i=1;i<=sum+2000;i++)
      w[i]=-1;
     w[0]=0;
     for(i=1;i<=n;i++)
      for(j=sum;j>=0;j--)
       if(w[j]!=-1)
        w[j+a[i]]=MAX(w[j+a[i]],w[j]+1);
     for(i=1;i<=n;i++)
      if(w[a[i]]>1)
      {A=0;break;}
           if(!A)
     {printf("This is not an A-sequence.\n");continue;}
     else
     printf("This is an A-sequence.\n");
    }
    return 0;
}
