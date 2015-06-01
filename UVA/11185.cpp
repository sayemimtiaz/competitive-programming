#include<stdio.h>
int main()
{
	long a,i;
	char b[100000];
	while(1)
	{
		scanf("%ld",&a);
		if(a<0)
			break;
		i=0;
		if(a==0)
			printf("0");
		else
		{
		while(a)
		{
			b[i]=(a%3+'0');
			a=a/3;
			i++;
		}
		while(i)
		{
			printf("%c",b[i-1]);
			i--;
		}
		}
		
		printf("\n");
	}
	return 0;
}