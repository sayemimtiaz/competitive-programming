#include<iostream.h>
int main()
{
	unsigned long a,b;
	while(cin>>a>>b)
	{
		a=a^b;
		cout<<a<<endl;
	}
	return 0;
}