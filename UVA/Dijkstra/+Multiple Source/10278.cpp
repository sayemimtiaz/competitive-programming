#include<cstdio>
#include<vector>
using namespace std;
#define INF 1000000000
struct P
{
    long node,cst; 
}Q[510];
typedef vector<long>vi;
vi adj[510];
vi cost[510];
long qsize,d[510],nd[510];
bool vis[510];
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
void dijkstra1()
{
     long u,v,i;
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
                  if(d[v]>(d[u]+cost[u][i]))
                  {
                     d[v]=d[u]+cost[u][i];
                     if(!vis[v])
                       insert(d[v],v,qsize);
                  }
             }
                                         
       }
}
void dijkstra2()
{
     long u,v,i;
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
                  if(nd[v]>(nd[u]+cost[u][i]))
                  {
                     nd[v]=nd[u]+cost[u][i];
                     if(!vis[v])
                       insert(nd[v],v,qsize);
                  }
             }
                                         
       }
}
int main()
{
    char str[10000];
    long max,node,kase,u,v,c,i,j,k,source,s,min;
    bool flag=0;
    scanf("%ld",&kase);
    while(kase--)
    {
         scanf("%ld %ld",&source,&node);
         for(i=1;i<=node;i++)
            d[i]=INF;
         for(i=0;i<source;i++)
         {
              scanf("%ld",&s);
              d[s]=0;
              Q[i].node=s;Q[i].cst=0;
         }
         qsize=source;
         getchar();
         while(gets(str)&&str[0]!='\0')
         {
            sscanf(str,"%ld %ld %ld",&u,&v,&c);
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
         }
         dijkstra1();
         min=INF;u=1;
         for(i=1;i<=node;i++)
         {
            if(d[i])
            {
                    for(j=1;j<=node;j++)
                       vis[j]=0;
                    k=0;
                for(j=1;j<=node;j++)
                 {  if(d[j])
                    nd[j]=INF;
                   else
                   {
                     Q[k].node=j;Q[k].cst=0;k++;
                     nd[j]=0;
                   }
                 }
                nd[i]=0;qsize=k+1;
                Q[k].node=i;Q[k].cst=0;
                dijkstra2();
                max=-1000;
                for(j=1;j<=node;j++)
                  if(max<nd[j])
                     max=nd[j];
                  if(max<min)
                  {
                     u=i;min=max;
                  }
            }
         }
         if(flag)
           printf("\n");
         flag=1;
         printf("%ld\n",u);
         for(i=1;i<=node;i++)
         {
            vis[i]=0;
            adj[i].clear();
            cost[i].clear();
         }
         
    } 
    return 0;
}
