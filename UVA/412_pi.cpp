#include<stdio.h>
#include<math.h>
bool isprime(long n)
{
	if(n==1)
		return false;
	
	if(n==2)
		return true;
	
	if(n%2==0)
		return false;
	for(long i=3;i<=sqrt(n);i+=2)
		if(n%i==0)
		return false;
		return true;
}
int main()
{
	long n,i,j,k,im,a[50],index,total,count,p[10000];
	while(1)
	{
		scanf("%ld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
		}
		total=0;
		for(i=0;i<n;i++)
		{
			index=0;
			int flag=0;
			long l;
			im=a[i];
			for(j=2;j<=im;j++)
			{
				if(im%j==0&&isprime(j))
				{
					if(flag==0)
					{
						l=j;
						p[index]=j;
						index++;
						flag=1;
					}
					else if(j!=l)
					{
						l=j;
						p[index]=j;
						index++;
					}
					im/=j;
					j=2;
				}
			}

			count=0;
			for(j=i+1;j<n;j++)
			{
				long yes=0;
				for(k=0;k<index;k++)
				{
				    if(a[j]%p[k]==0)
						yes=1;
				}
				if(yes==0)
					count++;
			}
			total+=count;
		}
		if(total==0)
			printf("No estimate for this data set.");
		else
		{
			long pair=0;
			for(i=n-1;i>=1;i--)
				pair+=i;
			double f=((6*pair)/(double)total);
			f=sqrt(f);
			printf("%0.6lf",f);
		}
		printf("\n");
	}
	return 0;
}

					
