#include<cstdio>
#include<vector>
#include<cstdlib>
#define SIZE 50000
using namespace std;
typedef vector<long> vi;
vi gr[SIZE];
long n,tim;
bool vis[SIZE]; 

typedef struct
{
	long u;
	long v;
}record;
record rec[SIZE];
int comp(const void *a,const void *b)
{
	record *x=(record*)a;
	record *y=(record*)b;
	return (y->u-x->u);
}
void init()
{
    long i;
    
    for(i=0;i<=n;i++)
    {
		rec[i].v=i+1;
		rec[i].u=0;
        gr[i].clear();
    }
	tim=0;
    memset(vis,0,sizeof(vis));
}
void dfs(long a)
{
	long next,i;
	tim++;
	rec[a].u=tim;
	vis[a]=1;
	for( i=0;i<gr[a].size();i++)
	{
		next=gr[a][i];
		if(!vis[next])
			dfs(next);
	}
	tim++;
	rec[a].u=tim;
}
int main()
{
    long i,a,b,edge;
    while(1)
	{
        scanf("%ld %ld",&n,&edge);
		if(!n&&!edge)
			break;
		init();
        for(i=0; i<edge; i++)
        {
            scanf("%ld %ld",&a,&b);
            gr[a-1].push_back(b-1);
        }
        for(i=0;i<n;i++)
			if(!vis[i])
				dfs(i);
		qsort(rec,n,sizeof(record),comp);
        for(i=0;i<n;i++)
		{
			printf("%ld",rec[i].v);
			if(i<n-1)
				printf(" ");
		}
		printf("\n");
    }
    return 0;    
}
