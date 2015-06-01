#include<iostream.h>
#include<stdlib.h>
int main()
{
	int t,c1,c2,i,j,a;
	char n[100];
	cin>>t;
	char nigar[10]={'0','1','2','3','4','5','6','7','8','9'};
	int nigar_value[10]={0,1,1,2,1,2,2,3,1,2};
	while(t--)
	{
		cin>>n;
		a=atoi(n);
		c1=0;
		while(a)
		{
			if(a%2)
				c1++;
			a/=2;
		}
		c2=0;
		i=0;
		while(n[i])
		{
			for(j=0;j<10;j++)
				if(n[i]==nigar[j])
				{
					c2+=nigar_value[j];
					break;
				}
				i++;
		}
		cout<<c1<<" "<<c2<<endl;
	}
	return 0;
}