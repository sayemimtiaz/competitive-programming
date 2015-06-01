#include<iostream.h>
int main()
{
	double a,b,c,test,i;
	cin>>test;
	for(i=0;i<test;i++)
	{
		cin>>a>>b>>c;
		cout<<"Case "<<i+1<<": ";
		if((a+b)>=c&&(a+c)>=b&&(b+c)>=a)
		{
			if(a==b&&b==c)
				cout<<"Equilateral";
			else if(a==b||b==c||a==c)
				cout<<"Isosceles";
			else
				cout<<"Scalene";
		}
		else
			cout<<"Invalid";
		cout<<"\n";
	}
	return 0;
}
