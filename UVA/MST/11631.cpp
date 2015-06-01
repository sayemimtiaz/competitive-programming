#include<stdio.h>
#include<stdlib.h>
#define size 200500
struct graph
{
	long x,y,w;
}gr[size];
long par[size],rank[size];
int cmp(const void *a,const void *b)
{
	graph *x=(graph*)a;
	graph *y=(graph*)b;
	return (x->w-y->w);
}
void make_set(long node)
{
	long i;
	for(i=0;i<node;i++)
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
	while(a!=par[a])
		a=par[a];
	return a;
}
int main()
{
	long i,node,edge,a,b,sum;
	while(scanf("%ld %ld",&node,&edge)==2&&(node||edge))
	{
		make_set(node);
		for(i=0;i<edge;i++)
		{
			scanf("%ld %ld %ld",&gr[i].x,&gr[i].y,&gr[i].w);
		}
		qsort(gr,edge,sizeof(graph),cmp);
		sum=0;
		for(i=0;i<edge;i++)
		{
			a=find(gr[i].x);b=find(gr[i].y);
			if(a!=b)
				link(a,b);
			else
				sum+=gr[i].w;
		}
		printf("%ld\n",sum);

	}
	return 0;
}