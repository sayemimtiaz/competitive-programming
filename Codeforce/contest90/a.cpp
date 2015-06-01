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
int gcd(int a,int b)
{
    if(b==0)
     return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b,c,d;
    bool turn;
    while(~scanf("%d %d %d",&a,&b,&c))
    {
      turn=1;
      while(1)
      {
       if(turn)
       {
         turn=0;
         d=gcd(a,c);
         if(d>c){
          printf("1\n");break;}
         c-=d;
       }
       else
       {
              turn=1;
         d=gcd(b,c);
         if(d>c){
          printf("0\n");break;}
         c-=d;
       }
      }
    }
    return 0;
}
