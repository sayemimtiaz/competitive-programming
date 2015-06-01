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
int main()
{
    char cmnd[100];
    int n,top,bottom,west,east,temp,south,north;
    while(scanf("%d",&n)&&n)
    {
      top=1,bottom=6;
      north=2,south=5;
      west=3,east=4;
      while(n--)
      {  
        scanf("%s",cmnd);
        if(cmnd[0]=='n')
        {
          temp=bottom;
          bottom=north;
          north=top;
          top=south;
          south=temp;
        }
        else if(cmnd[0]=='s')
        {
          temp=bottom;
          bottom=south;
          south=top;
          top=north;
          north=temp;
        }
        else if(cmnd[0]=='w')
        {
          temp=bottom;
          bottom=west;
          west=top;
          top=east;
          east=temp;
        }
        else
        {
          temp=bottom;
          bottom=east;
          east=top;
          top=west;
          west=temp;
        }
      }
      printf("%d\n",top);
    }
    return 0;
}
