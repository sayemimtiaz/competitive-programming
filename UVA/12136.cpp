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
    int i,sh,sm,eh,em,ws,we,ms,me,kase,kas=1;
    scanf("%d",&kase);
    while(kase--)
    {
      bool mark[2500]={0};
      scanf("%d%*c%d %d%*c%d",&sh,&sm,&eh,&em);
      ws=sh*100+sm;
      we=eh*100+em;
      for(i=ws;i<=we;i++)
       mark[i]=1;
      scanf("%d%*c%d %d%*c%d",&sh,&sm,&eh,&em);
      ms=sh*100+sm;
      me=eh*100+em;
      printf("Case %d: ",kas++);
        for(i=ms;i<=me;i++)
         if(mark[i]){
       printf("Mrs Meeting\n");break;}
       if(i==me+1)
       printf("Hits Meeting\n");
    }
    return 0;
}
