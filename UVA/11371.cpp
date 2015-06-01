#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[1000],p[1000],temp;
	long c,d,i,j,z,len;
	bool f;
	while(scanf("%s",s)==1)
	{
		len=strlen(s);
		for(i=0;i<len;i++)
			for(j=i+1;j<len;j++)
				if(s[i]<s[j])
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
		f=1;
		z=j=0;
		for(i=len-1;i>=0;i--)
		{
			if(f&&s[i]=='0')
				z++;
			else
			{
				f=0;
				p[j++]=s[i];
				while(z)
				{
					p[j++]='0';
					z--;
				}
			}
		}
		p[j]='\0';
		c=atol(s);
		d=atol(p);
		printf("%ld - %ld = %ld = %ld * %ld\n",c,d,(c-d),9,((c-d)/9));
	}
	return 0;
}
