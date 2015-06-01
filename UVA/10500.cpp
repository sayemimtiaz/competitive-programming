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

#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,0,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

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
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
}


int main()
{
    int xx[]={-1,+0,+1,+0};
    int yy[]={+0,+1,+0,-1};
    char B[12][12],M[12][12];
    bool V[12][12];
    int n,m,sx,sy,i,j,move,cx,cy,nx,ny,O;
    while(S2(n,m)&&(n||m))
    {
      S2(sx,sy);
      rep(i,1,n){
       getchar();
       rep(j,1,m){
        scanf("%c",&B[i][j]);
        if(B[i][j]==' ')j--;
        M[i][j]='?',V[i][j]=0;
        }
       }
        M[sx][sy]='0';move=0;V[sx][sy]=1;
        while(1)
        {
          bool flag=0;
          for(i=0;i<4;i++){
           nx=sx+xx[i],ny=sy+yy[i];
           if(nx<1||ny<1||nx>n||ny>m||V[nx][ny]) continue;
           if(B[nx][ny]=='X'){ M[nx][ny]='X';continue;}
            if(!flag) cx=nx,cy=ny,flag=1,move++,V[nx][ny]=1;
            M[nx][ny]='0';
           }
           if(!flag) break;
           sx=cx,sy=cy;
        }
        printf("\n");
        rep(i,1,n)
        {
         for(j=1;j<=m;j++)
           printf("|---");
         printf("|\n");
         rep(j,1,m)
          printf("| %c ",M[i][j]);
          printf("|\n");
         }
         for(j=1;j<=m;j++)
           printf("|---");
         printf("|\n\n");
         printf("NUMBER OF MOVEMENTS: %d\n",move);

    }
    return 0;
}
