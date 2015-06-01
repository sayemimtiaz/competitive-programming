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
int C[1002][1002];

inline i64 MAX(int a,int b)
{
  return (a>b)?a:b;
}
inline i64 MIN(int a,int b)
{
  return (a>b)?b:a;
}
inline dle dis(Point a,Point b)
{
  //Without sqrt()
  return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
   char str[5000],x[5000],y[5000];
   int m,n,i,j;
   int RR;
    while(gets(str))
    {
      sscanf(str,"%d %s",&m,x);
      gets(str);
      sscanf(str,"%d %s",&n,y);
      //Insertion
      C[0][0]=0;
      rep(i,1,n)
       C[0][i]=1+C[0][i-1];
      //Deletion
      rep(i,1,m)
       C[i][0]=1+C[i-1][0];
       
       rep(i,1,m)
        rep(j,1,n){
         if(x[i-1]==y[j-1])RR=0;else RR=1;
         C[i][j]=MIN(1+C[i][j-1],MIN(1+C[i-1][j],RR+C[i-1][j-1]));
         //printf("%d %d %d\n",1+C[i-1][j],1+C[i][j-1],C[i-1][j-1]+RR);
         }
         printf("%d\n",C[m][n]);
    }
    return 0;
}
