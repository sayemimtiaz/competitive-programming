#include<stdio.h>
#include<string.h>
int main()
{
	long i,j,kase,n,kas=1;
	bool flag=0,prev;
	char line[2000];
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		getchar();
		if(flag)
			printf("\n");
		flag=1;
		printf("Case %ld:\n",kas++);
		for(i=0;i<n;i++)
		{
			gets(line);
			prev=0;
			for(j=0;line[j]!='\0';j++)
			{
				if(line[j]==' '&&!prev)
				{
					putchar(' ');
					prev=1;
				}
				else if(line[j]!=' ')
				{
					prev=0;
					putchar(line[j]);
				}
			}
				printf("\n");
		}
	
	}
	return 0;
}