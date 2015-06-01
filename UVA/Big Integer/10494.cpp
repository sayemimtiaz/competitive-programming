#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 1000000
char a[size],avg[size],str[size],res[size];
long hold;
void div(char *s,long num)
{
	long i;
	long len=strlen(s);
	for(i=0,hold=0;i<len;i++)
	{
		hold=hold*10+(s[i]-'0');
		res[i]=hold/num+'0';
		hold%=num;
	}
	res[i]='\0';
	for(i=0;res[i]=='0';i++);
	strcpy(avg,&res[i]);
	if(strlen(avg)==0)
		strcpy(avg,"0");
}
int main()
{
	char c,b[10000];
	while(gets(str))
	{
		sscanf(str,"%s %c %s",a,&c,b);
		div(a,atol(b));
		if(c=='/')
			printf("%s\n",avg);
		else
			printf("%ld\n",hold);
	}
	return 0;
}