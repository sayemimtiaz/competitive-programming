#include<iostream.h>
int main()
{
	char a[10000];
	long n,i,count,j;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		i=0;
		count=0;
		while(n)
		{
			a[i]=(n%2)+'0';
			if(a[i]=='1')
				count++;
			n=n/2;
			i++;
		}
		cout<<"The parity of ";
		for(j=i-1;j>=0;j--)
			cout<<a[j];
		cout<<" is "<<count<<" (mod 2).";
		cout<<endl;
	}
	return 0;
}
