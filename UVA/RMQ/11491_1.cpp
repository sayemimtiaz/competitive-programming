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
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100009
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a

int a[SIZE],s[SIZE][30],m[SIZE][30];
char num[SIZE];

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
    int n,i,j,x,y,mm,d;
    while(scanf("%d %d",&n,&mm)&&(n||mm))
    {
     scanf("%s",&num);
    for(i=0;i<n;i++)
     a[i]=num[i]-'0';
     
     for(i=0;i<n;i++)
      m[i][0]=a[i],s[i][0]=i;
     
    for(j=1;(1<<j)<=n;j++)
     for(i=0;i+(1<<j)-1<n;i++)
     {
       if(m[i][j-1]>=m[i+(1<<(j-1))][j-1])
       m[i][j]=m[i][j-1],s[i][j]=s[i][j-1];
       else
        m[i][j]=m[i+(1<<(j-1))][j-1],s[i][j]=s[i+(1<<(j-1))][j-1];
     }
       
    x=0;mm=n-mm;
    for(j=mm;j>0;j--)
    {
      y=n-j;
      d=log(y-x+1)/log(2);
      if(m[x][d]>=m[y-(1<<d)+1][d])
      {
         printf("%d",m[x][d]);
         x=s[x][d]+1;
      }
       else
       {
      printf("%d",m[y-(1<<d)+1][d]);
      x=s[y-(1<<d)+1][d]+1;
      }
    }
    printf("\n");
    }
    return 0;
}
