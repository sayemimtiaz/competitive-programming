#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 650500
struct graph
{
	long x,y;
	double w;
}gr[size];
long par[size],rank[size];
int cmp(const void *a,const void *b)
{
	graph *x=(graph*)a;
	graph *y=(graph*)b;
	if(x->w>y->w)
		return 1;
	else if(x->w<y->w)
		return -1;
	return 0;
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
	long pox[1000],poy[1000];
	long i,node,a,b,j,k,kase;
	bool flag=0;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&node);
		make_set(node);
		for(i=0;i<node;i++)
			scanf("%ld %ld",&pox[i],&poy[i]);
		k=0;
		for(i=0;i<node;i++)
		{
			for(j=i+1;j<node;j++)
			{
				gr[k].w=(double)sqrt((pox[i]-pox[j])*(pox[i]-pox[j])+(poy[i]-poy[j])*(poy[i]-poy[j]));
				gr[k].x=i;gr[k].y=j;
				k++;
			}
		}
		qsort(gr,k,sizeof(graph),cmp);
		scanf("%ld",&j);
		while(j--)
		{
			scanf("%ld %ld",&a,&b);
			a--;b--;
			a=find(a);b=find(b);
			if(a!=b)
				link(a,b);
		}
		if(flag)
			printf("\n");
		bool yes=0;
		flag=1;
		for(i=0;i<k;i++)
		{
			a=find(gr[i].x);b=find(gr[i].y);
			if(a!=b)
			{
				yes=1;
				printf("%ld %ld\n",gr[i].x+1,gr[i].y+1);
				link(a,b);
			}
		}
		if(!yes)
		printf("No new highways need\n");
	}
	return 0;
}