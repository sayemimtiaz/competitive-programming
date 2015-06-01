#include<iostream.h>
double a[100000];
int main()
{
	int i,j,count,n;
	double x,y;
	i=0;
	char ch;
	while(1)
	{
		cin>>ch;
		if(ch=='*')
			break;
		n=i+4;
		for(;i<n;i++)
			cin>>a[i];
	}
	j=1;
			n=i/4;
	while(1)
	{
		cin>>x>>y;
		if(x==9999.9&&y==9999.9)
			break;
		count=0;
		int k=0;
		for(i=0;i<n;i++)
		{
			if((x>a[k]&&x<a[k+2])&&(y<a[k+1]&&y>a[k+3]))
				cout<<"Point "<<j<<" is contained in figure "<<i+1<<endl;
			else
				count++;
			k+=4;
		}
		if(count==n)
			cout<<"Point "<<j<<" is not contained in any figure"<<endl;
		j++;
	}
	return 0;
}