#include<stdio.h>
#include<string.h>
char str[1000][1000];
long val[1000];
int main()
{
	char st[10000];
	long kase,n,take,i,kas=1;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			gets(st);
			sscanf(st,"%s %ld",str[i],&val[i]);
		}
		scanf("%ld",&take);
		scanf("%s",st);
		for(i=0;i<n;i++)
			if(!strcmp(st,str[i]))
				break;
		printf("Case %ld: ",kas++);
		if(i<n)
		{
			if(val[i]<=take)
				printf("Yesss");
			else if((take+5)>=val[i])
				printf("Late");
			else
				printf("Do your own homework!");
		}
		else
				printf("Do your own homework!");
		printf("\n");

	}
	return 0;
}