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

struct SS
{
  int a[101][101];
}S,A;
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
    int x[]={1,-1,0,0};
    int y[]={0,0,1,-1};
    int i,j,k,l,c,d,N,R,C,K;
    
    while(scanf("%d %d %d %d",&N,&R,&C,&K)&&(N||R||C||K))
    {
      rep(i,1,R)
       rep(j,1,C)
        scanf("%d",&S.a[i][j]);
      rep(i,1,K)
      {
        A=S;
        rep(j,1,R)
         rep(k,1,C){
          rep(l,0,3)
          {
            c=j+x[l],d=k+y[l];
            if(c<1||d<1||c>R||d>C)
             continue;
            if(S.a[c][d]-S.a[j][k]==1||S.a[j][k]-S.a[c][d]==N-1)
             A.a[c][d]=S.a[j][k];
          }
         }
         S=A;
      }
       rep(i,1,R){
       printf("%d",S.a[i][1]);
       rep(j,2,C)
        printf(" %d",S.a[i][j]);
        printf("\n");
        }
    }
    return 0;
}
