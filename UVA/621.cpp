#include<stdio.h>
#include<string.h>
int main()
{
	int n,len;
	char s[1000];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",&s);
		len=strlen(s);
		if(len<3)
			printf("+");
		else if(s[len-1]=='5'&&s[len-2]=='3')
				printf("-");
		else if(s[0]=='9'&&s[len-1]=='4')
				printf("*");
		else if(s[0]=='1'&&s[1]=='9'&&s[2]=='0')
				printf("?");
		printf("\n");
	}
	return 0;
}