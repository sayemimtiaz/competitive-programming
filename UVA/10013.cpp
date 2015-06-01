#include<iostream.h>
#include<string.h>
int s[100000];
char res[1000000];
int main()
{
	long n,m,i,j,hold,a,b;
	cin>>n;
	j=0;
	while(n--)
	{
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>a>>b;
			s[i]=a+b;
		}
		hold=0;
		for(i=m-1;i>=0;i--)
		{
			s[i]+=hold;
			if(s[i]>=10)
			{
				res[i]=s[i]%10+'0';
				hold=1;
			}
			else
			{
				hold=0;
				res[i]=s[i]+'0';
			}
		}
		if(j!=0)
			cout<<endl;
		j=1;
		for(i=0;i<m;i++)
			cout<<res[i];
		cout<<endl;
	}
	return 0;
}

