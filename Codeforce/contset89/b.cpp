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
    
    int i,j,n,sp;
    while(scanf("%d",&n)==1)
    {
      sp=n*2;
      for(i=0;i<=n;i++)
      {
        for(j=0;j<sp;j++)
         printf(" ");
         printf("0");
        for(j=1;j<=i;j++)
         printf(" %d",j);
        for(j=i-1;j>=0;j--)
         printf(" %d",j);
         sp-=2;
        printf("\n");
      }
      sp=2;
      for(i=n-1;i>=0;i--)
      {
        
         for(j=0;j<sp;j++)
         printf(" ");
         printf("0");
        for(j=1;j<=i;j++)
         printf(" %d",j);
        for(j=i-1;j>=0;j--)
         printf(" %d",j);
         sp+=2;
        printf("\n");
      }
      
    }
    return 0;
}
