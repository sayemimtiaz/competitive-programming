#include<stdio.h>
#include<string.h>
int main()
{
	char c[10000],b[10000],str[10000];
	int kase,i,j,k,h,len,count;
	scanf("%d",&kase);
	h=0;
	while(kase--)
	{
		scanf("%s",str);
		len=strlen(str);
		i=0;
		while(i<len)
		{
			c[i]=str[i];
			c[i+1]='\0';
			i++;
			if(len%i==0)
			{
				count=0;
				k=0;
				j=0;
			while(j<=len)
			{
				if(k==i)
				{
					b[k]='\0';
					if(strcmp(c,b)==0)
						count++;
					k=0;
					b[k]=str[j];
					k++;
				}
				else
				{
					b[k]=str[j];
					k++;
				}
				j++;
			}
			if(count==(len/i))
				break;
			}
		}
		if(h)
			printf("\n");
		h=1;
		printf("%d\n",i);
	}
	return 0;
}
		
