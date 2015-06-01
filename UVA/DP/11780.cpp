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
#define mems(x) memset(x,0,sizeof(x))

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
inline dle MIN(dle a,dle b)
{
 return(a>b)?b:a;
}
inline dle dis(Point a,Point b)
{
  //Without sqrt()
  return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    double P[1200],R;
    int W[1200];
    int F[100];
    int f,n,j,i;
    F[1]=1,F[2]=1,f=3;
    do{
      F[f]=F[f-1]+F[f-2];
      f++;
      }while(F[f-1]<=1000);
    f--;
    
    while(scanf("%d",&n)&&n)
    {
     rep(i,1,n)
      P[i]=INT_MX;
     W[0]=0;
     for(i=1;i<=f-2&&F[i]<=n;i++)
      rep(j,F[i],n){
        R=fabs((j*1.6)-(W[j-F[i]]+F[i+1]));
        if(P[j]>R)
         P[j]=R,W[j]=W[j-F[i]]+F[i+1];
       //printf("P[%d]=%lf\n",j,[j]);
       }
      printf("%0.2lf\n",P[n]);
        
    }
    return 0;
}
