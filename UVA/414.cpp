#include<stdio.h>
#include<string.h>
int main()
{
	int n,count,min,i,d;
	char ch;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		int a[12]={0};
		for(i=0;i<=n;i++)
		{
			while(1)
			{
			 ch=getchar();
			 if(ch==' ' || ch=='B')
				a[i-1]++;
			 if(ch=='\n')
				 break;
			}
			if(i==1)
			{
				min=a[i-1];
			}
			else if(a[i-1]<min)
			{
				min=a[i-1];
			}
		}
		count=0;
		for(i=0;i<n;i++)
		{
			d=a[i]-min;
			count+=d;
		}
		printf("%d\n",count);
	}
	return 0;
}
