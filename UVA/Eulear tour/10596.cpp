#include<cstdio>
#include<queue>
#include<vector>

#define SIZE 50000

using namespace std;
	
typedef queue<long> qi;
typedef vector<long> vi;

qi q;
vi gr[SIZE];
long n,in[SIZE],out[SIZE],kaj;
bool vis[SIZE],test[SIZE]; 
void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
        gr[i].clear();
    }
	kaj=0;
    memset(vis,0,sizeof(vis));
	memset(test,0,sizeof(test));
	memset(in,0,sizeof(in));
	
	memset(out,0,sizeof(out));
}


bool bfs(long start)
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
	if(count==kaj)
    return 1;
	return 0;
}



int main()
{
	bool flag;
    long i,a,b,edge;
    while( scanf("%ld %ld",&n,&edge)==2)
    {
		init();
        for(i=0; i<edge; i++)
        {
            scanf("%ld%ld",&a,&b);
            gr[a].push_back(b);
			in[b]++;
			out[a]++;
			if(!test[a])
				kaj++;
			if(!test[b])
				kaj++;
			test[a]=test[b]=1;
        }
		flag=1;
		for(i=0;i<n;i++)
		{
			if(test[i])
			{
				if((in[i]+out[i])%2!=0)
				{

					flag=0;
					break;
				}
			}
		}
		if(flag)
		{
			for(i=0;i<n;i++)
			{
				if(test[i])
				{
					flag=bfs(i);
					break;
				}
			}
		}
		if(edge==0)
			flag=0;
		if(flag)
			printf("Possible");
		else
			printf("Not Possible");
		printf("\n");
	}
	return 0;
}