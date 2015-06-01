#include<stdio.h>
int p[1000],r[1000],n;
void make_set()
{
	int i;
	for(i=1;i<=n;i++)
	{
		r[i]=0;
		p[i]=i;
	}
}
void link(int x,int y)
{
	if(r[x]>r[y])
	{
		p[y]=x;
		r[x]++;
    }
	else
	{
		p[x]=y;
		r[y]++;
    }
}
int find(int x)
{
	if(x!=p[x])
		p[x]=find(p[x]);
	return p[x];
}
int main()
{
	int i,e,x,y;
	scanf("%d %d",&n,&e);
	make_set();
	for(i=1;i<=e;i++)
	{
		scanf("%d %d",&x,&y);
		x=find(x);
		y=find(y);
		if(x!=y)
		  link(x,y);
	}
	for(i=1;i<=n;i++)
		printf("Node %d Parent %d Rank %d\n",i,p[i],r[i]);
	scanf("%d",&i);
	return 0;
}
