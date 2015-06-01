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
#define i64 int
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))

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

char str[120][220];
int main()
{
    int kase,n,i,j,k,l,ma;
    bool flag;
    while(scanf("%d",&n)&&n)
    {
      rep(i,0,n-1)
       scanf("%s",str[i]);
      
      ma=0;flag=1;
      while(flag){
      rep(i,0,n-1){
       if(str[i][ma]=='\0')
          {flag=0;break;}
       rep(j,i+1,n-1)
       {
         if(str[i][ma]=='\0'||str[j][ma]=='\0')
          {flag=0;break;}
         for(l=0,k=ma;str[i][k]!='\0'&&str[j][k]!='\0';l++,k++)
          if(str[i][k]!=str[j][k])
           break;
         if(str[i][k]=='\0'&&str[j][k]=='\0'){
          flag=0;break;}
       }
       if(!flag)
        break;
        }
        if(!flag)
         break;
         ma++;
        }
       printf("%d\n",ma-1);
    }
    return 0;
}
