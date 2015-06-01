#include<stdio.h>
#include<math.h>
int main()
{
	long k;
	long double n,a,b,nis,c;
	scanf("%ld",&k);
	while(k--)
	{
		scanf("%Lf",&n);
		n=2*n;
		nis=sqrtl(1+4*n);
		a=(-1+nis)/2;
		a=floor(a);
		printf("%0.Lf\n",a);

	}
	return 0;
}