#include<stdio.h>
int main()
{
	__int64 n,count,i,j=1,a;
	while(scanf("%I64d",&n)==1&&n)
	{
		count=0;
		for(i=1;;i++)
		{
			a=(n-i);
			if(a%2==0)
				a=a/2-1;
			else
				a/=2;
			if(a-i<=0)
				break;
			count+=(a-i);
		}
		printf("Case %I64d: %I64d\n",j++,count);
	}
	return 0;
}