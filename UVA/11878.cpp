#include<iostream.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[10000],ch[10000],sign;
	long i,j,k,a[10],len,count=0;
	while(cin>>str)
	{
		len=strlen(str);
		j=k=0;
		bool flag=0;
		for(i=0;i<=len;i++)
		{
			if(str[i]=='+'||str[i]=='-'||str[i]=='='||str[i]=='\0')
			{
				if(ch[j-1]=='?')
					flag=1;
				ch[j]='\0';
				a[k++]=atol(ch);
				if(str[i]=='+'||str[i]=='-')
					sign=str[i];
				j=0;
			}
			else
			   ch[j++]=str[i];
		}
		if(sign=='+'&&!flag)
		{
			if(a[0]+a[1]==a[2])
				count++;
		}
		else if(sign=='-'&&!flag)
		{
			if(a[0]-a[1]==a[2])
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}