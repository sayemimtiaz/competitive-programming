#include<cstdio>
#include<vector>

#define SIZE 500000

using namespace std;
typedef vector<long> vi;
vi gr[SIZE];
long n,u[SIZE],tim,next;
bool vis[SIZE]; 

typedef struct
{
	long p;
	long v;
}record;
record rec[SIZE];
int comp(const void *a,const void *b)
{
	record *x=(record*)a;
	record *y=(record*)b;
	return (y->v-x->v);
}
void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
		rec[i].v=i;
		rec[i].p=i+1;
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
	rec[a].v=tim;
}
int main()
{
    long i,a,b,j,edge;
 
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
		{
			if(!vis[i])
			{
				dfs(i);
			}
		}
bool	   f=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<gr[i].size();j++)
			{
				next=gr[i][j];
				if(u[next]<=u[i]
                
                &&u[i]<rec[i].v&&rec[i].v<=rec[next].v)
				{
					f=1;
					break;
				}
			}
			if(f)
				break;
		}
		if(!f)
		{
			qsort(rec,n,sizeof(record),comp);
			for(i=0;i<n;i++)
				printf("%ld\n",rec[i].p);

		}
		else
			printf("IMPOSSIBLE\n");

    }
    return 0;    
}
