#include<cstdio>
#include<vector>
using namespace std;
vector<int>adj[1000];
int x[1000],n,m;
void init()
{
     int i,j;
     for(i=1;i<=n;i++)
     {
         x[i]=0;
         adj[i].clear();
     }
}
void nextvalue(int k)
{
     int i;
     while(1)
     {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
         return;
        for(i=0;i<adj[k].size();i++)
         if(x[k]==x[adj[k][i]])
           break;
        if(i==adj[k].size())
         return;
         
     }
}
void print()
{
     int i;
     for(i=1;i<=n;i++)
      printf(" %d",x[i]);
     printf("\n");
}
void color(int k)
{
     while(1)
     {
        nextvalue(k);
        if(x[k]==0)
          return;
        if(k==n)
          print();
        else
        color(k+1);
     }
}
int main()
{
    int kase,u,v,e,i;
    scanf("%d",&kase);
    while(kase--)
    {
    scanf("%d %d %d",&m,&n,&e);
    for(i=1;i<=e;i++){
     scanf("%d %d",&u,&v);
     adj[u].push_back(v);
     adj[v].push_back(u);}
     color(1);
     init();
     }
    return 0;
}
