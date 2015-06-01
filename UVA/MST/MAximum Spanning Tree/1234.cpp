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
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100009 
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

struct edge
{
  int a,b,c;
}E[SIZE];
int n,par[SIZE],rank[SIZE];

bool cmp(edge x,edge y)
{
  return (x.c>y.c);
}

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

inline void MakeSet()
{
  for(int i=1;i<=n;i++)
   rank[i]=0,par[i]=i;
}

void link(int x,int y)
{
  if(rank[x]>rank[y])
   par[y]=x;
  else
  {
      par[x]=y;
      if(rank[x]==rank[y])
      rank[y]++;
  }
}

int find(int x)
{
    if(par[x]!=x)
     par[x]=find(par[x]);
    return par[x];
}

int main()
{
    int kase,m,a,b,c,i;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&m);
      MakeSet();
      for(i=0;i<m;i++)
         scanf("%d %d %d",&E[i].a,&E[i].b,&E[i].c);
      sort(E,E+m,cmp);
      c=0;
      for(i=0;i<m;i++)
      {
         a=find(E[i].a),b=find(E[i].b);
       //printf("%d %d %d %d %d %d\n",E[i].a,E[i].b,a,b,par[a],par[b]);
         if(a!=b)
          link(a,b);
         else
          c+=E[i].c;  
      }
      printf("%d\n",c);             
    }
    scanf("%d",&n);
    return 0;
}
