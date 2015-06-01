#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 30000
struct graph
{
	int x,y,w;
}gr[SIZE];
int par[SIZE],rank[SIZE],N,M;
bool s[SIZE];
int cmp(const void *a,const void *b)
{
	graph *m=(graph*)a;
	graph *n=(graph*)b;
	return (m->w-n->w);
}
void make_set()
{
	int i;
	for(i=0;i<N;i++)
	{
		rank[i]=0;
		par[i]=i;
	}
}
void link(int a,int b)
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
int find(int a)
{
	if(a!=par[a])
		par[a]=find(par[a]);
	return par[a];
}
void kruskal()
{
	int i,a,b;
	for(i=0;i<M;i++)
	{
		a=find(gr[i].x);b=find(gr[i].y);
		if(a!=b)
			link(a,b),s[i]=1;
	}
}
int main()
{
	int i;
	while(scanf("%d %d",&N,&M)&&(N||M))
	{
	make_set();
	for(i=0;i<M;i++)
	   scanf("%d %d %d",&gr[i].x,&gr[i].y,&gr[i].w);
	qsort(gr,M,sizeof(graph),cmp);
	kruskal();
	bool flag=0;
	for(i=0;i<M;i++)
	 if(s[i]==0)
	 {
      if(flag)
       printf(" ");
      flag=1;
	  printf("%d",gr[i].w);
     }
     if(!flag)
      printf("forest");
     printf("\n");
     memset(s,0,sizeof(s));
   }
	return 0;
}
