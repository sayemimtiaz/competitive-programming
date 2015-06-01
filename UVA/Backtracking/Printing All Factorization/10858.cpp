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

int a[50];
int s[3000][50],k;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

void gen(int n,int h)
{
     int i,j;
     for(i=2;i*i<=n;i++)
      if(n%i==0&&a[h-1]<=i)
      {
        a[h]=i;
        gen(n/i,h+1);
      }
      if(h-1){
       a[h]=n;
       for(i=1;i<=h;i++)
        s[k][i]=a[i];
        s[k][i]=-1;
        k++;
      }
}
int main()
{
    int n,i,j;
    while(scanf("%d",&n)&&n)
    {
      k=0;a[0]=-2;
      gen(n,1);
      printf("%d\n",k);
      for(i=0;i<k;i++)
      { printf("%d",s[i][1]);
       for(j=2;s[i][j]!=-1;j++)
         printf(" %d",s[i][j]);
         printf("\n");
       }
      
    }
    return 0;
}
