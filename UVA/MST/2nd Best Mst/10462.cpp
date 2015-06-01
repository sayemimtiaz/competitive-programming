#include<stdio.h>
#include<stdlib.h>
#define SIZE 500
#define INF 2147483647
struct graph
{
	bool omit;
	long x,y,w;
}gr[SIZE];
long par[SIZE],e,rank[SIZE],edge,node,M,tree[SIZE];
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
	while(a!=par[a])
		a=par[a];
	return a;
}
void kruskal1()
{
	long i,a,b;
	for(i=0;i<edge;i++)
	{
		a=find(gr[i].x);b=find(gr[i].y);
		if(a!=b)
		{
			tree[M++]=i;
			link(a,b);
		}
	}
}
long kruskal2()
{
	long i,a,b,sum=0;
	for(i=0;i<edge;i++)
	{
		if(gr[i].omit)
		{
		a=find(gr[i].x);b=find(gr[i].y);
		if(a!=b)
		{
			e++;
			link(a,b);
			sum+=gr[i].w;
		}
		}
	}
	return sum;
}
int main()
{
	long i,a,b,kase,c,kas=1;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld %ld",&node,&edge);
		make_set();
		for(i=0;i<edge;i++)
		{
			scanf("%ld %ld %ld",&a,&b,&c);
			gr[i].x=a;gr[i].y=b;gr[i].w=c;gr[i].omit=1;
		}
		qsort(gr,edge,sizeof(graph),cmp);
		M=0;
		kruskal1();
		printf("Case #%ld :",kas++);
		if(M+1!=node)
		 printf(" No way\n");
        else
        { 
		a=INF;
		for(i=0;i<M;i++)
		{
			make_set();
			e=0;
			gr[tree[i]].omit=0;
			b=kruskal2();
			if(b<a&&(e+1)==node)
				a=b;
			gr[tree[i]].omit=1;
		}
		if(a!=INF)
			printf(" %ld\n",a);
		else
			printf(" No second way\n",c);
        }
	}
	return 0;
}
