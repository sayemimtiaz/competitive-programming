#include<stdio.h>
#include<math.h>
int main()
{
	long a[30][30],sum,i,j,b,c,h=1;
			long k,z;
	double n;
	while(1)
	{
		scanf("%lf",&n);
		if(!n)
			break;
		z=(long int)n;
		for(i=0;i<z;i++)
			for(j=0;j<z;j++)
				scanf("%ld",&a[i][j]);
		b=z;
		c=z-2;
     	z=ceil(n/2);
		printf("Case %ld: ",h++);
		for(i=0;i<z;i++)
		{
			sum=0;
			for(j=i;j<b;j++)
			{
				if((b-i)==1)
					sum+=a[i][j];
				else
				sum+=a[i][j]+a[b-1][j];
			}
			k=i+1;
			for(j=1;j<=c;j++)
			{
				sum+=a[k][i]+a[k][b-1];
				k++;
			}
			b--;
			c-=2;
			printf("%ld",sum);
			if(i<(z-1))
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}