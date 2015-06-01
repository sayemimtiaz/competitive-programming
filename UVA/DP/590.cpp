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
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

int G[20][20][35];
int D[20][20],N,K;
int memo[20][1005];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int dp(int city,int day)
{
    if(memo[city][day]!=-1)
     return memo[city][day];
     int d,t,m,i;
    m=-5;
   // printf("In city %d at day %d\n",city,day);
     if(day==K-1)
     {
       if(N!=city){
       d=(day+1)%D[city][N];if(!d)d=D[city][N];
       if(G[city][N][d])
       m=G[city][N][d];}
     }
     else
     {
    for(i=1;i<=N;i++)
    {    
      if(city!=i)
      {           
      d=(day+1)%D[city][i];if(!d)d=D[city][i];
     if(G[city][i][d])
     {
    //  printf("Going to city %d from %d at day %d\n",i,city,day);       
       t=dp(i,day+1);
       if(t!=-5)
        t+=G[city][i][d];
       if(t!=-5&&m==-5)
        m=t;
       else if(t!=-5)
       m=MIN(m,t);
       //printf("Back to city %d parent city %d where m=%d,t=%d\n",i,city,m,t);
       }
     }
     }
     }
     memo[city][day]=m;
     return m;
     
}
int main()
{
    //freopen("o","w",stdout);
    int i,j,k,kas=1,t;
    while(scanf("%d %d",&N,&K)&&(N||K))
    {
       for(i=0;i<=N;i++)
        for(j=0;j<1005;j++)
         memo[i][j]=-1;
         
       for(i=1;i<=N;i++)
         for(j=1;j<=N;j++)
          {
            if(i==j)
             continue;
            scanf("%d",&D[i][j]);
            for(k=1;k<=D[i][j];k++)
             scanf("%d",&G[i][j][k]);
          }
       t=dp(1,0);
       printf("Scenario #%d\n",kas++);
       if(t!=-5)
        printf("The best flight costs %d.\n",t);
       else
        printf("No flight possible.\n");
        printf("\n");
        for(i=0;i<=N;i++)
         for(j=0;j<=N;j++)
           for(k=0;k<35;k++)
            G[i][j][k]=0;
    }
    return 0;
}
