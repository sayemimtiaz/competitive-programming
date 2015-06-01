#include<iostream.h>
#include<string.h>
int main()
{
	int g,len,i,j,c,b,a;
	char str[1000];
	while(1)
	{
		cin>>g;
		if(g==0)
			break;
		cin>>str;
		len=strlen(str);
		b=len/g;
		c=0;
		a=b-1;
		for(i=0;i<g;i++)
		{
			for(j=a;j>=c;j--)
				cout<<str[j];
			c=a+1;
			a=a+b;
			
		}
		cout<<"\n";
	}
	return 0;
}

