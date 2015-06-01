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
#define INF 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define in(i) 2*i
 

int S,D,m,n,path[5050];
int flow[5050][5050];


inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int bfs()
{
    int i,u,v,cf,tf,a,c;
    queue<long>q;
    int x[]={1,-1,n,-n};
    for(i=0;i<=D;i++)
     path[i]=-2;
    q.push(S);
    path[S]=-1;
    while(!q.empty())
    {
       u=q.front();
       q.pop();
       if(u==D)
       { 
         cf=INF;
         v=D;
         while(path[v]!=-1)
         {
           cf=MIN(cf,flow[path[v]][v]);
          // printf("Edge %ld %ld costs %ld\n",path[v],v,flow[path[v]][v]);
           v=path[v];
         }
         while(!q.empty())
          q.pop();
         return cf;
       }
     //  printf("%d\n",u);
       if(u==S)
       {
         for(i=0;i<=D;i++)
          if(path[i]==-2&&flow[u][i])
           {
             q.push(i);
             path[i]=u;
           }
       }
       else
       {
       a=u/2;
       if(u%2==0&&path[u+1]==-2&&flow[u][u+1])
           {
             q.push(u+1);
             path[u+1]=u;
           }
       for(i=0;i<4;i++){
           c=2*(a+x[i]);
         
           if(c<0||c>D)
            continue;
           if(path[c]==-2&&flow[u][c])
           {
             q.push(c);
             path[c]=u;
           }
           c++;
           if(path[c]==-2&&flow[u][c])
           {
             q.push(c);
             path[c]=u;
           }
       }
       if(path[D]==-2&&flow[u][D])
           {
             q.push(D);
             path[D]=u;
           }
       }
    }
    return 0;
}

int maxflow()
{
    int cf,v,totalflow=0;
    
    while(cf=bfs())
    {
      // printf("%d\n",cf);
       totalflow+=cf;
       v=D;
       while(path[v]!=-1)
       {
           flow[path[v]][v]=0;
           flow[v][path[v]]=1;
          // printf("%d ",v);
           v=path[v];
       }
    //  printf("\n");
    }
    return totalflow;
    
}

void init()
{
        int x[4]={0,0,1,-1};
    int y[4]={1,-1,0,0};
    int i,j,k,ia,ib,oa,ob,c,d;
    
     for(i=0;i<m;i++)
       for(j=0;j<n;j++)
       {
         ia=2*(i*n+j);
         oa=ia+1;
         flow[ia][oa]=1;
         
         if(i==0||j==0||i==m-1||j==n-1)
          flow[oa][D]=1;
         for(k=0;k<4;k++)
         {
           c=i+x[k],d=j+y[k];
           if(c<0||d<0||c>=m||d>=n)
            continue;
           ib=2*(c*n+d);
           ob=ib+1;
           flow[oa][ib]=1;
         }
       }
}

int main()
{
   // freopen("z.txt","r",stdin);
    //freopen("o.txt","w",stdout);
    int i,j,q,kase,a,k,l;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d %d",&n,&m,&q);
       S=2*m*n;D=S+1;
      init();
      for(k=0;k<q;k++)
      {
        scanf("%d %d",&i,&j);
        a=2*((j-1)*n+(i-1));
        flow[S][a]=1;
      }
      if(maxflow()==q)
       printf("possible\n");
      else
       printf("not possible\n");
      
      for(i=0;i<=D;i++)
       for(j=0;j<=D;j++)
        flow[i][j]=0;
    }
    return 0;
}
