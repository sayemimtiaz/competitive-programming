#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int>adj[100];
bool vis[100];
bool child;
void dfs(int s)
{
  int i;
  vis[s]=1;
  for(i=0;i<adj[s].size();i++)
   if(!vis[adj[s][i]])
    {child=1;dfs(adj[s][i]);}
}
int main()
{
    char str[1000];
    int kase,i,j,a,b,tree,acorn;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
       while(gets(str)&&str[0]!='*')
       {
         a=str[1]-64;b=str[3]-64;
         adj[a].push_back(b);
         adj[b].push_back(a);
       }
       gets(str);
       tree=acorn=0;
       for(i=0;str[i]!='\0';i++)
       {
            if(str[i]==',')
             continue;
            a=str[i]-64;
            if(!vis[a])
            {
             child=0;
             dfs(a);
             if(!child)
              acorn++;
             else
              tree++;
              }
       }
       printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
       for(i=0;i<=30;i++)
        adj[i].clear();
       memset(vis,0,sizeof(vis));
    }
    return 0;
}
