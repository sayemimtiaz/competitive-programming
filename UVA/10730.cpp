#include<stdio.h>
long a[100000];
long t[100000];
int main()
{
	bool flag;
	long n,i,j,d,s;
	while(1)
	{
		scanf("%ld%*c",&n);
		if(!n)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			t[a[i]]=i;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				flag=0;
				s=a[j]+a[j]-a[i];
				if(s>=n||s<0)
					continue;
				if(t[s]>j)
				{
					flag=1;
					break;
				}	
			}
			if(flag)
				break;
		}
		if(flag)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}