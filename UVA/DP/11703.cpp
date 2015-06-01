#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 1000000
long  ache[1000005];
 void x( )
{
		ache[0]=1;
	 long i,a,c,b;
	 for(i=1;i<=N;i++)
	 {
		 a=i-sqrt(i);
		 b=log(i);
		 c=i*sin(i)*sin(i);
		ache[i]=ache[a]%1000000+ache[b]%1000000+ache[c]%1000000;
		ache[i]%=1000000;
	}
}
int main()
{
	long n;
	x();
	while(1)
	{
		scanf("%ld",&n);
		if(n==-1)
			break;
		printf("%ld\n",ache[n]%1000000);
	}
	return 0;
}
