#include<stdio.h>
#include<math.h>
int isprime(int n)
{
	if(n==2)
		return 1;
	if(n%2==0)
		return 0;
	for(int i=3;i<=sqrt(n);i+=2)
		if(n%i==0)
			return 0;
		return 1;
}
int main()
{
	int n,a,i,j,k;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		int b[100]={0};
		for(i=2;i<=n;i++)
		{
			a=i;
			for(j=2;j<=a;j++)
			{
				if(a%j==0&&isprime(j))
				{
					b[j]++;
					a/=j;
					j=1;
				}
			}
		}
		j=1;
		printf("%3d! =%3d",n,b[2]);
		for(i=3;;i+=2)
		{
			if(i==99)
				break;
			if(b[i]==0&&isprime(i))
				break;
			if(b[i]==0)
				continue;
			
			if(j%15==0)
				printf("\n      %3d",b[i]);
			else
				printf("%3d",b[i]);
			j++;
		}
		printf("\n");
	}
	return 0;
}
