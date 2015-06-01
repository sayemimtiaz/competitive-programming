#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define INF 2147483647
#define MAXN 1200
#define MINI(a,b) (a>b)?b:a
vector<int>adj[MAXN];
int X,flow[MAXN][MAXN],N,src,dest,path[MAXN],in[MAXN],out[MAXN],total[MAXN];
bool F[MAXN];
int bfs()
{
    int i,u,v,cf,tf;
    queue<long>q;
    for(i=1;i<=N;i++)
     path[i]=-2;
    q.push(src);
    path[src]=-1;
    while(!q.empty())
    {
       u=q.front();
       q.pop();
       if(out[u]==0)
       { 
         cf=INF;
         v=u;
         X=u;
         while(path[v]!=-1)
         {
           cf=MINI(cf,flow[path[v]][v]);
          // printf("Edge %ld %ld costs %ld\n",path[v],v,flow[path[v]][v]);
           v=path[v];
         }
         while(!q.empty())
          q.pop();
         return cf;
       }
       for(i=1;i<=N;i++)
       {
           if(path[i]==-2&&flow[u][i])
           {
             q.push(i);
             path[i]=u;
           }
       }
    }
    return 0;
}
void maxflow()
{
    int cf,v;
    while(cf=bfs())
    {
       total[X]+=cf;
       v=X;
       F[v]=1;
       while(path[v]!=-1)
       {
           flow[path[v]][v]-=cf;
           flow[v][path[v]]+=cf;
           v=path[v];
       }
    }
    
}
int main()
{
  int j,E,i,k,l,m,a,b,c,oa[MAXN],ob[MAXN],oc[MAXN],S[MAXN],D[MAXN],cnt; 
  while(~scanf("%d %d",&N,&E))
  {

  for(i=1;i<=E;i++)
  {
    scanf("%d %d %d",&a,&b,&c);
    flow[a][b]=c;
    in[b]=1;
    out[a]=1;
   }
   if(E==0){
    printf("0\n");continue;}
   j=0;k=0;
   for(i=1;i<=N;i++)
   { if(in[i]==0)
      S[j++]=i;
     if(out[i]==0)
      D[k++]=i;
     }
     m=0;cnt=0;
   for(i=0;i<j;i++)
   {
    src=S[i];
    maxflow();
    for(l=0;l<k;l++)
     if(F[D[l]])
     {
       oa[m]=S[i],ob[m]=D[l],oc[m]=total[D[l]];
       m++;
       cnt++;
     }
     memset(F,0,sizeof(F));
   }
   printf("%d\n",cnt);
   for(i=0;i<m;i++)
    printf("%d %d %d\n",oa[i],ob[i],oc[i]);
   memset(total,0,sizeof(total));
   memset(out,0,sizeof(out));
   memset(in,0,sizeof(in));
  }
  return 0;
}
