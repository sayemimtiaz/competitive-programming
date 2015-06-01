#include<stdio.h>
#define MAXINT 2147483647
int main()
{
	char str[50000],s;
	long double a,b;
	while(gets(str))
	{
		sscanf(str,"%Lf %c %Lf",&a,&s,&b);
		printf("%s\n",str);
		if(a>MAXINT)
			printf("first number too big\n");
		if(b>MAXINT)
			printf("second number too big\n");
	    if(s=='+'&&(a+b)>MAXINT)
		   printf("result too big\n");
		if(s=='*'&&(a*b)>MAXINT)
		   printf("result too big\n");
	}
	return 0;
}