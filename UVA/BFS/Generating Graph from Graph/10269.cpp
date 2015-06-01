/*Though the problem statement seems it could be solved by straight-forward approach,Its not really.
Here,I generated another graph from the given graph.This new Graph consists of nodes which contain 3 information
(original number of vertex in given graph,how many times boot can be used,how long already passed through the boat
if mario wears it then).From source state(A+B,K,0) I went through all other neighbour state like (next,K,0) or (next,K-1,c)
and finally find out the result*/

#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
typedef vector<long>vi;
#define INF 2147483647
vi adj[105],cost[105];
long memo[105][15][505];
queue<long>q;
int main()
{
    long mino,kase,a,b,c,A,B,M,L,K,i,j,k,x,y,z;
    scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%ld %ld %ld %ld %ld",&A,&B,&M,&L,&K);
        while(M--)
        {
          scanf("%ld %ld %ld",&a,&b,&c);
          adj[a].push_back(b);
          adj[b].push_back(a);
          cost[a].push_back(c);
          cost[b].push_back(c);
        }
        for(k=0;k<=A+B;k++)
         for(i=0;i<=K;i++)
          for(j=0;j<=L;j++)
           memo[k][i][j]=INF;
        q.push(A+B);q.push(K);q.push(0);
        memo[A+B][K][0]=0;
        while(!q.empty())
        {
          a=q.front();q.pop();b=q.front();q.pop();c=q.front();q.pop(); 
          for(i=0;i<adj[a].size();i++)
          {
              x=adj[a][i];y=b;z=0;
              if(memo[x][y][z]>memo[a][b][c]+cost[a][i])
              {
                  memo[x][y][z]=memo[a][b][c]+cost[a][i];
                  q.push(x);q.push(y);q.push(z);
              }
              if(c&&(L-c)>=cost[a][i])
              {
                   z=(x>A)?0:c+cost[a][i];
                   if(memo[x][y][z]>memo[a][b][c])
                   {memo[x][y][z]=memo[a][b][c];
                    q.push(x);q.push(y);q.push(z);
                    } 
               }
               if(b&&L>=cost[a][i])
               {
                    y=b-1;z=(x>A)?0:cost[a][i];
                 if(memo[x][y][z]>memo[a][b][c])
                 {memo[x][y][z]=memo[a][b][c];
                  q.push(x);q.push(y);q.push(z);} 
               }
               
          }
        }
        mino=INF;
        for(i=0;i<=K;i++)
         for(j=0;j<=L;j++)
          if(memo[1][i][j]<mino)
           mino=memo[1][i][j];
        printf("%ld\n",mino);
        for(i=1;i<=A+B;i++)
        {adj[i].clear();cost[i].clear();}
    }
    return 0;
}
