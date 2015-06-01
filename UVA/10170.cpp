#include<iostream.h>
int main()
{
	long long s,d,i,tot;
	while(cin>>s>>d)
	{
		i=s;
		tot=s;
		while(1)
		{
			if(tot>=d)
				break;
			i++;
			tot+=i;
		}
		cout<<i<<endl;
	}
	return 0;
}