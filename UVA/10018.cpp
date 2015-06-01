#include<string.h>
#include<stdio.h>
int main()
{
	long test,i,j,len,sum,carry;
	char a[1000],b[1000],c[1000];
	scanf("%ld",&test);
	while(test--)
	{
		scanf("%s",&a);
		j=0;
		while(1)
		{
		len=strlen(a);
		for(i=len-1;i>=0;i--)
			b[(len-1)-i]=a[i];
		b[len]='\0';
		if(!strcmp(a,b))
		{
			printf("%ld %s",j,a); 
			break;
		}
		carry=0;
		for(i=len-1;i>=0;i--)
		{
			sum=(a[i]-'0')+(b[i]-'0')+carry;
			c[(len-1)-i]=sum%10+'0';
			carry=sum/10;
		}
		if(carry!=0)
		{
			c[len]=carry+'0';
			len++;
			c[len]='\0';
		}
		else
			c[len]='\0';
		for(i=len-1;i>=0;i--)
			a[(len-1)-i]=c[i];
		a[len]='\0';
		j++;
	}
		printf("\n");
	}
	return 0;
}
