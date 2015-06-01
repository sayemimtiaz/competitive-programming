#include<stdio.h>
#include<math.h>
int main()
{
	long kase,M,N,X,i,kas=1;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&N);
		M=sqrt(N);
		printf("Case %ld:",kas++);
		for(i=M;i>=1;i--)
		{
			X=N-i*i;
			if(X%i==0&&X)
				printf(" %ld",X);
		}
		printf("\n");
	}
	return 0;
}