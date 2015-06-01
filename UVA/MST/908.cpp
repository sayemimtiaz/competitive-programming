#include<stdio.h>
#include<stdlib.h>
#define SIZE 1005555
struct graph
{
	long x,y,w;
}gr[SIZE];
long par[SIZE],rank[SIZE],node;
int cmp(const void *a,const void *b)
{
	graph *m=(graph*)a;
	graph *n=(graph*)b;
	return (m->w-n->w);
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
int main()
{
	bool flag=0;
	long i,a,b,c,sum1,sum2,k,m;
	while(scanf("%ld",&node)==1)
	{
		sum1=sum2=0;
		make_set();
		for(i=1;i<node;i++)
		{
			scanf("%ld %ld %ld",&a,&b,&c);
			sum1+=c;
		}
		scanf("%ld",&k);
		for(i=0;i<k;i++)
		{
			scanf("%ld %ld %ld",&a,&b,&c);
			gr[i].x=a;gr[i].y=b;gr[i].w=c;
		}
		scanf("%ld",&m);
		for(i=k;i<m+k;i++)
		{
			scanf("%ld %ld %ld",&a,&b,&c);
			gr[i].x=a;gr[i].y=b;gr[i].w=c;
		}
		qsort(gr,k+m,sizeof(graph),cmp);
		if(flag)
			printf("\n");
		flag=1;
		for(i=0;i<m+k;i++)
		{
			a=find(gr[i].x);b=find(gr[i].y);
			if(a!=b)
			{
				link(a,b);
				sum2+=gr[i].w;
			}
		}
		printf("%ld\n%ld\n",sum1,sum2);
	}
	
	return 0;
}
