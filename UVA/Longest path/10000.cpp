#include<stdio.h>
#include<string.h>
#define INFINITY -100000000
long d[120][120],w[120][120];

int main()
{
	long max,i,j,k,a,b,s,kas=1,n,l;
	while(1)
	{
		scanf("%ld",&n);
		if(!n)
			break;
		scanf("%ld",&s);
		memset(w,0,sizeof(w));
		while(1)
		{
			scanf("%ld %ld",&a,&b);
			if(!a&&!b)
				break;
			w[a-1][b-1]=1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(w[i][j])
				d[i][j]=w[i][j];
				else
				d[i][j]=INFINITY;
			}
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(d[i][j]<(d[i][k]+d[k][j]))
						d[i][j]=(d[i][k]+d[k][j]);
				}
			}
		}
		max=INFINITY;
		printf("Case %ld: ",kas++);
		for(i=0;i<n;i++)
		{
			if((s-1)!=i&&d[s-1][i]>0)
			{
				if(d[s-1][i]>max)
				{
					l=i+1;
					max=d[s-1][i];
				}
			}
		}
		printf("The longest path from %ld has length %ld, finishing at %ld.\n\n",s,max,l);


	}
	return 0;
}