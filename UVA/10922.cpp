#include<iostream.h>
#include<string.h>
int main()
{
	char num[2000];
	long i,a,b,flag,count,len;
	while(1)
	{
		cin>>num;
		if(strcmp(num,"0")==0)
			break;
		 len=strlen(num);
		 a=0;
		for(i=0;i<len;i++)
		{
			a+=(num[i]-'0');
		}
		count=1;
		flag=0;
		while(1)
		{
			if(a!=9&&a<10)
			{
				flag=0;
				break;
			}
			if(a==9)
			{
				flag=1;
				break;
			}
			b=0;
			while(a)
			{
				b+=(a%10);
				a=a/10;
				if(a<10)
				{
					b+=a;
					break;
				}
			}
			a=b;
			count++;
		}
		if(flag==1)
			cout<<num<<" is a multiple of 9 and has 9-degree "<<count<<".";
		else
			cout<<num<<" is not a multiple of 9.";
		cout<<endl;
	}
	return 0;
}

