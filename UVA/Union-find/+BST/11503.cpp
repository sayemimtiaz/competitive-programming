#include<stdio.h>
#include<string.h>
#define SIZE 200100
struct Tree
{
	char node[21];
	long left,right;
}T[SIZE];
long root=0,ts=1;
long r[SIZE],p[SIZE],len[SIZE];
long BST(char *s)
{
	long temp,c,save;
	save=temp=root;
	while(temp)
	{
		save=temp;
		c=strcmp(s,T[temp].node);
		if(c<0)
			temp=T[temp].left;
		else if(c>0)
			temp=T[temp].right;
		else
			return temp;
	}
	r[ts]=0;p[ts]=ts;len[ts]=1;
	strcpy(T[ts].node,s);
	T[ts].left=T[ts].right=0;
	if(!root)
		root=1;
	else
	{
	if(c<0)
      T[save].left=ts;
	else
		T[save].right=ts;
	}
    ts++;
	return ts-1;
}
void link(long x,long y)
{
	if(r[x]>r[y])
	{
		len[x]=len[y]=len[x]+len[y];
		p[y]=x;
	}
	else
	{
		len[x]=len[y]=len[x]+len[y];
		p[x]=y;
	    if(r[x]==r[y])
		r[y]++;
	}
}
long find(long x)
{
	if(x!=p[x])
		p[x]=find(p[x]);
	return p[x];
}
int main()
{
	long kase,n,a,b;
	char f1[21],f2[21],str[1000];
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		getchar();
		root=0;ts=1;
		while(n--)
		{
			gets(str);
			sscanf(str,"%s %s",f1,f2);
			a=BST(f1);
			b=BST(f2);
			a=find(a);b=find(b);
			if(a!=b)
				link(a,b);
			printf("%ld\n",len[a]);
		}
	}
	return 0;
}