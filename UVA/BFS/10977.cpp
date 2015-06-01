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
#define swap(a,b,t) t=a,a=b,b=t
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
typedef pair<int,int>pii;


inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
inline int dis(int ax,int ay,int bx,int by)
{
  //Without sqrt()
  return ((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
}

bool v[205][205];
int d[205][205];
queue<pii>q;

int main()
{
    int m,n,i,j,a,b,L,t,c,dd;
    
    while(S2(m,n)&&(m||n))
    {
      mems(v);
      S1(t);
      while(t--){
        S2(a,b);
        v[a][b]=1;
        }
      S1(t);
      while(t--)
      {
        S3(a,b,L);
        v[a][b]=1;
        L*=L;
        rep(i,1,m)
         rep(j,1,n)
            if(dis(a,b,i,j)<=L)
               v[i][j]=1;
      }
      if(v[1][1]){  printf("Impossible.\n");continue;}
      v[1][1]=1,d[1][1]=0;q.push(pii(1,1));
      while(!q.empty()){
        pii U=q.front();q.pop();
        rep(i,0,3){
         c=U.first+xx[i],dd=U.second+yy[i];
         if(c<1||dd<1||c>m||dd>n||v[c][dd]) continue;
         q.push(pii(c,dd));v[c][dd]=1,d[c][dd]=d[U.first][U.second]+1;
         }
      }
      if(v[m][n])
       printf("%d\n",d[m][n]);
      else
       printf("Impossible.\n");
    }
    return 0;
}
