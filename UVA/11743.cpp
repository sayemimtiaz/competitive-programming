#include<stdio.h>
int main()
{
	char digit[100];
	int a,n,i,b,j;
	scanf("%d\n",&n);
	while(n--)
	{
		gets(digit);
		i=0;
		b=0;
		j=1;
		while(digit[i])
		{
			if(digit[i]>='0'&&digit[i]<='9')
			{
			if(j==1)
			{
				j=2;
				a=(digit[i]-'0')*2;
				a=(a%10)+(a/10);
			}
			else
			{
				j=1;
				a=digit[i]-'0';
			}
			b+=a;
			}
			i++;
		}
		if(b%10==0)
			printf("Valid");
		else
			printf("Invalid");
		printf("\n");
	}
	return 0;
}

