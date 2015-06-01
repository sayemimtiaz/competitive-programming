#include<iostream.h>
int main()
{
	int a[9],i,p,h;
	char s;
	while(cin>>a[0])
	{
		for(i=1;i<9;i++)
			cin>>a[i];
		p=8;
		h=0;
		int count=0;
		for(i=0;i<9;i++)
		{
			if(a[i]!=0)
			{
				if(h==0)
				{
					if(a[i]<0)
					{
						a[i]=-a[i];
						cout<<"-";
					}
					h=1;
				}
				else
				{
					if(a[i]<0)
					{
						a[i]=-a[i];
						cout<<" - ";
					}
					else
						cout<<" + ";
				}
				if(i<8)
				{
					if(i==7&&a[i]==1)
					{
						cout<<"x";
						continue;
					}
					else if(i==7)
					{
						cout<<a[i]<<"x";
						continue;
					}
					if(a[i]==1)
						cout<<"x^"<<p;
					else
				    cout<<a[i]<<"x^"<<p;
				}
				else
					cout<<a[i];
			}
			else 
				count++;
			p--;
		}
		if(count==9)
			cout<<"0";
		cout<<endl;
	}
	return 0;
}