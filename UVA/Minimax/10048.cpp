#include<stdio.h>
#include<string.h>
#define INFINITY 100000000
long d[120][120],w[120][120];

int main()
{
	bool flag=1;
	long i,j,k,a,b,c,s,q,h=1;
	while(1)
	{
		scanf("%ld %ld %ld",&c,&s,&q);
		if(!c&&!s&&!q)
			break;
		memset(w,0,sizeof(w));
		for(i=0;i<s;i++)
		{
			scanf("%ld %ld %ld",&a,&b,&j);
			w[a-1][b-1]=w[b-1][a-1]=j;
		}
		for(i=0;i<c;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i==j)
					d[i][j]=0;
				else if(w[i][j])
				d[i][j]=w[i][j];
				else
				d[i][j]=INFINITY;
			}
		}
		for(k=0;k<c;k++)
			for(i=0;i<c;i++)
				for(j=0;j<c;j++)
				{
					a=(d[i][k]>d[k][j])?d[i][k]:d[k][j];
					d[i][j]=(d[i][j]<a)?d[i][j]:a;
				}
	
	
		for(i=0;i<q;i++)
		{
			scanf("%ld %ld",&a,&b);
			if(!flag&&!i)
				printf("\n");
			if(!i)
				printf("Case #%ld\n",h++);
			if(d[a-1][b-1]==INFINITY)
				printf("no path\n");
			else
			printf("%ld\n",d[a-1][b-1]);
		}
		flag=0;
	}
	return 0;
}