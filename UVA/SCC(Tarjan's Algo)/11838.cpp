

#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#define MAXN 2500

using namespace std;
	
typedef vector <long>vi;
vi grap1[MAXN],grap2[MAXN];
bool vis[MAXN]; 
long n,cnt1,cnt2;

void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
       grap2[i].clear();
        vis[i]=0;
       grap1[i].clear();
    }
}
void dfs1(long cur)
{
     long i,next;
     vis[cur]=1;
     cnt1++;
     for(i=0;i<grap1[cur].size();i++)
     {
       next=grap1[cur][i];
       if(!vis[next])
         dfs1(next);
     }
}
void dfs2(long cur)
{
     long i,next;
     vis[cur]=1;
     cnt2++;
     for(i=0;i<grap2[cur].size();i++)
     {
       next=grap2[cur][i];
       if(!vis[next])
         dfs2(next);
     }
}
int main()
{
    long i,a,b,j,edge,t;
    while(scanf("%ld %ld",&n,&edge)&&(n||edge))
    {
                     init();
        for(i=0;i<edge; i++)
        {
            scanf("%ld %ld %ld",&a,&b,&t);
            grap1[a].push_back(b);
            grap2[b].push_back(a);
            if(t==2)
            {
             grap1[b].push_back(a);
             grap2[a].push_back(b);
            }
		}
       cnt1=0;
       dfs1(1);
       cnt2=0;
       memset(vis,0,sizeof(vis));
       dfs2(1);
       if(cnt1==cnt2&&cnt1==n)
        printf("1\n");
       else
        printf("0\n");
    }
    return 0;    
}
