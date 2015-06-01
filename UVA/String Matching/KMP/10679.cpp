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
#define i64 long long
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
int F[1200];
char T[100999];

void FailureFun(char *P,int m)
{
  int i,j;
  F[0]=0;
  i=1;
  j=0;
  while(i<m)
  {
    if(P[i]==P[j])
     F[i]=j+1,i++,j++;
    else if(j>0)
     j=F[j-1];
    else
     F[i]=0,i++;
  }
}
int KMP(char *P,int m)
{
    int i,j;
    int n=strlen(T);
    i=j=0;
    while(i<n)
    {
      if(T[i]==P[j]){
       if(j==m-1)
        return (i-j);
       i++,j++;
       }
      else if(j>0)
       j=F[j-1];
      else
       i++;
    }
    return -1;
}
int main()
{
    char P[1200];
    int pos,kase,n;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
      gets(T);
      scanf("%d",&n);
      getchar();
      while(n--){
      gets(P);
      int m=strlen(P);
      FailureFun(P,m);
      int pos=KMP(P,m);
      if(pos!=-1)
       printf("y\n");
      else
       printf("n\n");
       }
    }
    return 0;
}
