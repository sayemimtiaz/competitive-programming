#include<stdio.h>
#include<string.h>
char str[1000];
long n,min;
void check(long peb,long pos)
{
	if(peb<min)
		min=peb;
	if(str[pos]=='o')
	{
		if((pos+1)<n&&str[pos+1]=='o'&&(pos+2)<n&&str[pos+2]=='-')
		{
			str[pos]='-';str[pos+1]='-';str[pos+2]='o';
			check(peb-1,0);
			str[pos]='o';str[pos+1]='o';str[pos+2]='-';
		}
		if((pos-1)>=0&&str[pos-1]=='o'&&(pos-2)>=0&&str[pos-2]=='-')
		{
			str[pos]='-';str[pos-1]='-';str[pos-2]='o';
			check(peb-1,0);
			str[pos]='o';str[pos-1]='o';str[pos-2]='-';
		}
	}
	if((pos+1)<n)
		check(peb,pos+1);

}
int main()
{
	long kase,i,o;
	scanf("%ld",&kase);
	getchar();
	while(kase--)
	{
		gets(str);
		n=strlen(str);
		o=0;
		for(i=0;i<n;i++)
			if(str[i]=='o')
				o++;
		min=o;
		check(o,0);
		printf("%ld\n",min);
	}
	return 0;
}