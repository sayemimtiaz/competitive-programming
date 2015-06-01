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
inline int Clap(int i)
{
  if(i%7==0)
   return 1;
  while(i)
  {
    if(i%10==7)
     return 1;
    i/=10;
  }
  return 0;
}
int main()
{
    int m,n,k,clap,p;
    while(scanf("%d %d %d",&n,&m,&k)&&(n||m||k))
    {
      p=m+(2*(n-m));
      if(m==1||m==n)
       p=-1;
      clap=0;n=n+n-2;
      while(1)
      {
        clap+=Clap(m);
        if(clap==k){  printf("%d\n",m);
         break;}
         if(p!=-1){
          clap+=Clap(p);
        if(clap==k){  printf("%d\n",p);
         break;}
        p+=n;
        }
        m+=n;
      }
    
    }
    return 0;
}
