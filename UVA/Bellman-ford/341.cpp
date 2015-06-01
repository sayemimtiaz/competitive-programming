#include<stdio.h>
#include<string.h>
long d[100000],a[100000],b[100000],w[100000],n,p,par[100000];
void init()
{
	long i;
	for(i=0;i<n;i++)
		d[i]=1000000000;
	d[p-1]=0;
	memset(par,0,sizeof(par));
}
void relax(long a,long b,long w)
{
	if(d[b]>(d[a]+w))
	{
		par[b]=a;
		d[b]=d[a]+w;
	}
}
void print_path(long im,long az)
{
	if(im!=az)
		print_path(im,par[az]);
	printf(" %ld",az+1);
}
int main()
{
    long i,t,edge,kas=1,j,k,e;
    while(1)
    {
        scanf("%ld",&n);
		if(!n)
			break;
		j=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&e);
			for(k=0;k<e;k++)
			{
		      scanf("%ld %ld",&p,&t);
		      a[j]=i;
		      b[j]=p-1;
		      w[j]=t;
			  j++;
			}
		}
		scanf("%ld %ld",&p,&t);
		init();
        for(i=0; i<n-1; i++)
			for(k=0;k<j;k++)
			{
				relax(a[k],b[k],w[k]);
			}
	    printf("Case %ld: Path =",kas++);
		print_path(p-1,t-1);
		printf("; %ld second delay",d[t-1]);
		printf("\n");
    }
    return 0;    
}
