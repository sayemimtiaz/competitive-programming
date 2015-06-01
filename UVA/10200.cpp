#include<stdio.h>
#include<math.h>
bool isprime(long a)
{
	if(a==1)
		return false;
	if(a==2)
		return true;
	if(a%2==0)
		return false;
	for(long i=3;i<=sqrt(a);i+=2)
		if(a%i==0)
			return false;
		return true;
}
int main()
{
	long a,b,n,i;
	int arr[15000]={0};
	for(i=0;i<=11000;i++)
	{
		n=41+i+(i*i);
		if(isprime(n))
			arr[i]=1;
	}
	long d,count,t;
	while(scanf("%ld %ld",&a,&b)==2)
	{
		count=0;
		for(i=a;i<=b;i++)
			if(arr[i])
				count++;
			printf("%0.2lf\n",(count * 100.0) / (double)(b - a + 1) + 1e-9);
	}
	return 0;
}
			

	
