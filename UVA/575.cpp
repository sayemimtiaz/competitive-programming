#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char a[1000];
	long i,j,len,sum;
	while(1)
	{
		scanf("%s",&a);
		if(strcmp(a,"0")==0)
			break;
		len=strlen(a);
		j=len;
		sum=0;
		for(i=0;i<len;i++)
		{
			sum+=((a[i]-'0')*(pow(2,j)-1));
			j--;
		}
		printf("%ld\n",sum);
	}
	return 0;
}
