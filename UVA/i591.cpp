#include<iostream.h>
int main()
{
	long sum,n,h[50],add;
	int i,g=1;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		sum=add=0;
		for(i=0;i<n;i++)
		{
			cin>>h[i];
			sum+=h[i];
		}
		sum/=n;
		for(i=0;i<n;i++)
		{
			if(h[i]>sum)
				add+=(h[i]-sum);
		}
		cout<<"Set #"<<g<<endl;
		g++;
		cout<<"The minimum number of moves is "<<add<<".\n\n";
	}
	return 0;
}