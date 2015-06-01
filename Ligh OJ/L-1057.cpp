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
#define i64 int
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,-1,sizeof(x))
#define swap(a,b) a^=b,b^=a,a^=b
#define chkC(x,n) (x[n>>5]&(1<<(n&31)))
#define setC(x,n) (x[n>>5]|=(1<<(n&31)))

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



inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b) {return (a>b)?b:a;}
inline dle dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}

int M[17][66070],C[22][22];
int FS,n,m,p[22][22],Sx,Sy,k;
char str[22][22];

void bfs(int x,int y)
{
  queue<pii>q;
      
  pii nodo;
  int i,nx,ny,sx,sy,d[22][22];
  memset(d,0,sizeof(d));
  C[p[x][y]][p[x][y]]=0;
  q.push(pii(x,y));d[x][y]=1;
  while(!q.empty())
  {
    nodo=q.front();q.pop();
    sx=nodo.first;sy=nodo.second;

    rep(i,0,7)
    {
     nx=sx+xx[i],ny=sy+yy[i];
     if(nx<1||ny<1||nx>m||ny>n||d[nx][ny]) continue;
     d[nx][ny]=d[sx][sy]+1;
   
     if(str[nx][ny-1]!='.'){
     C[p[x][y]][p[nx][ny]]=d[nx][ny]-1;
     
     
     }
     
     q.push(pii(nx,ny));
    }
  }
}
int dp(int f,int s)
{
  if(f==0&&s==FS) return 0;
  int ret=M[f][s];
  if(ret>=0) return ret;
  M[f][s]=-2;
  ret=INT_MX;

  int i,t;
  
  rep(i,0,k-1)
  {
    if(f!=i){
     int ns=s|(1<<i);
     if(M[i][ns]==-2) continue;
    t=dp(i,ns);
    if(t!=INT_MX) t+=C[f][i];
    ret=MIN(ret,t);
    }
  }
 return M[f][s]=ret; 
}

int main()
{
    int i,j,kase,kas=0;
    S1(kase);
    while(kase--)
    {
      S2(m,n);
      k=0;
      rep(i,1,m)
      {
       scanf("%s",str[i]);
       rep(j,1,n)
        if(str[i][j-1]=='x') p[i][j]=0,Sx=i,Sy=j;
        else if(str[i][j-1]=='g')p[i][j]=++k;
      }
    rep(i,1,m)
       rep(j,1,n)
        if(str[i][j-1]!='.')   
         bfs(i,j);
      k++;
      FS=(1<<k)-1;
      mems(M);
      printf("Case %d: %d\n",++kas,dp(0,1));
    }
    return 0;
}
