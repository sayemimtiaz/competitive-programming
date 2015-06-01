#include<stdio.h>
#include<stdlib.h>
#define SIZE 20000
#define INF 1000000000
struct graph
{
	long x,y,w;
}gr[SIZE];
long par[SIZE],e,rank[SIZE],edge,node;
int cmp(const void *a,const void *b)
{
	graph *x=(graph*)a;
	graph *y=(graph*)b;
	return (x->w-y->w);
}
void make_set()
{
	long i;
	for(i=1;i<=node;i++)
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
	long i,a,b,sum=0;
	for(i=0;i<edge;i++)
	{
		a=find(gr[i].x);b=find(gr[i].y);
		if(a!=b)
		{
			link(a,b);
			sum+=gr[i].w;
		}
	}
	return sum;
}
int main()
{
	long i,a,b,c;
		scanf("%ld %ld",&node,&edge);
		make_set();
		for(i=0;i<edge;i++)
		{
			scanf("%ld %ld %ld",&a,&b,&c);
			gr[i].x=a;gr[i].y=b;gr[i].w=c;
		}
		qsort(gr,edge,sizeof(graph),cmp);
		printf("%ld",kruskal());
	
	return 0;
}
