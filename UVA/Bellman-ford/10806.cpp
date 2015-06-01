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

int p[120][120],e;
int a[SIZE],b[SIZE],c[SIZE],n,d[SIZE],par[SIZE];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int bell()
{
    int i,j;
    for(i=1;i<=n;i++)
     d[i]=INT_MX,par[i]=-1;
     d[1]=0;
    for(i=0;i<n-1;i++)
     for(j=0;j<e;j++)
      if(c[j]!=INT_MX&&d[a[j]]!=INT_MX&&d[b[j]]>d[a[j]]+c[j])
      {
         d[b[j]]=d[a[j]]+c[j];
         par[b[j]]=a[j];
      }
}
int main()
{
    int i,c1,x;
    while(scanf("%d",&n)&&n)
    {
      scanf("%d",&e);
      e*=2;
      for(i=0;i<e;i++){
       scanf("%d %d %d",&a[i],&b[i],&c[i]);
       p[a[i]][b[i]]=i;
       i++;
       a[i]=b[i-1],b[i]=a[i-1],c[i]=c[i-1];
       p[a[i]][b[i]]=i;
       }
       bell();
       c1=d[n];
      // printf("%d\n",c1);
       x=n;
       while(par[x]!=-1)
       {
         c[p[par[x]][x]]=INT_MX;
         c[p[x][par[x]]]=-c[p[x][par[x]]];
         x=par[x];               
       }
       bell();
       if(c1==INT_MX||d[n]==INT_MX)
        printf("Back to jail\n");
       else
       printf("%d\n",c1+d[n]);
    }
    return 0;
}
