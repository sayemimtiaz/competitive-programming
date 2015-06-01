#include<stdio.h>
long d[100000],a[100000],b[100000],w[100000],n;
void init()
{
	long i;
	for(i=0;i<n;i++)
		d[i]=1000000000;
	d[0]=0;
}
void relax(long a,long b,long w)
{
	if(d[b]>(d[a]+w))
		d[b]=d[a]+w;
}
int main()
{
    long i,t,edge;
	bool flag;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&edge);
		init();
        for(i=0; i<edge; i++)
            scanf("%ld %ld %ld",&a[i],&b[i],&w[i]);
        for(i=0;i<edge;i++)
			relax(a[i],b[i],w[i]);
		flag=1;
		for(i=0;i<edge;i++)
			if(d[b[i]]>(d[a[i]]+w[i]))
			{
				flag=0;
				break;
			}
		if(!flag)
			printf("possible");
		else
			printf("not possible");
		printf("\n");
    }
    return 0;    
}
