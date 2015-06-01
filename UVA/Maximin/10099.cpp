#include<stdio.h>
#include<string.h>
#include<math.h>
#define INFINITY -100000000
long d[300][300],w[300][300];
int main()
{
	long i,j,k,a,b,c,s,h=1;
	while(1)
	{
		scanf("%ld %ld",&c,&s);
		if(!c&&!s)
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
					a=(d[i][k]<d[k][j])?d[i][k]:d[k][j];
					d[i][j]=(d[i][j]>a)?d[i][j]:a;
				}
	
			scanf("%ld %ld %ld",&a,&b,&j);
			printf("Scenario #%ld\n",h++);
			printf("Minimum Number of Trips = %0.lf\n",ceil(j/(double)(d[a-1][b-1]-1)));
		printf("\n");
	}
	return 0;
}