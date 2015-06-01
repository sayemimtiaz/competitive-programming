

#include<cstdio>
#include<queue>
#include<vector>

#define SIZE 60000

using namespace std;
	
typedef queue<long> qi;
typedef vector<long> vi;

qi q;
vi gr[SIZE];
bool vis[SIZE]; 

long n,a[SIZE],w[SIZE];

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
    long i,u,next,sum,j;
	j=0;
    vis[start]=true;
	sum=w[start];
    q.push(start);
    while(!q.empty())
    {
		u=q.front();
		a[j]=u;
		j++;
		q.pop();
        for(i=0; i<gr[u].size(); i++)
        {
            next=gr[u][i];
            if(vis[next]==false)
            {
				
                q.push(next);
                vis[next]=true;
				sum+=w[next];
            }    
        }
    }
	if(sum==0)
		for(i=0;i<j;i++)
			w[a[i]]=0;
	
    return 0;
}



int main()
{
    long i,a,b,j,edge,count,kase;
	scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%ld%ld",&n,&edge);
		init();
		for(i=0;i<n;i++)
			scanf("%ld",&w[i]);
        for(i=0; i<edge; i++)
        {
            scanf("%ld%ld",&a,&b);
            
            gr[a].push_back(b);
            gr[b].push_back(a);
		}
		for(i=0;i<n;i++)
		{
			if(vis[i]==false)
			{
               bfs(i);
			}
        }
		bool f=0;
		for(i=0;i<n;i++)
			if(w[i]!=0)
			{
				f=1;
				printf("IMPOSSIBLE\n");
				break;
			}
		if(!f)
			printf("POSSIBLE\n");
    }
    return 0;    
}
