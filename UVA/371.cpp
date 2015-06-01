#include<stdio.h>
int main()
{
	long a,b,temp,j,i,max,count;
	while(1)
	{
		scanf("%ld %ld",&a,&b);
		if(a==0&&b==0)
			break;
		if(a>b)
		{
         	temp=a;
			a=b;
			b=temp;
		}
		temp=0;
		for(i=a;i<=b;i++)
		{
			j=i;
			count=0;
			while(1)
			{
			    if(j%2==0)
					j/=2;
				else
					j=(3*j)+1;
				count++;
				if(j==1)
					break;
			}
			if(temp==0)
			{
				temp=i;
				max=count;
			}
			else if(count>max)
			{
				max=count;
				temp=i;
			}
		}
		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",a,b,temp,max);
	}
	return 0;
}


