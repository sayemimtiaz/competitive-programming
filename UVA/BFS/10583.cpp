

#include<cstdio>
#include<queue>
#include<vector>

#define SIZE 50000

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


int bfs(long start)
{
    long i,u,next;
    vis[start]=true;
    q.push(start);
    while(!q.empty())
    {
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
	
    return 0;
}



int main()
{
    long i,a,b,j,edge,count;
	j=1;
    while(1)
    {
		count=0;
        scanf("%ld%ld",&n,&edge);
		if(!n&&!edge)
			break;
		init();
        for(i=0; i<edge; i++)
        {
            scanf("%ld%ld",&a,&b);
            
            gr[a-1].push_back(b-1);
            gr[b-1].push_back(a-1);
		}
		for(i=0;i<n;i++)
		{
			if(vis[i]==false)
			{
				count++;
               bfs(i);
			}
        }
		printf("Case %ld: %ld\n",j++,count);
    }
    return 0;    
}
