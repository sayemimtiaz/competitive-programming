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

int M[28][353],P[353][28][353];

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
    int L,S,l,s,w,t,r,kas=1,a;
    while(scanf("%d %d",&L,&S)&&(L||S))
    {
      printf("Case %d: ",kas++);
      if(S<L||L>26||S>351||(S/L)>26)
      {printf("0\n");continue;}
      for(s=1;s<=26;s++)
       M[1][s]=1,P[s][1][s]=1;
       
      for(l=2;l<=L;l++)
       for(s=l+1;s<=S;s++){a=s/l;
       for(w=1;w<27&&w<=a;w++){
        if(s-w>w)
          M[l][s]+=(M[l-1][s-w]-P[w][l-1][s-w]);
          P[w][l][s]=M[l][s];
          } 
       }
       printf("%d\n",M[L][S]);
      for(l=0;l<=26;l++)
       for(s=0;s<=351;s++)
         M[l][s]=0;
    }
    return 0;
}
