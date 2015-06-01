#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char store[20][1000];
long i,size,a[10000];
bool vis[1000];
void check(long k,long how)
{
	long j;
	if(how==size)
	{
		for(j=0;j<size;j++)
		{
			printf("%s",store[a[j]]);
			if(j<size-1)
				printf(", ");
		}
		printf("\n");
		return;
	}
	for(j=k;j<i;j++)
	{
		if(!vis[j])
		{
			vis[j]=1;
			a[how]=j;
			check(j+1,how+1);
			vis[j]=0;
		}
	}
}
int main()
{
	bool flag=0;
	long kase,s,e,j,c;
	char str[10000];
	scanf("%ld",&kase);
	gets(str);
	gets(str);
	for(NULL;kase--;NULL)
	{
		gets(str);
     c = sscanf(str, "%ld%ld", &s, &e);
   i = 0;
     for (NULL; gets(store[i]) && store[i][0]; i++); 
		if(c==0)
		{s=1;e=i;}
		else if(c==1)
		{s=s;e=s;}
		memset(vis,0,sizeof(vis));
		for(size=s;size<=e;size++)
		{
			printf("Size %ld\n",size);
			for(j=0;j<i;j++)
			{
				a[0]=j;
				vis[j]=1;
				check(j+1,1);
				vis[j]=0;
			}
			printf("\n");
		}
		if(kase)
			printf("\n");

	}
	return 0;
}