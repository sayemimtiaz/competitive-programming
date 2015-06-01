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

struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
priority_queue<pair<int,int> >pq;
vector<pair<int,int> >adj[30];

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

int main()
{
    pair<int,int>nodo,next;
    int n,m,i,j,u,v,c,q;
    int d[30],e[30],p[30],O[30],o;
    char c1,c2,str[5000];
    bool vis[30];
    
    while(gets(str))
    {
      sscanf(str,"%d %d",&n,&m);
      for(i=0;i<m;i++)
      {
        gets(str);
        sscanf(str,"%c %c %d",&c1,&c2,&c);
        adj[c1-'A'].pb(make_pair(c2-'A',c));
        adj[c2-'A'].pb(make_pair(c1-'A',c));
      }
      gets(str);
      sscanf(str,"%d",&q);
      while(q--)
      {
        gets(str);
        sscanf(str,"%c %c",&c1,&c2);
        //printf("%c %c\n",c1,c2);
        for(i=0;i<26;i++)
        vis[i]=0,p[i]=-1,d[i]=INT_MX;
        d[c1-'A']=0,e[c1-'A']=1;
        pq.push(make_pair(0,c1-'A'));
        while(!pq.empty())
        {
          nodo=pq.top();pq.pop();
          u=nodo.second;
          if(vis[u])
           continue;
          vis[u]=1;
          for(i=adj[u].size()-1;i>=0;i--)
          {
            next=adj[u][i];v=next.first,c=next.second;
            if((d[v]>d[u]+c)||(d[v]==d[u]+c&&e[v]>e[u]+1))
            {
              d[v]=d[u]+c,e[v]=e[u]+1;p[v]=u;
              pq.push(make_pair(-d[v],v));
            }
          }
        }
       // printf("%d\n",d[c2-'A']);
        u=c2-'A';o=0;
        while(u!=-1){
         O[o++]=u;
         u=p[u];}
         printf("%c",O[o-1]+'A');
        for(i=o-2;i>=0;i--)
         printf(" %c",O[i]+'A');
        printf("\n");
      }
      for(i=0;i<26;i++)
       adj[i].clear();
    }
    return 0;
}
