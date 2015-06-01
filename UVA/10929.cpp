#include<iostream.h>
#include<string.h>
int main()
{
	char num[2000];
	long a,b,i,len;
	while(1)
	{
		cin>>num;
		if(strcmp(num,"0")==0)
			break;
		len=strlen(num);
		a=b=0;
		for(i=0;i<len;i++)
		{
			if(i%2)
				a+=(num[i]-'0');
			else
				b+=(num[i]-'0');
		}
		a=a-b;
		if(a<0)
			a=-a;
		if(a%11==0)
			cout<<num<<" is a multiple of 11.";
		else
				cout<<num<<" is not a multiple of 11.";
		cout<<endl;
	}
	return 0;
}
		
