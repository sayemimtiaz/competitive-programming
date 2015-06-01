#include<stdio.h>
int main()
{
	long s,max,i,n,a;
	while(1)
	{
		scanf("%ld",&n);
		if(!n)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a);
			if(!i)
			{
				s=a;
				max=s;
			}
			else
			{
				if(max<a)
					max=a;
				s+=a;
				if(max<s)
					max=s;
				if(s<=0)
				{
					if(a<=0)
						s=0;
					else
						s=a;
				}
			}
		}
		if(max<=0)
			printf("Losing streak.\n");
		else
		    printf("The maximum winning streak is %ld.\n",max);
	}
	return 0;
}
				