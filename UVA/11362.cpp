#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char list[12000][20];
int cmp(const void *a,const void *b)
{
	return (strcmp((char*)a,(char*)b));
}
int main()
{
	long i,j,kase,n,k;
	char str[100];
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%s",list[i]);
		qsort(list,n,sizeof(list[0]),cmp);
		bool flag=0;
		for(i=0;i<n-1;i++)
		{
				for(k=0;list[i][k]!='\0';k++)
				   if(list[i][k]!=list[i+1][k])
						break;
				if(list[i][k]=='\0')
				{
					flag=1;
					break;
				}
		}
		if(flag)
			printf("NO\n");
		else
				printf("YES\n");

	}
	return 0;
}