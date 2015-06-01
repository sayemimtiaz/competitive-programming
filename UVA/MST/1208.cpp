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
#define SIZE 10000 
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

struct edge
{
  int a,b,c;
}E[SIZE],O[SIZE];
int n,par[SIZE],rank[SIZE];

bool cmp(edge x,edge y)
{
  if(x.c!=y.c)
  return (x.c<y.c);
  if(x.a!=y.a)
  return (x.a<y.a);
  return (x.b<y.b); 
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
  for(int i=0;i<n;i++)
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
    char ch[1000],*pch;
    int kase,m,a,b,c,i,e,j,kas=0;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      MakeSet();
      e=0;
      for(i=0;i<n;i++)
        for(j=0;j<n;j++){
         scanf("%s",ch);
         pch=strtok(ch,",");
         sscanf(pch,"%d",&a);
          if(i==j||!a)
           continue;
          E[e].a=i,E[e].b=j,E[e++].c=a;
         }
      sort(E,E+e,cmp);
      m=0;
      for(i=0;i<e;i++)
      {
         a=find(E[i].a),b=find(E[i].b);
         if(a!=b){
          link(a,b);
          O[m++]=E[i];}  
      }
      printf("Case %d:\n",++kas);
      for(i=0;i<m;i++)
       printf("%c-%c %d\n",O[i].a+'A',O[i].b+'A',O[i].c);             
    }
    scanf("%d",&n);
    return 0;
}
