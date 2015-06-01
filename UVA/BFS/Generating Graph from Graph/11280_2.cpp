#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 2147483647
queue<long>q1,q2;
map<string,long>m;
typedef vector<long>vi;
vi adj[120],cost[120];
long memo[120][120],node;
void bfs()
{
     long pv,pd,nv,nd,i;
     while(!q1.empty())
     {
        pv=q1.front();q1.pop();
        pd=q2.front();q2.pop();
        for(i=0;i<adj[pv].size();i++)
        {
             nv=adj[pv][i];
             nd=pd+1;
             if(memo[nv][nd]>memo[pv][pd]+cost[pv][i])
             {
                memo[nv][nd]=memo[pv][pd]+cost[pv][i];
                q1.push(nv);q2.push(nd);
             }
        }
     }
}
int main()
{
    long kase,i,p1,p2,query,edge,depth,c,kas=1,j,min;
    bool flag=0;
    string s1,s2;
    cin>>kase;
    while(kase--)
    {
       cin>>node;
       for(i=1;i<=node;i++)
        {cin>>s1;m[s1]=i;}
       cin>>edge;
       while(edge--)
       {
         cin>>s1>>s2>>c;
         p1=m[s1];p2=m[s2];
         adj[p1].push_back(p2);
         cost[p1].push_back(c);
       }
       cin>>query;
       if(flag)cout<<"\n";
       flag=1;
       for(i=0;i<110;i++)
        for(j=0;j<110;j++)
         memo[i][j]=INF;
       cout<<"Scenario #"<<kas<<"\n";
       kas++;
       memo[1][0]=0;
       q1.push(1);q2.push(0);
       bfs();
       while(query--)
       {
         cin>>depth;
         depth++;
         min=INF;
         if(depth>=node)
          depth=node-1;
         for(i=1;i<=depth;i++)
          if(memo[node][i]!=INF&&min>memo[node][i])
           min=memo[node][i];
         if(min==INF)
          cout<<"No satisfactory flights\n";
         else
          cout<<"Total cost of flight(s) is $"<<min<<"\n";;
       }
       for(i=1;i<=node;i++)
       {adj[i].clear();cost[i].clear();}
    }
    return 0;
}
