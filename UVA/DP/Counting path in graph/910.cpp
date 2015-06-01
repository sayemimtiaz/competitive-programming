#include<cstdio>
#include<vector>
using namespace std;
vector<long>adj[40];
long memo[40][40],M,N;
bool sp[40];
void init()
{
     for(long i=0;i<=N;i++)
     {
       sp[i]=0;
       for(long j=0;j<=40;j++)
        memo[i][j]=-1;
     }
}
long dp(long curNode,long dis)
{
     if(memo[curNode][dis]!=-1)
      return memo[curNode][dis];
     if(dis==M)
     {
        if(sp[curNode])
         return 1;
        else 
         return 0;
     }
     long size,i;
     long m=0;
     size=adj[curNode].size();
     for(i=0;i<size;i++)
     {
        if((dis+1)<=M)
        {
          m+=dp(adj[curNode][i],dis+1);
        }
     }
     memo[curNode][dis]=m;
     return m;
}
int main()
{
    long i;
    char a,b,c,d;
    while(~scanf("%ld",&N))
    {
       init();
       for(i=0;i<N;i++)
       {
          getchar();
          scanf("%c %c %c %c",&a,&b,&c,&d);
          adj[a-65].push_back(b-65);
          adj[a-65].push_back(c-65);
          sp[a-65]=(d=='x')?1:0;
       }
       scanf("%ld",&M);
       printf("%ld\n",dp(0,0));
       for(i=0;i<N;i++)
        adj[i].clear();
    }
    return 0;
}
