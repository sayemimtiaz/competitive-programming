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
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 unsigned long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
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
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
}


int main()
{
    char str[300],e[300];
    i64 F[22],i,j,k,a,o,kase,kas=0,n,pr;
    F[0]=1;
    for(i=1;i<=20;i++)
      F[i]=i*F[i-1];
    scanf("%llu",&kase);
    while(kase--)
    {
     scanf("%s %llu",str,&o);
     bool flag[22]={0};
     n=strlen(str);
     a=0;
     for(i=0;i<n;i++)
     {
       for(j=1;j<=n;j++)
        if(!flag[j])
        {
          for(pr=1,k=1;k<j;k++) if(!flag[k]) pr++;
          a=(a+pr*F[n-i-1]);
          if(a>=o){ a-=F[n-i-1],e[j-1]=str[i],flag[j]=1;break;}
          a-=(pr*F[n-i-1]);
        }
     }
     e[i]='\0';
     printf("Case %llu: %s\n",++kas,e);
    }
    return 0;
}
