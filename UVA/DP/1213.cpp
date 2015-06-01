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

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

bool prime[SIZE];
int a[200],c;
int m[1300][16],s[190][1300][16];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

void sieve(int n)
{
     int i,j;
     int m=sqrt(n);
     a[1]=2,c=2;
     for(i=3;i<=n;i+=2)
      if(!prime[i])
      {
        a[c++]=i;
        if(i<=m)
         for(j=i*i;j<=n;j+=2*i)
          prime[j]=1;
      }
      
     
}

int main()
{
    sieve(1128);
    int n,k,i,j,l;
    while(scanf("%d %d",&n,&k)&&(n||k))
    {
      for(i=1;a[i]<=n;i++)
       m[a[i]][1]=1,s[i][a[i]][1]=1;
       
      for(i=1;i<=n;i++)
      {
        for(j=1;a[j]<=i;j++)
        {
          for(l=2;l<=k;l++)
          {
            if(i-a[j]>a[j]&&m[i-a[j]][l-1])
            {
            m[i][l]+=(m[i-a[j]][l-1]-s[j][i-a[j]][l-1]);
           // printf("m[%d][%d]=%d start with %d\n",i,l,m[i][l],a[j]); 
            }
             s[j][i][l]=m[i][l];
          }              
        }
      }
      printf("%d\n",m[n][k]);
      for(i=1;i<=n;i++)
       for(j=1;j<=k;j++)
        m[i][j]=0;
    }
    return 0;
}
