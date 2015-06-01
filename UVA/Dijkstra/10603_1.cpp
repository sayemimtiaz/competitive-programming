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
  return a;
}

int a,b,c,R,d,S;
bool G[202],vis[202][202][202],flag;

struct CONT
{
  int a,b,c,d;
};

bool operator<(const CONT &a,const CONT &b)
{
  return a.d>b.d;
}

inline void UpdateR(int a,int c)
{
  if(G[a]||a>d||a<S) return;
  R=c,S=a;
  G[a]=1;
}
int main()
{
    int kase,na,nb,nc,nd;
    priority_queue<CONT>q;
    S1(kase);
    while(kase--)
    {
      S3(a,b,c);
      S1(d);
      CONT C1={0,0,c,0};
      q.push(C1);
      S=R=0;flag=0;
      while(!q.empty()){
       CONT C1=q.top();q.pop();
       if(vis[C1.a][C1.b][C1.c]) continue;
       vis[C1.a][C1.b][C1.c]=1;
     //  printf("%d %d %d %d\n",C1.a,C1.b,C1.c,C1.d);
       UpdateR(C1.a,C1.d),UpdateR(C1.b,C1.d),UpdateR(C1.c,C1.d);
       if(C1.a){
         nc=C1.c;
         //Transferring From A to B
        if(C1.a>b-C1.b) nb=b,na=C1.a-b+C1.b,nd=C1.d+b-C1.b;
        else na=0,nb=C1.b+C1.a,nd=C1.d+C1.a;
        if(!vis[na][nb][nc]){
         CONT C2={na,nb,nc,nd};
         q.push(C2);
         }
         nb=C1.b;
         //Transferring From A to C
        if(C1.a>c-C1.c) nc=c,na=C1.a-c+C1.c,nd=C1.d+c-C1.c;
        else na=0,nc=C1.c+C1.a,nd=C1.d+C1.a;
        if(!vis[na][nb][nc]){
         CONT C2={na,nb,nc,nd};
         q.push(C2);
         }
        }
         if(C1.b){
         nc=C1.c;
         //Transferring From B to A
        if(C1.b>a-C1.a) na=a,nb=C1.b-a+C1.a,nd=C1.d+a-C1.a;
        else nb=0,na=C1.a+C1.b,nd=C1.d+C1.b;
        if(!vis[na][nb][nc]){
         CONT C2={na,nb,nc,nd};
         q.push(C2);
         }
         na=C1.a;
         //Transferring From B to C
        if(C1.b>c-C1.c) nc=c,nb=C1.b-c+C1.c,nd=C1.d+c-C1.c;
        else nb=0,nc=C1.c+C1.b,nd=C1.d+C1.b;
        if(!vis[na][nb][nc]){
         CONT C2={na,nb,nc,nd};
         q.push(C2);
         }
        }
         if(C1.c){
         nb=C1.b;
         //Transferring From C to A
        if(C1.c>a-C1.a) na=a,nc=C1.c-a+C1.a,nd=C1.d+a-C1.a;
        else nc=0,na=C1.a+C1.c,nd=C1.d+C1.c;
        if(!vis[na][nb][nc]){
         CONT C2={na,nb,nc,nd};
         q.push(C2);
         }
         na=C1.a;
         //Transferring From C to B
        if(C1.c>b-C1.b) nb=b,nc=C1.c-b+C1.b,nd=C1.d+b-C1.b;
        else nc=0,nb=C1.b+C1.c,nd=C1.d+C1.c;
        if(!vis[na][nb][nc]){
         CONT C2={na,nb,nc,nd};
         q.push(C2);
         }
        }
       }
       printf("%d %d\n",R,S);
       mems(vis);
       mems(G);
    }
    return 0;
}
