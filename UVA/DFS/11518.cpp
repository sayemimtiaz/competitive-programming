#include<cstdio>
#include<vector>
#include<cstdlib>

#define SIZE 500000

using namespace std;
typedef vector<long> vi;
vi gr[SIZE];
long n,count;
bool vis[SIZE]; 


void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
        gr[i].clear();
    }
    memset(vis,0,sizeof(vis));
}
void dfs(long a)
{
	long next,i;
	vis[a]=1;
	for( i=0;i<gr[a].size();i++)
	{
		next=gr[a][i];
		if(!vis[next])
		{
			count++;
			dfs(next);
		}
	}
}
int main()
{
    long i,a,b,edge,t,k,l;
    scanf("%ld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%ld %ld %ld",&n,&edge,&l);
		init();
        for(i=0;i<edge;i++)
        {
            scanf("%ld %ld",&a,&b);
            gr[a-1].push_back(b-1);
        }
		count=0;
        for(i=0;i<l;i++)
		{
			scanf("%ld",&a);
			if(!vis[a-1])
				count++;
			dfs(a-1);
		}
		printf("%ld\n",count);
    }
    return 0;    
}
