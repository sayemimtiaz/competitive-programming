#include<stdio.h>
int main()
{
	long a,l,i=0,m,term;
	while(1)
	{
		scanf("%ld %ld",&a,&l);
		if(a==-1&&l==-1)
			break;
		term=1;
		i++;
		m=a;
		while(1)
		{
			if(a==1)
				break;
			if(a%2==0)
				a=a/2;
			else
				a=3*a+1;
			if(a>l)
				break;
			term++;
		}
		printf("Case %ld: A = %ld, limit = %ld, number of terms = %ld\n",i,m,l,term);
	}
	return 0;
}