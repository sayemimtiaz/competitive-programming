#include<stdio.h>
#include<string.h>
char word[1500][700],line[100000],c[100000];
int main()
{
	long long sum;
	long i,j,k,len,val[1500],m,n;
	while(scanf("%ld %ld",&n,&m)==2)
	{
		for(i=0;i<n;i++)
			scanf("%s %ld\n",word[i],&val[i]);
		for(i=0;i<m;i++)
		{
			sum=0;
			while(1)
			{
				gets(line);
				if(strcmp(line,".")==0)
					break;
				k=0;
				len=strlen(line);
				for(j=0;j<=len;j++)
				{
					if(line[j]==' '||line[j]=='\0')
					{
						c[k]='\0';
						for(k=0;k<n;k++)
							if(strcmp(c,word[k])==0)
							{
								sum+=val[k];
							}
						k=0;
					}
					else
					{
						c[k]=line[j];
						k++;
					}
				}
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}
