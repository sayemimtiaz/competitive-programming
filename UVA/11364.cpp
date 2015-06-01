#include<iostream.h>
int main()
{
	long t,a,max,min,i,b;
	cin>>t;
	while(t--)
	{
		cin>>b;
		for(i=0;i<b;i++)
		{
			cin>>a;
			if(i==0)
			{
				max=a;
			}
			else if(a>max)
				max=a;
			if(i==0)
				min=a;
			if(a<min)
				min=a;
		}
		a=max-min;
		cout<<(2*a)<<endl;
	}
	return 0;
}