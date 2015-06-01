#include<stdio.h>
#include<string.h>
int main()
{
	char a[10],b[1000];
	int i,flag,print;
	while(1)
	{
		scanf("%s %s",&a,&b);
		if(strcmp(b,"0")==0&&strcmp(a,"0")==0)
			break;
		i=0;
		print=0;
		flag=1;
		while(b[i])
		{
			if(a[0]!=b[i])
			{
				if(flag&&b[i]=='0')
				{
						flag=1;
				}
				else 
				{
					print=1;
					printf("%c",b[i]);
					flag=0;
				}
			}
			i++;
		}
		if(!print)
			printf("0");
		printf("\n");
	}
	return 0;
}
