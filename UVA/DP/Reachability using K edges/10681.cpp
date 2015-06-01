#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define MAXNODE 120
#define MAXD 220 
vector<long>adj[MAXNODE];
int memo[MAXNODE][MAXD];
long E;
long dp(long cur,long trip)
{
     if(!trip)
     {
       if(cur==E)
       return 1;
       return 2;
     }
     if(memo[cur][trip])
      return memo[cur][trip];
     long cm,m,i,next;
     if(trip==1)
     {
        for(i=0;i<adj[cur].size();i++)
        {
           next=adj[cur][i];
           if(next==E)
             {memo[cur][trip]=1;return 1;}
        }
        memo[cur][trip]=2;return 2;        
     }
     else
     {
     for(i=0;i<adj[cur].size();i++)
     {
         next=adj[cur][i];
         m=dp(next,trip-1);
         if(cm!=1)
          cm=m;
     }
     }
     memo[cur][trip]=cm;
     return cm;
}
int main()
{
    long L,D,S,i,j,C,a,b;
    while(scanf("%ld %ld",&C,&L)&&(C||L))
    {
        while(L--)
        {
           scanf("%ld %ld",&a,&b);
           adj[a].push_back(b);
           adj[b].push_back(a);
        }
        scanf("%ld %ld %ld",&S,&E,&D);
        if(dp(S,D)==1)
        printf("Yes, Teobaldo can travel.\n");
        else
        printf("No, Teobaldo can not travel.\n");
        memset(memo,0,sizeof(memo));
        for(i=1;i<=C;i++)
         adj[i].clear();
    }
    return 0;
}
