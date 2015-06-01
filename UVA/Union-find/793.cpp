#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000000
long n,par[SIZE],rank[SIZE];
void make_set()
{
	long i;
	for(i=1;i<=n;i++)
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
		par[a]=b;
	if(rank[a]==rank[b])
		rank[b]++;
}
long find(long a)
{
	while(a!=par[a]){a=par[a];}
	return a;
}
int main()
{
	bool f=1;
	char ch[10000],g;
    long a[2],yes,no,kase;
    scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%ld",&n);
		getchar();
		make_set();
		yes=no=0;
        while(gets(ch)&&ch[0]!='\0')
		{
			sscanf(ch,"%c %ld %ld",&g,&a[0],&a[1]);
			if(g=='c')
			{
				a[0]=find(a[0]);a[1]=find(a[1]);
				if(a[0]!=a[1])
				link(a[0],a[1]);
			}
			else
			{
				if(find(a[0])==find(a[1]))
					yes++;
				else
					no++;
			}
        }
		if(!f)
			printf("\n");
		f=0;
		printf("%ld,%ld\n",yes,no);
    }
    return 0;    
}
