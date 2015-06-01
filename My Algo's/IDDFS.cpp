#include<cstdio>
#include<vector>
using namespace std;
vector<long>adj[1000];
bool found,D;
long goal,source,par[1000];
void DLS(long node,long depth) 
{
  if ( depth >= 0 ) 
  {
    D=(!depth)?1:0;
    if ( node == goal )
    {found=1;return;}
    long i;
    for(i=0;i<adj[node].size();i++)
    {par[adj[node][i]]=node;DLS(adj[node][i],depth-1);}
  }
}
void path(long node)
{
  if(node==-1)
   return;
  path(par[node]);
  printf("%ld ",node);
}
void IDDFS() 
{
  long depth;
  D=1;depth = 0;found=0;par[source]=-1;
  while(!found&&D)
  {
    DLS(source,depth);
    if(found)
    {
     printf("%ld\n",depth);
     path(goal);
     }
    depth = depth + 1;
  }
  if(!found)
   printf("Not Reachable\n");
}

int main()
{
    long node,edge,a,b,i;
    while(scanf("%ld %ld",&node,&edge)==2)
    {
      while(edge--)
      {
        scanf("%ld %ld",&a,&b);
        adj[a].push_back(b);
      }
      scanf("%ld %ld",&source,&goal);
      IDDFS();
      for(i=1;i<=node;i++)
       adj[i].clear();
    }
}
