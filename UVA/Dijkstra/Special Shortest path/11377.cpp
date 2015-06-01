#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define INF 100000000
#define SIZE 3000
struct P
{
	long node;
	long cst;
}Q[SIZE];
typedef vector<long>vi;
vi adj[SIZE];
vi cost[SIZE];
bool visit[SIZE],air[SIZE];
long qsize,set,par[SIZE];
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
void path(long a)
{
     if(a==-1)
      return;
     if(!air[a])
      set++;
     path(par[a]);
}
int main()
{
	long s,k,n,m,e,u,i,v,c,kase,kas=1;
	long d[SIZE];
	scanf("%ld",&kase);
	while(kase--)
	{
	scanf("%ld %ld %ld",&n,&m,&k);
	memset(air,0,sizeof(air));
	for(i=1;i<=k;i++)
	{ scanf("%ld",&u);air[u]=1;}
	for(i=1;i<=m;i++)
	{
		scanf("%ld %ld",&u,&v);
		adj[u].push_back(v);adj[v].push_back(u);
		if(air[v])
		cost[u].push_back(0);
		else
		cost[u].push_back(1);
		if(air[u])
		cost[v].push_back(0);
		else
		cost[v].push_back(1);
	}
	scanf("%ld",&k);
	printf("Case %ld:\n",kas++);
	while(k--)
	{
     scanf("%ld %ld",&s,&m);
	for(i=1;i<=n;i++)
		{d[i]=INF;par[i]=-1;}
	  memset(visit,0,sizeof(visit));
	d[s]=0;
	Q[0].node=s;Q[0].cst=0;
	qsize=1;
	while(qsize)
	{
		u=Q[0].node;
		Q[0]=Q[qsize-1];
		heapify(0);
		qsize--;
		visit[u]=1;
		for(i=0;i<adj[u].size();i++)
		{
			v=adj[u][i];
			if(d[v]>d[u]+cost[u][i])
			{
				d[v]=d[u]+cost[u][i];
				par[v]=u;
				if(!visit[v])
					insert(d[v],v,qsize);
			}
		}
	}
	if(s==m)
	printf("0");
	else if(d[m]==INF)
	 printf("-1");
    else
    {
        set=0;
        path(m);
        printf("%ld",set);
    }
    printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
      cost[i].clear();
      adj[i].clear();
      }
}
	return 0;
}
