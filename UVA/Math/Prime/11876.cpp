#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 1000100
long a[SIZE],N[SIZE],C[SIZE],k=0;
long NOD(long n)
{
	if(n==1)
		return 1;
	long div=2;
	long m=sqrt(n);
	long i;
	for(i=2;i<=m;i++)
		if(n%i==0)
		{
			if((n/i)!=i)
				div+=2;
			else
				div++;
		}
	return div;

}
void precal()
{
	long a;
	N[0]=1;
	C[1]=1;
	for(k=1;;k++)
	{
		a=N[k-1]+NOD(N[k-1]);
		if(a>1000000)
			break;
		N[k]=a;
		C[a]=k+1;
	}
	long i;
	for(i=1;i<=SIZE-10;i++)
	{
		if(C[i]==0)
			C[i]=C[i-1];
	}

}
bool binser(long a)
{
	long b,e,m;
	b=0;
	e=k-1;
	while(b<=e)
	{
		m=(b+e)/2;
		if(N[m]==a)
			return 1;
		else if(N[m]>a)
			e=m-1;
		else
			b=m+1;
	}
	return 0;
}
int main()
{
	long l,u,kase,kas,r,i;
	precal();
	scanf("%ld",&kase);
	kas=1;
	while(kase--)
	{
		scanf("%ld %ld",&l,&u);
		i=l;
		while(i<=u&&!binser(i))
			i++;
		if(i>u)
		{
				printf("Case %ld: 0\n",kas++);
				continue;
		}
		l=i;
		i=u;
		while(i>=l&&!binser(i))
			i--;
		u=i;
		printf("Case %ld: %ld\n",kas++,C[u]-C[l]+1);
	}
	return 0;
}