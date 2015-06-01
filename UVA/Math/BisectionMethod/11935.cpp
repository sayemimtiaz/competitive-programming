#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
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
#define eps 1e-9
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



inline dle MAX(dle a,dle b)
{
  return (a-b>eps)?a:b;
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
    char str[100],*pch;
    double d,cd,pd,c,l,scl,high;
    
    while(gets(str))
    {
      if(str[0]=='0'&&str[2]=='F'&&str[7]=='c'&&str[19]=='0'&&str[20]=='\0')
       break;
       pd=0;l=0;scl=0;high=0;c=0;
       do{
       pch=strtok(str," ");
       sscanf(pch,"%lf",&cd);
       pch=strtok(NULL," ");
      if(pch[0]=='F') 
      {
          pch=strtok(NULL," ");  
          pch=strtok(NULL," ");
             d=cd-pd;
          scl+=(d*((c/100.00)+l));
            sscanf(pch,"%lf",&c);
      }
      else
      {
          d=cd-pd;
          scl+=(d*((c/100.00)+l));
          if(pch[0]=='M')
           l=0;
          else if(pch[0]=='G')
           high=MAX(high,scl),scl=0;
          else if(pch[0]=='L')
           l++;
          
      }
    //  printf("%lf %lf\n",cd,c);
      if(pch[0]=='G'&&pch[1]=='o')
       break;
       pd=cd;
      }while(gets(str));
      printf("%0.3lf\n",high);
    }
    return 0;
}
