#include<stdio.h>
#include<math.h>
int main()
{
	unsigned long long i,j,k;
	long double n,a[20],b;
	while(1)
	{
		scanf("%Lf",&n);
		if(!n)
			break;
		a[0]=floorl((n*10)/9);//for using fun floor instead of floorl i got wrong
		j=1;
		for(i=a[0]-10;i<=a[0]+10;i++)
		{
			if(i!=a[0])
			{
				b=floorl(i/10);
				if((i-b)==n)
				{
					a[j]=i;
					j++;
				}
			}
		}
		for(i=0;i<j;i++)
		{
			for(k=i+1;k<j;k++)
			{
				if(a[i]>a[k])
				{
					n=a[i];
					a[i]=a[k];
					a[k]=n;
				}
			}
		}
		for(i=0;i<j;i++)
		{
			printf("%0.Lf",a[i]);
			if(i<j-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
