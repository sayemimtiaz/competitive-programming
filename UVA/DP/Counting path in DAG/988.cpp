#include<cstdio>
#include<vector>
#define MAXN 4000
using namespace std;
vector<long>adj[MAXN];
long memo[MAXN],N;
void init()
{
     for(long i=0;i<=N;i++)
        memo[i]=-1;
}
long dp(long curNode)
{
     if(memo[curNode]!=-1)
      return memo[curNode];
     long size,i;
     long m=0;
     size=adj[curNode].size();
     if(size==0)
      return 1;
     for(i=0;i<size;i++)
     {
          m+=dp(adj[curNode][i]);
     }
     memo[curNode]=m;
     return m;
}
int main()
{
    long i;
    bool flag=0;
    long a,c;
    while(~scanf("%ld",&N))
    {
       init();
       for(i=0;i<N;i++)
       {
          scanf("%ld",&c);
          while(c--)
          {
            scanf("%ld",&a);
            adj[i].push_back(a);
          }
       }
       if(flag)
        printf("\n");
       else
        flag=1;
       printf("%ld\n",dp(0));
       for(i=0;i<N;i++)
        adj[i].clear();
    }
    return 0;
}
