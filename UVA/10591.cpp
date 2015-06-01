#include<stdio.h>
long a[100000];
int main()
{
	long t,i,j,n,c,d,b;
	bool flag;
	scanf("%ld",&t);
	for(n=0;n<t;n++)
	{
		scanf("%ld",&a[0]);
		b=a[0];
		i=1;
		printf("Case #%ld: %ld ",n+1,a[0]);
		while(1)
		{
		d=0;
		while(b)
		{
			c=b%10;
			d+=(c*c);
			b/=10;
		}
		a[i]=d;
		if(a[i]==1)
		{
			printf("is a Happy number.");
			break;
		}
		flag=false;
		for(j=0;j<i;j++)
		{
			if(d==a[j])
			{
				printf("is an Unhappy number.");
				flag=true;
				break;
			}
		}
		b=d;
		if(flag==true)
			break;
		i++;
		}
		printf("\n");
	}
	return 0;
}
