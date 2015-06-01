#include<stdio.h>
long a[1000100],b[1000100];
int main()
{
	long n,m,i,j,cnt;
	while(1)
	{
		scanf("%ld %ld",&m,&n);
		if(!m&&!n)
			break;
		for(i=0;i<m;i++)
			scanf("%ld",&a[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&b[i]);
		i=j=cnt=0;
		while(i<m&&j<n)
		{
			if(a[i]==b[j])
			{
				i++;j++;
				cnt++;
			}
			else if(a[i]>b[j])
			{
				j++;
				while(j<n&&b[j]<a[i])
					j++;
				if(j<n&&a[i]==b[j])
				{
					j++;
					cnt++;
				}
				i++;
			}
			else
			{
				i++;
				while(i<m&&b[j]>a[i])
					i++;
				if(i<m&&a[i]==b[j])
				{
					i++;
					cnt++;
				}
				j++;
			}
		}
		printf("%ld\n",cnt);
	}
	return 0;
}