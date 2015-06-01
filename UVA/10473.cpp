#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char num[100];
	long val,i,j,flag,len,k;
	char x[6]={'A','B','C','D','E','F'};
	int x_val[6]={10,11,12,13,14,15};
	while(1)
	{
		scanf("%s",&num);
		if(*num=='-')
			break;
		len=strlen(num);
		if(num[0]=='0'&&num[1]=='x')
		{
			i=2;
			j=3;
			val=0;
			while(num[i])
			{
				flag=0;
				for(k=0;k<6;k++)
					if(num[i]==x[k])
					{
						flag=1;
						break;
					}
				if(flag)
					val+=x_val[k]*pow(16,len-j);
				else
				val+=pow(16,len-j)*(num[i]-'0');
				i++;
				j++;

			}
			printf("%ld",val);
		}
		else
		{
			i=atol(num);
			printf("0x%X",i);
		}
		printf("\n");
	}
	return 0;
}
