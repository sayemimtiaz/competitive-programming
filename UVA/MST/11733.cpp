#include<stdio.h>
#include<stdlib.h>
#define SIZE 120000
struct graph
{
	long x,y,w;
}gr[SIZE];
long par[SIZE],rank[SIZE],N,M,A;
int cmp(const void *a,const void *b)
{
	graph *m=(graph*)a;
	graph *n=(graph*)b;
	return (m->w-n->w);
}
void make_set()
{
	long i;
	for(i=1;i<=N;i++)
	{
		rank[i]=0;
		par[i]=i;
	}
}
void link(long a,long b)
{
	if(rank[a]>rank[b])
		par[b]=a;
	else
	{
		par[a]=b;
		if(rank[a]==rank[b])
			rank[b]++;
	}
}
long find(long a)
{
	if(a!=par[a])
		par[a]=find(par[a]);
	return par[a];
}
long kruskal()
{
	long i,a,b,sum=0,added=0;
	for(i=0;added<N&&i<M&&gr[i].w<A;i++)
	{
		a=find(gr[i].x);b=find(gr[i].y);
		if(a!=b)
		{
			link(a,b);
			sum+=gr[i].w;
			added++;
		}
	}
	return sum;
}
int main()
{
	long i,a,b,c,kase,kas=1;
	scanf("%ld",&kase);
	while(kase--)
	{
	scanf("%ld %ld %ld",&N,&M,&A);
	make_set();
	for(i=0;i<M;i++)
	{
	   scanf("%ld %ld %ld",&a,&b,&c);
	   gr[i].x=a;gr[i].y=b;gr[i].w=c;
	}
	qsort(gr,M,sizeof(graph),cmp);
	b=kruskal();
	a=0;
	for(i=1;i<=N;i++)
 	 if(i==par[i])
  	 a++;
	printf("Case #%ld: %ld %ld\n",kas++,b+a*A,a);
   }
	return 0;
}
