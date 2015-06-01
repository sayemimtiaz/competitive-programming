#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
bool isprime(long a)
{
	if(a==1)
		return 0;
	if(a==2)
		return 1;
	if(a%2==0)
		return 0;
	long i;
	for(i=3;i<=sqrt(a);i+=2)
		if(a%i==0)
			return 0;
	return 1;
}
int main()
{
	char str[1000],cpy[1000];
	long len,i;
	bool f1,f2;
	while(gets(str))
	{
		f1=isprime(atol(str));
		len=strlen(str);
		for(i=len-1;i>=0;i--)
			cpy[len-1-i]=str[i];
		cpy[len]='\0';
		f2=isprime(atol(cpy));
		if(f1&&f2&&strcmp(str,cpy))
			printf("%s is emirp.",str);
		else if(f1)
			printf("%s is prime.",str);
		else
			printf("%s is not prime.",str);
		printf("\n");
	}
	return 0;
}