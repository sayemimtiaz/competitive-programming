#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
#define SIZE 1200
vector<long> adj[SIZE];
queue<long> q;
bool vis[SIZE];
long d[SIZE];
void bfs()
{
     long i,u,v;
     while(!q.empty())
     {
        u=q.front();
        q.pop();
        for(i=0;i<adj[u].size();i++)
        {
          v=adj[u][i];
          if(!vis[v])
          {
             vis[v]=1;
             d[v]=d[u]+1;
             q.push(v);
          }
        }
     }
}
int main()
{
    long j,k,n;
    double t,a[SIZE],b[SIZE],vi,m,dis;
    char str[5000];
    while(scanf("%lf %lf",&vi,&m)==2&&(vi||m))
    {
        getchar();
        n=0;
        while(gets(str)&&str[0]!='\0')
        {
          sscanf(str,"%lf %lf",&a[n],&b[n]);
          n++;
        }
         m=m*60;
        for(j=0;j<n;j++)
         for(k=j+1;k<n;k++)
         {
           dis=sqrt((a[j]-a[k])*(a[j]-a[k])+(b[j]-b[k])*(b[j]-b[k]));
           t=dis/vi;
           if(t<=m)
           {
                   adj[j].push_back(k);adj[k].push_back(j);}
         }
        for(j=0;j<n;j++)
        {
          d[j]=-1;
          vis[j]=0;
        }
        d[0]=0;
        q.push(0);vis[0]=1;
        bfs();
        if(d[1]==-1)
          printf("No.\n");
        else
          printf("Yes, visiting %ld other holes.\n",d[1]-1);
       for(j=0;j<n;j++)
       {adj[j].clear();} 
    }
    return 0;
}
