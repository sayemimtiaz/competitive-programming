#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char msg[10000],s[10000],r[10000];
	int i,len,a;
	while(gets(msg))
	{
		len=strlen(msg);
		for(i=len-1;i>=0;i--)
			s[(len-1)-i]=msg[i];
		s[len]='\0';
		if(s[0]>='0'&&s[0]<='9')
		{
			for(i=0;i<len;i++)
			{
				if(s[i]=='1')
				{
					r[0]='1';r[1]=s[i+1];r[2]=s[i+2];r[3]='\0';
					i+=2;
				}
				else
				{
					r[0]=s[i];r[1]=s[i+1];r[2]='\0';
					i+=1;
				}
				printf("%c",atoi(r));
			}
		}
		else
		{
			for(i=0;i<len;i++)
			{
				a=(int)s[i];
				while(a)
				{
				printf("%d",a%10);
				a/=10;
				}
			}
		}
		printf("\n");
	}
	return 0;
}





