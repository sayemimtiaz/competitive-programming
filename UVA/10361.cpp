#include<stdio.h>
#include<string.h>
char s[10][50000];
int main()
{
	char x[50000],y[50000],c[50000];
	bool flag;
	long n,i,len,j,k;
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		gets(x);
		gets(y);
		len=strlen(x);
		j=k=0;
		flag=0;
		for(i=0;i<=len;i++)
		{
			if(flag&&(x[i]=='>'||x[i]=='<'||x[i]=='\0'))
			{
				c[j]='\0';
				strcpy(s[k++],c);
				if(j!=0)
				printf("%s",c);
				j=0;
			}
			else if(flag)
				c[j++]=x[i];
			if(x[i]=='<')
				flag=1;
			if(!flag)
				printf("%c",x[i]);
		}
		len=strlen(y);
			printf("\n");
		for(i=0;i<len;i++)
		{
			if(y[i]=='.')
				break;
			printf("%c",y[i]);
		}
		if(strlen(s[2])!=0)
			printf("%s",s[2]);
		if(strlen(s[1])!=0)
			printf("%s",s[1]);
		if(strlen(s[0])!=0)
			printf("%s",s[0]);
		if(strlen(s[3])!=0)
			printf("%s",s[3]);
		printf("\n");
	}
	return 0;
}
