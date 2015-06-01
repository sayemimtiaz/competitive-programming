#include<iostream.h>
int main()
{
	long amp,fre,test,i,j,k,l,a,flag;
	cin>>test;
//	cout<<endl;
	for(i=0;i<test;i++)
	{
		cin>>amp>>fre;
		if(i!=0)
			cout<<"\n";
		for(j=0;j<fre;j++)
		{
			flag=0;
			int g=0;
			for(k=1;k<=((2*amp)-1);k++)
			{
				if(k>amp)
				{
					flag=1;
				}
				if(flag==1)
				{
					if(g==0)
					{
						g=1;
					a=k-2;
					}
					else
					a--;
				}
				else
					a=k;
				for(l=1;l<=a;l++)
				{
					cout<<a;
				}
				cout<<"\n";
			}
			if(j<fre-1)
			cout<<"\n";
		}
	}
	return 0;
}
