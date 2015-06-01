#include<stdio.h>
#include<string.h>
bool t[100000];
long m,k,n,i,l;
long for_a()
{
	long j;
	j=0;
	for(;;)
	{
		if(!t[i])
			j++;
		if(j==k)
			return i;
		i++;
		if(i>n)
			i=1;
		
	}
	return -1;
}
long for_b()
{
	long j;
	j=0;
	for(;;)
	{
		if(!t[l])
			j++;
		if(j==m)
			return l;
		l--;
		if(l<1)
			l=n;
	}
	return -1;
}
int main()
{
	long j;
	while(1)
	{
		scanf("%ld %ld %ld",&n,&k,&m);
		if(!n&&!k&&!m)
			break;
		memset(t,0,sizeof(t));
		j=0;
		i=1;
		l=n;
		while(1)
		{
			for_a();
			for_b();
			t[i]=t[l]=1;
			if(i!=l)
			{
				j+=2;
				printf("%3ld%3ld",i,l);
			}
			else
			{
				j++;
				printf("%3ld",i);
			}
			if(j<n)
				printf(",");
			if(j==n)
				break;
		}
		printf("\n");
	}
	return 0;
}