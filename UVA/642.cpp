#include<stdio.h>
#include<string.h>
char a[1000][1000],b[10000],c[1000][1000];
int t[10000];
int main()
{
	bool flag,print;
	int i,j,k,l1,l2,l,count,h;
	i=0;
	while(scanf("%s",a[i])==1)
	{
		if(strcmp(a[i],"XXXXXX")==0)
			break;
		i++;
	}
	while(1)
	{
		scanf("%s",b);
		if(strcmp(b,"XXXXXX")==0)
			break;
		l1=strlen(b);
		print =false;
		h=0;
		for(j=0;j<i;j++)
		{
			l2=strlen(a[j]);
			if(l1==l2)
			{
				memset(t,0,sizeof(t));
				count=0;
				for(k=0;k<l1;k++)
				{
					flag=false;
					for(l=0;l<l1;l++)
					{
					   if(b[k]==a[j][l]&&t[l]==0)
					   {
						   flag=true;
						   t[l]=1;
						   count++;
						   break;
					   }
					}
					if(!flag)
						break;
					if(count==l1)
					{
						strcpy(c[h],a[j]);
						h++;
					}
				}
			}
		

		}
		for(j=0;j<h;j++)
			for(k=j+1;k<h;k++)
				if(strcmp(c[j],c[k])>0)
				{
					strcpy(b,c[j]);
					strcpy(c[j],c[k]);
					strcpy(c[k],b);
				}
		for(j=0;j<h;j++)
		{
			print=true;
			printf("%s\n",c[j]);
		}
		if(!print)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}