#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char var[1000000],optor[100000];
bool flagtr[1000000],flagend[1000000];
long m,n,opend[10000];
void output()
{
	long i,j;
	bool flag=0;
	j=0;
	for(i=0;i<m;i++)
	{
		if(flag&&!flagend[i])
		{
			for(;j<n;j++)
				if(!flagtr[j])
				{
					printf(" %c ",optor[j]);
					break;
				}
			if(opend[i]<0)
				printf("-%ld",-opend[i]);
			else
				printf("%ld",opend[i]);
			j++;
		}
		else if(!flag&&!flagend[i])
		{
			if(opend[i]<0)
				printf("-%ld",-opend[i]);
			else
				printf("%ld",opend[i]);
			flag=1;
		}
	}
	printf(" = %s\n",var);
}
int main()
{
	char ch[60000],str[60000];
	bool flag,fl;
	long i,j,k;
	while(gets(str))
	{
		flag=0;
		j=k=m=n=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]==' ')
				continue;
			if(flag)
				var[k++]=str[i];
			else if(str[i]<'0'||str[i]>'9')
			{
				if(!j)
				{
					ch[0]=str[i];
					j=1;
				}
				else
				{
				ch[j]='\0';
				opend[m++]=atol(ch);
				j=0;
			    if(str[i]=='=')
				{
				  flag=1;
				  continue;
				}
				optor[n++]=str[i];
				}
			}
			else
			   ch[j++]=str[i];
		}
		memset(flagtr,0,sizeof(flagtr));
		memset(flagend,0,sizeof(flagend));
		var[k]='\0';
		if(fl)
			printf("\n");
		fl=1;
		output();
	   for(i=0;i<n;i++)
		{
			if(optor[i]=='*'||optor[i]=='/')
			{
				flagend[i]=1;
				flagtr[i]=1;
				if(optor[i]=='*')
				    opend[i+1]=opend[i]*opend[i+1];
				else
					opend[i+1]=opend[i]/opend[i+1];
				output();
			}
		}
	   	 for(i=0;i<n;i++)
		{
			if(optor[i]=='-'||optor[i]=='+')
			{
				flagtr[i]=1;
				for(j=0;j<m;j++)
					if(!flagend[j])
					{
						flagend[j]=1;
						break;
					}
				for(k=0;k<m;k++)
					if(!flagend[k])
					{
							break;
					}
				if(optor[i]=='+')
				    opend[k]+=opend[j];
				else
					opend[k]=opend[j]-opend[k];
				output();
			}
		}
	}
	return 0;
}