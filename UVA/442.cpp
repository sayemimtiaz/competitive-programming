#include<stdio.h>
char s[1000000];
long x[1000000],y[1000000],m[1000000],n[1000000];
int main()
{
	long i,no,t=0,a,b,res,c,d;
	bool flag,yes[500]={0};
	char str[50000],ch;
	scanf("%ld",&no);
	getchar();
	while(no--)
	{
		gets(str);
		sscanf(str,"%c %ld %ld",&ch,&a,&b);
		x[ch]=a;y[ch]=b;
		yes[ch]=1;
	}
	while(gets(str))
	{
		t=0;res=0;flag=0;
		for(i='A';i<='Z';i++)
			if(yes[i])
			{m[i]=x[i];n[i]=y[i];}
		for(i=0;!flag&&str[i]!='\0';i++)
		{
			if(str[i]!=')')
				s[t++]=str[i];
			else
			{
				t--;
				ch=s[t];
				a=m[s[t]];b=n[s[t]];t--;
				while(s[t]!='(')
				{
					c=m[s[t]];d=n[s[t]];
					if(a!=d)
					{
						flag=1;
						break;
					}
					res+=(c*d*b);
					a=c;
					t--;
				}
				s[t++]=ch;m[ch]=a;n[ch]=b;
			}
		}
		if(flag)
			printf("error\n");
		else
			printf("%ld\n",res);
	}
	return 0;
}