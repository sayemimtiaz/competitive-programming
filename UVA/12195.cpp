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
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

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
    int V[1000];
    char str[1000];
    int i,r,cnt;
    
    V[int('W')]=128;
    V['H']=64;
    V['Q']=32;
    V['E']=16;
    V['S']=8;
    V['T']=4;
    V['X']=2;

    while(gets(str)&&str[0]!='*')
    {
      cnt=0;
      for(r=0,i=1;str[i]!='\0';i++)
      {
        if(str[i]=='/')
        {
         if(r==128)
          cnt++;
         r=0;
         continue;
        }
        r+=V[str[i]];                          
      }   
      printf("%d\n",cnt);                     
    }
    return 0;
}
