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
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))

int xx[]={0,1,-1,0,1,-1,1,-1};
int yy[]={1,0,0,-1,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
int ei,ej,n;
bool vis[120][120];
bool sp,flag;

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

void dfs(int i,int j)
{
     int ni,nj,k;
     if(sp)
      printf(" ");
     else
      sp=1;
     printf("(%d,%d)",i,j);
     vis[i][j]=1;
     if(i==ei&&ej==j)
     {flag=0;return;}
     for(k=0;k<4;k++)
     {
       ni=xx[k]+i,nj=j+yy[k];
       if(ni<1||nj<1||ni>n||nj>n||vis[ni][nj])
        continue;
          if(ni==ei&&ej==nj)
            dfs(ni,nj);
     }
     for(k=0;flag&&k<4;k++)
     {
       ni=xx[k]+i,nj=j+yy[k];
       if(ni<1||nj<1||ni>n||nj>n||vis[ni][nj])
        continue;
       dfs(ni,nj);
       if(flag)
       printf(" (%d,%d)",i,j);
     }
}
int main()
{
    char str[50000],temp[50000],*pch;
    int kase,i,j,k,si,sj,a,b;
    gets(str);
    sscanf(str,"%d",&kase);
    while(kase--)
    {
      gets(str);
      pch=strtok(str," ");
      sscanf(pch,"%d",&n);
      pch=strtok(NULL," ");
      k=0;
      while(pch!=NULL)
      {
        j=0;
        for(i=1;pch[i]!=')';i++)
        {
          if(pch[i]==',')
          {
            temp[j]='\0',j=0;
            sscanf(temp,"%d",&a);
          }
          else
           temp[j++]=pch[i];        
        }
        temp[j]='\0';
        sscanf(temp,"%d",&b);
        if(k==0)
         si=a,sj=b,k=1;
        else if(k==1)
         ei=a,ej=b,k=2;
         else
          vis[a][b]=1;
        pch=strtok(NULL," ");
      }
      sp=0;flag=1;
      dfs(si,sj);
      printf("\n");
      mems(vis);
    }
    return 0;
}
