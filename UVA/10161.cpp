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

int main()
{
    int n,a,b,x,y;
    bool mov;
    while(scanf("%d",&n)&&n)
    {
      mov=1;
      a=1,x=1,y=1;
      b=1;
       if(b==n)printf("%d %d\n",x,y);
       else
       {
      while(1)
      {
        if(mov)
        {
          y++;
          b++;
          if(b==n){printf("%d %d\n",x,y);
            break;}
          b+=a;
          if(b>=n)
          {printf("%d %d\n",x+n-b+a,y);
            break;}
             x+=a;
          b+=a;
          if(b>=n)
          {printf("%d %d\n",x,y-n+b-a);
            break;}
           y-=a;
          mov=0;
        }
        else
        {
           x++;
            b++;
          if(b==n){printf("%d %d\n",x,y);
            break;}
           b+=a;
          if(b>=n)
          {printf("%d %d\n",x,y+n-b+a);
            break;}
          y+=a;
          b+=a;
          if(b>=n)
          {printf("%d %d\n",x-n+b-a,y);
            break;}
           x-=a;
           mov=1; 
        }
       // printf("%d %d %d\n",x,y,b);
        a++;
      }
      }
    }
    return 0;
}
