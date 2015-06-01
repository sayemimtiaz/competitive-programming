#include<stdio.h>
#include<string.h>
char line[1000100],c[1000100],d[1000100];
int main()
{
	long i,j,k,len,count,r;
	bool yes;
	while(1)
	{
		gets(line);
		if(strcmp(line,".")==0)
			break;
		len=strlen(line);
		r=1;
		for(i=0;i<len;i++)
		{
			c[i]=line[i];
			c[i+1]='\0';
			k=0;
			count=1;
			yes=false;
			if(len%(i+1)==0)
			{
			for(j=i+1;j<=len;j++)
			{
				if(k==i+1)
				{
					d[k]='\0';
					if(strcmp(c,d)==0)
					{
						yes=true;
						count++;
					}
					else
					{
						break;
					}
					k=0;
					d[k]=line[j];
					k++;
				}
				else
				{
					d[k]=line[j];
					k++;
				}
			}
			if(yes)
			{
				if((count*(i+1))==len)
				{
					r=count;
				break;
				}
			}
			}
		}
		printf("%ld\n",r);

	}
	return 0;
}