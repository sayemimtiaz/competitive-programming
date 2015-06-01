#include<cstdio>
#include<vector>
using namespace std;
#define inf 30000
struct P
{
	long node;
	long cst;
}Q[1000];
typedef vector<long>vi;
vi adj[1000];
vi cost[1000];
long qsize;
void heapify(long lrg)
{
	P temp;
	long p,l,r;
	p=lrg;l=2*lrg+1;r=l+1;
	if(l<qsize&&Q[l].cst<Q[p].cst)
		p=l;
	if(r<qsize&&Q[r].cst<Q[p].cst)
		p=r;
	if(p!=lrg)
	{
		temp=Q[p];
		Q[p]=Q[lrg];
		Q[lrg]=temp;
		heapify(p);
	}
}
void insert(long c,long u,long lrg)
{
	while(lrg>0&&Q[lrg/2].cst>c)
	{
		Q[lrg]=Q[lrg/2];
		lrg=lrg/2;
	}
	Q[lrg].node=u;Q[lrg].cst=c;
	qsize++;
}
int main()
{
	long n,e,u,i,v,c,kase;
	long d[1000];
	scanf("%ld",&kase);
	while(kase--)
	{
	scanf("%ld %ld",&n,&e);
	for(i=1;i<=e;i++)
	{
		scanf("%ld %ld %ld",&u,&v,&c);
		adj[u].push_back(v);
		cost[u].push_back(c);
	}
	for(i=1;i<=n;i++)
		d[i]=inf;
	d[1]=0;//d[2]=0;
	Q[0].node=1;Q[0].cst=0;
	//Multiple source
//	Q[1].node=2;Q[1].cst=0;
	qsize=1;
	bool visit[1000]={0};
	while(qsize)
	{
		u=Q[0].node;
		printf("%ld\n",u);
		Q[0]=Q[qsize-1];
		heapify(0);
		qsize--;
		if(visit[u])
		 continue;
		visit[u]=1;
		for(i=0;i<adj[u].size();i++)
		{
			v=adj[u][i];
			if(!visit[v]&&d[v]>cost[u][i]+d[u])
			{
				d[v]=cost[u][i]+d[u];
			//	if(!visit[v])//This is required to cease the infinte loop in case of negative cycle
					insert(d[v],v,qsize);
			}
		}
	}
	for(i=1;i<=n;i++)
		printf(" %ld",d[i]);
	printf("\n");
    }
	return 0;
}
