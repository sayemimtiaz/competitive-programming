#include<cstdio>
#include<vector>
using namespace std;
#define MAXNODE 2000
#define MIN(a,b) (a>b)?b:a
vector<int>adj[MAXNODE];
int memo[MAXNODE][3],N;
bool vis[MAXNODE],mark[MAXNODE];
void init()
{
     int i,j;
     for(j=1;j<=N;j++)
     {mark[j]=0;
     for(i=1;i<=2;i++)
       memo[j][i]=-1;
     }
}
int dp(int name,int state)
{
    if(memo[name][state]!=-1)
      return memo[name][state];
      int m,i,next;
    m=(state==1)?0:1;
    for(i=0;i<adj[name].size();i++)
    {
      next=adj[name][i];
      if(!vis[next])
      {
        vis[name]=1;
        if(state==1)
        m+=dp(next,2);
        else
        m+=MIN(dp(next,1),dp(next,2));
        vis[name]=0;
        }
    }
    mark[name]=1;
    memo[name][state]=m;
    return m;
}
int main()
{
    int temp,temval,res,i,j;
    while(scanf("%d",&N)&&N)
    {
       init();
       for(i=1;i<=N;i++)
       {
         scanf("%d",&temp);
         while(temp--)
         {
           scanf("%d",&temval);
           adj[i].push_back(temval);
         }
       }
         res=0;
         for(i=1;i<=N;i++)
           if(!mark[i])
           {
              temp=dp(i,1);if(!temp)temp=1;
              temval=dp(i,2);if(!temval)temval=1;
              res+=MIN(temp,temval);
           }
        printf("%d\n",res);
        for(i=1;i<=N;i++)
         adj[i].clear();
    }
    return 0;
}
