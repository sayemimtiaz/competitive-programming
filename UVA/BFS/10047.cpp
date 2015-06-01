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
#define mems(x) memset(x,0,sizeof(x))
#define swap(a,b,t) t=a,a=b,b=t
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={-1,+0,+1,+0};
int yy[]={+0,-1,+0,+1};
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
struct State
{
  int x,y,d,c;
}S,T;

queue<State>q;
char Grid[27][27];
int m,n;
int d[27][27][5][6];
bool vis[27][27][5][6];

void bfs()
{
 while(!q.empty())
 {
   S=q.front();q.pop();
   //printf("Maa d[%d][%d][%d][%d]=%d\n",S.x,S.y,S.d,S.c,d[S.x][S.y][S.d][S.c]);
   T.x=S.x+xx[S.d],T.y=S.y+yy[S.d];
   if(T.x>=1&&T.y>=1&&T.x<=m&&T.y<=n&&Grid[T.x][T.y]!='#'){
     T.d=S.d;T.c=(S.c+1)%5;
     if(!vis[T.x][T.y][T.d][T.c]){
      vis[T.x][T.y][T.d][T.c]=1,d[T.x][T.y][T.d][T.c]=d[S.x][S.y][S.d][S.c]+1,q.push(T);
    //   printf("[%d][%d][%d][%d]\n",T.x,T.y,T.d,T.c);
       }
   }
   T=S;
   T.d=(S.d+1)%4;
     if(!vis[T.x][T.y][T.d][T.c]){
      vis[T.x][T.y][T.d][T.c]=1,d[T.x][T.y][T.d][T.c]=d[S.x][S.y][S.d][S.c]+1,q.push(T);
  //   printf("[%d][%d][%d][%d]\n",T.x,T.y,T.d,T.c);
       }
   T.d=(S.d-1);if(T.d<0)T.d=3;
    if(!vis[T.x][T.y][T.d][T.c]){
      vis[T.x][T.y][T.d][T.c]=1,d[T.x][T.y][T.d][T.c]=d[S.x][S.y][S.d][S.c]+1,q.push(T);
//     printf("[%d][%d][%d][%d]\n",T.x,T.y,T.d,T.c);
       }
 }
}
int main()
{
    bool flag=0;
    int i,j,kas=0,ans,Tx,Ty;
    while(S2(m,n)&&(m||n))
    {
     rep(i,1,m)
     {
       getchar();
       rep(j,1,n){
        scanf("%c",&Grid[i][j]);
        if(Grid[i][j]=='S')
         S.x=i,S.y=j,S.d=0,S.c=0,q.push(S),vis[i][j][0][0]=1,d[i][j][0][0]=0;
         else if(Grid[i][j]=='T')
          Tx=i,Ty=j;
       }
     }
     bfs();
      ans=INT_MX;
      rep(i,0,3)
       if(vis[Tx][Ty][i][0])
        ans=MIN(ans,d[Tx][Ty][i][0]);
      if(flag) printf("\n");
      else flag=1;
       printf("Case #%d\n",++kas);
       if(ans!=INT_MX)
      printf("minimum time = %d sec\n",ans);
      else 
       printf("destination not reachable\n");
     mems(vis);
    }
    return 0;
}
