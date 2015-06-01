

#include<cstdio>
#include<queue>
#include<vector>

#define SIZE 500000

using namespace std;
	
typedef queue<long> qi;
typedef vector<long> vi;

qi q;
vi gr[SIZE];
bool vis[SIZE]; 

long n;

void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
        gr[i].clear();
    }
    memset(vis,0,sizeof(vis));
}


long bfs(long start)
{
    long i,u,next,count=0;
    vis[start]=true;
    q.push(start);
    while(!q.empty())
    {
		count++;
		u=q.front();
        q.pop();
        for(i=0; i<gr[u].size(); i++)
        {
            next=gr[u][i];
            if(vis[next]==false)
            {
				
                q.push(next);
                vis[next]=true;
            }    
        }
    }
	
    return count;
}



int main()
{
    long i,a,b,edge,count,kase,max;
	scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%ld%ld",&n,&edge);
		init();
        for(i=0; i<edge; i++)
        {
            scanf("%ld%ld",&a,&b);
            
            gr[a-1].push_back(b-1);
            gr[b-1].push_back(a-1);
		}
		max=-100000;
		for(i=0;i<n;i++)
		{
			if(vis[i]==false)
			{
               count=bfs(i);
			}
			if(max<count)
				max=count;
        }
		printf("%ld\n",max);
    }
    return 0;    
}
