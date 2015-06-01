#include<stdio.h>
#include<math.h>
bool prime[32768];
long p[32768];
int main()
{
	long m=32767,i,j,cnt,n,b;
	m=sqrt(m);
	for(i=4;i<32768;i+=2)
		prime[i]=1;
	prime[0]=prime[1]=1;
	for(i=3;i<32768;i+=2)
	{
		if(!prime[i])
		{
			if(m>=i)
			for(j=i*i;j<=32767;j+=2*i)
				prime[j]=1;
		}
	}
	for(i=4;i<=32767;i+=2)
	{
		cnt=0;
		for(j=2;j<=(i/2);j++)
		{
			b=i-j;
			if(!prime[j]&&!prime[b])
				cnt++;
		}
		p[i]=cnt;
	}
	while(1)
	{
		scanf("%ld",&n);
		if(n==0)
			break;
		printf("%ld\n",p[n]);
	}
	return 0;
}


