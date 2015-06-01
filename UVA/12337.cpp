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
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 int
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))
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
    int xx[]={0,1,0,-1};
    int yy[]={1,0,-1,0};
    int kase,i,j,kas=0,min,n,l,k,a,nx,ny,x,y,face,q;
    char temp[55][55];
    char str[1000];
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
     gets(str);
     n=strlen(str);
     l=sqrt(n);
     min=INT_MX;
     for(i=2;i<=l;i++)
      if(n%i==0)
      {
         a=n/i;
        //rintf("%d %d\n",i,a);
         bool flag=1;
         bool vis[55][55]={0};
         x=0,y=0;temp[x][y]=str[0];k=1;vis[0][0]=1;face=0;
         while(1)
         {
           for(q=0,j=face;q<4;q++)
           { nx=x+xx[j],ny=y+yy[j];
            if(nx>=0&&ny>=0&&nx<i&&ny<a&&!vis[nx][ny])
             {face=j;break;}
             j=(j+1)%4;
            }
            if(q==4)
             break;
            temp[nx][ny]=str[k++];
            vis[nx][ny]=1;
          
        //   printf("temp[%d][%d]=%c %d\n",nx,ny,str[k-1],face);
            x=nx,y=ny;
         }
         for(j=0;flag&&j<a;j++)
          for(k=1;flag&&k<i;k++)
           if(temp[k-1][j]!=temp[k][j]) 
             flag=0;
          if(flag)
           min=MIN(min,i+a);
           flag=1;
           mems(vis);
           x=0,y=0;temp[x][y]=str[0];k=1;vis[0][0]=1;face=0;
         while(1)
         {
           for(q=0,j=face;q<4;q++)
           { nx=x+xx[j],ny=y+yy[j];
            if(nx>=0&&ny>=0&&nx<a&&ny<i&&!vis[nx][ny])
             {face=j;break;}
             j=(j+1)%4;
            }
            if(q==4)
             break;
            temp[nx][ny]=str[k++];
            vis[nx][ny]=1;
          // printf("temp[%d][%d]=%c %d\n",nx,ny,str[k-1],face);
            x=nx,y=ny;
         }
         for(j=0;flag&&j<i;j++)
          for(k=1;flag&&k<a;k++)
            if(temp[k-1][j]!=temp[k][j])
             flag=0;
          if(flag)
           min=MIN(min,i+a);
      }
      printf("Case %d: ",++kas);
      if(min==INT_MX)
       printf("-1\n");
      else
       printf("%d\n",min);
    }
    return 0;
}
