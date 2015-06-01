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
#define eps 0.00000001

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
    long double F[]={1,1,2,6,24,120,720,5040,40320,362880};
    int kase,kas=1,i;
     long double p;
    bool isStart=0;
      printf("n e\n- -----------\n");
      printf("0 1\n");
      printf("1 2\n");
printf("2 2.5\n");

      p=2.50;
      for(i=3;i<=9;i++)
      {
          p+=(1.00/(long double)F[i]);
          printf("%d %.9Lf\n",i,p);             
      }
    //getchar();
    return 0;
}
