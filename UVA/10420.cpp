
#include<stdio.h>
#include<string.h>
char line[500],country[5000][500],temp[500];
int main()
{
	int test,len,i,j,k,count;
	scanf("%d\n",&test);
	k=0;
	for(i=0;i<test;i++)
	{
		gets(line);
		len=strlen(line);
		for(j=0;;j++)
		{
			if(line[j]==' '||line[j]=='\0')
			{
				country[k][j]='\0';
				break;
			}
		    country[k][j]=line[j];
		}
		k++;
	}
	int b[5000]={0};
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(strcmp(country[i],country[j])>0)
			{
				strcpy(temp,country[i]);
				strcpy(country[i],country[j]);
					strcpy(country[j],temp);
			}
		}
	}
	for(i=0;i<k;i++)
	{
		count=1;
		if(b[i]==0)
		{
		for(j=i+1;j<k;j++)
		{
			if(strcmp(country[i],country[j])==0)
			{
				b[j]=1;
				count++;
			}
		}
		printf("%s %d\n",country[i],count);
		}
	}
	return 0;
}


