#include<cstdio>
#include<vector>
using namespace std;
#define NN 21000
#define INF 2147483647
typedef vector<long>vi;
vi adj[NN],cost[NN];
struct P
{
       long node;
       long cst;
}Q[NN];
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
    long i,u,v,c,n,m,s,t,kase,kas=1,d[NN];
    bool vis[NN];
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld %ld %ld %ld",&n,&m,&s,&t);
      while(m--)
      {
        scanf("%ld %ld %ld",&u,&v,&c);
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
      }
      for(i=0;i<n;i++)
      {
        vis[i]=0;
        d[i]=INF;
      }
      d[s]=0;
      Q[0].node=s;Q[0].cst=0;
      qsize=1;
      while(qsize)
      {
        u=Q[0].node;
        Q[0]=Q[qsize-1];
        heapify(0);
        qsize--;
        vis[u]=1;
        for(i=0;i<adj[u].size();i++)
        {
           v=adj[u][i];
           if(d[v]>cost[u][i]+d[u])
			{
				d[v]=cost[u][i]+d[u];
				if(!vis[v])
					insert(d[v],v,qsize);
			}
        }
    }
    printf("Case #%ld: ",kas++);
    if(d[t]==INF)
     printf("unreachable\n");
    else
     printf("%ld\n",d[t]);
     for(i=0;i<n;i++)
     {adj[i].clear();cost[i].clear();}
   }
   return 0;
}
