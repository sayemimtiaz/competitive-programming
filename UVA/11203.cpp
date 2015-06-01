#include<stdio.h>
#include<string.h>
int main()
{
	char str[50000],ch[50000];
	long len,M,E,x,y,z,i,j,n;
	bool flag;
	scanf("%ld",&n);
	while(n--)
	{
		flag=1;
		scanf("%s",str);
		len=strlen(str);
		j=0;
		M=0;
		E=0;
		for(i=0;i<=len;i++)
		{
			if(str[i]=='M'||str[i]=='E'||str[i]=='\0')
			{
				ch[j]='\0';
				if(j==0)
				{
					flag=0;
					break;
				}
				if(str[i]=='M')
				{
					M++;
					if(M==2)
					{
						flag=0;
						break;
					}
					x=j;
				}
				else if(str[i]=='E')
				{
					E++;
					if(E==2)
					{
						flag=0;
						break;
					}

					y=j;
				}
				else
					z=j;
				j=0;

			}
			else if(str[i]=='?')
			{
				ch[j++]='?';
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(x+y!=z)
			flag=0;
		if(flag)
			printf("theorem");
		else
			printf("no-theorem");
		printf("\n");


	}
	return 0;
}