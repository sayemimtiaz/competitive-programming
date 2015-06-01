#include<cstdio>
#include<vector>

#define SIZE 50000

using namespace std;
typedef vector<long> vi;
vi gr[SIZE];
long n,u[SIZE],v[SIZE],tim;
bool vis[SIZE]; 


void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
		v[i]=i;
        gr[i].clear();
    }
	tim=0;
    memset(vis,0,sizeof(vis));
	memset(u,0,sizeof(u));
}
void dfs(long a)
{
	long next,i;
	tim++;
	u[a]=tim;
	vis[a]=1;
	for( i=0;i<gr[a].size();i++)
	{
		next=gr[a][i];
		if(!vis[next])
			dfs(next);
	}
	tim++;
	u[a]=tim;
}
int main()
{
    long count,i,a,b,j,edge,t,temp,k;
    scanf("%ld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%ld %ld",&n,&edge);
		init();
        for(i=0; i<edge; i++)
        {
            scanf("%ld %ld",&a,&b);
            gr[a-1].push_back(b-1);
        }
        for(i=0;i<n;i++)
		{
			if(!vis[i])
			{
				dfs(i);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(u[i]<u[j])
				{
					temp=u[i];
					u[i]=u[j];
					u[j]=temp;
					temp=v[i];
					v[i]=v[j];
					v[j]=temp;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		tim=0;
		count=0;
        for(i=0;i<n;i++)
		{
			if(!vis[v[i]])
			{
				dfs(v[i]);
				count++;
			}
		}
		printf("Case %ld: %ld\n",k,count);
    }
    return 0;    
}
