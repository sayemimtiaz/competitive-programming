#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 1000000
char equ[15][10]={"0","5","10","15","20","25","30","35","40","45"};
char str[size],res[size];
void bigsub(char first[],char end[])
{
	long lf,ls,i,j,a;
	lf=strlen(first);
	ls=strlen(end);
	if((ls==lf&&strcmp(end,first)>=0)||(ls>lf))
	{
		j=lf;
		lf=ls;
		ls=j;
		strcpy(res,first);
		strcpy(first,end);
		strcpy(end,res);
	}
	ls--;
	for(i=lf-1;i>=0;i--)
	{
			a=first[i]-'0';
		if(ls>=0)
		{
		  if(first[i]<end[ls])
		  {
			  a+=10;
			  if(i-1>=0)
				  first[i-1]=first[i-1]-1;
		  }
		  res[i]=a-(end[ls]-'0')+'0';
		  ls--;
		}
		else
			res[i]=a+'0';
	}
	res[lf]='\0';
	for(i=0;i<lf&&res[i]=='0';i++);
	strcpy(str,&res[i]);
}
int main()
{
	long j,n,l;
	while(scanf("%s",str)==1&&strcmp(str,"0"))
	{
		j=strlen(str)-1;
		l=j+1;
		while(l>9)
		{
			n=str[j]-'0';
			str[j]='\0';
			bigsub(str,equ[n]);
			j--;
			l=strlen(str);
		}
		n=atol(str);
		if((n==0)||(n>=17&&n%17==0))
			printf("1");
		else
			printf("0");
		printf("\n");
	}
	return 0;
}