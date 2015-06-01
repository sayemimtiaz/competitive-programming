#include<iostream>
#include<cmath>
using namespace std;
bool isprime(long a)
{
	if(a==2)
		return true;
	else
	{
	for(long i=2;i<=sqrt(a);)
	{
		if(a%i==0)
			return false;
		if(i==2)
			i++;
		else
			i+=2;
	}
	return true;
	}
}
long int primefactors(long a)
{
	long factor=0,s,m=0;
	for(long i=1;i<=a;i++)
	{
		if(a%i==0&&isprime(i))
		{
			if(m==0)
			{
				s=i;
				factor++;
				m=1;
			}
			else if(i!=s)
			{
				factor++;
				s=i;
			}
			a=a/i;
			i=1;
		}
	}
	return (factor-1);
}
int main()
{
	long a;
	while(1)
	{
		cin>>a;
		if(a==0)
			break;
		cout<<a<<" : "<<primefactors(a)<<endl;
	}
	return 0;
}
