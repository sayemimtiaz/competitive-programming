#include<stdio.h>
#include<string.h>
char line[200][200];
int main()
{
	int n,l,i,j,kas=1;
	while(scanf("%d",&n)&&n)
	{
        getchar();
		for(i=0;i<n;i++)
			gets(line[i]);
		printf("Case %d:\n",kas++);
		printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
		for(i=0;i<n;i++)
		{
			printf("printf(\"");
			l=strlen(line[i]);
			for(j=0;j<l;j++)
			{
			    if(line[i][j]=='"')
				{
						printf("\\\"");
				}
				else if(line[i][j]=='\\')
				{
					printf("\\\\");
				}
				else
					printf("%c",line[i][j]);
			}
			printf("\\n\");\n");

		}
		printf("printf(\"\\n\");\n");
		printf("return 0;\n}\n");
	}
	return 0;
}
