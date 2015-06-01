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

int P[100009],S[10009];
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
    int M,N,i,j,a;
    while(scanf("%d %d",&M,&N)&&(M||N))
    {
      for(i=1;i<=M;i++)
      {
        scanf("%d",&a);
        P[1]=a;P[0]=0;
        for(j=2;j<=N;j++)
        {
            scanf("%d",&a);
            if(P[j-1]>P[j-2]+a)
               P[j]=P[j-1];
            else
               P[j]=P[j-2]+a;
        } 
        S[i]=P[N];             
      }
        P[1]=S[1];P[0]=0;
        for(j=2;j<=M;j++)
        {
            if(P[j-1]>P[j-2]+S[j])
               P[j]=P[j-1];
            else
               P[j]=P[j-2]+S[j];
        } 
        printf("%d\n",P[M]);
    }
    return 0;
}
