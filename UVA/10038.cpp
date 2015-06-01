#include<iostream.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
int main()
{
	int n,a[3000],b,i;
	while(cin>>n)
	{
		int c[3000]={0};
		if(n==0)
			cout<<"Not jolly";
		else
		{
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(i==0)
				b=a[i];
			else
			{
				c[i-1]=b-a[i];
				if(c[i-1]<0)
					c[i-1]=-c[i-1];
				b=a[i];
			}
		}
		qsort(c,n-1,sizeof(int),comp);
		for(i=0;i<n-1;i++)
		{
			if(c[i]!=i+1)
			{
				cout<<"Not jolly";
				break;
			}
		}
		if(i==n-1)
			cout<<"Jolly";
		}
		cout<<endl;
	}
	return 0;
}