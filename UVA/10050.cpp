#include<iostream.h>
int main()
{
	long t,n,p,a[1000],i,j,count,lose;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		for(i=0;i<p;i++)
			cin>>a[i];
		count=0;
		lose=0;
		for(i=1;i<=n;i++)
		{
			count++;
			if(count==6)
			{
				continue;
			}
			if(count==7)
			{
				count=0;
				continue;
			}
			for(j=0;j<p;j++)
			{
				if(i%a[j]==0)
				{
					lose++;
					break;
				}
			}
		}
		cout<<lose<<endl;
	}
	return 0;
}
