#include<stdio.h>
#include<string.h>
char a[10000],avg[10000];
void add(char *s1,char *s2)
{
	char tmp[10000],res[10000];
	long l1,l2,i,temp,m,n,sum,hold,j;
	l1=strlen(s1);
	l2=strlen(s2);
	if(l2>l1)
	{
		temp=l1;
		l1=l2;
		l2=temp;
		strcpy(tmp,s1);
		strcpy(s1,s2);
		strcpy(s2,tmp);
	}
	m=l1-1;
	n=l2-1;
	for(i=0,hold=0;i<l1;i++)
	{
		if(n>=0)
		sum=(s1[m--]-'0')+(s2[n--]-'0')+hold;
		else
		sum=(s1[m--]-'0')+hold;
		res[i]=sum%10+'0';
		hold=sum/10;
	}
	if(hold)
		res[i++]=hold+'0';
	for(j=i-1;j>=0;j--)
		a[i-1-j]=res[j];
	a[i]='\0';

}
void div(char *s,long num)
{
	char res[10000];
	long i,hold;
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
	char str[10000];
	long  m,n,i,kas=1;
	strcpy(a,"0");
	while(1)
	{
		scanf("%ld %ld",&m,&n);
		if(!m&&!n)
			break;
		for(i=0;i<m;i++)
		{
			scanf("%s",str);
			if(!i)
				strcpy(a,str);
			else
			{
			add(a,str);
			}
		}
		div(a,n);
		printf("Bill #%ld costs %s: each friend should pay %s\n\n",kas++,a,avg);
	}
	return 0;
}