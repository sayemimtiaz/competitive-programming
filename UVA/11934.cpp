#include<stdio.h>
int main()
{
	long long a,b,c,d,l,i,cnt;
	while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&l)==5&&(a||b||c||d||l))
	{
		cnt=0;
		for(i=0;i<=l;i++)
			if((a*i*i+b*i+c)%d==0)
				cnt++;
		printf("%lld\n",cnt);
	}
	return 0;
}