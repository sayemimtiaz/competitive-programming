#include<stdio.h>
#include<string.h>
#define INFINITY -100000000
long d[300][300],w[300][300];
char store[300][100];
long next;
long find(char *s)
{
	long i;
	for(i=0;i<next;i++)
		if(!strcmp(s,store[i]))
			return i;
	strcpy(store[next++],s);
	return next-1;
}
int main()
{
	char s1[10000],s2[10000];
	long i,j,k,a,b,c,s,q,h=1;
	while(1)
	{
		scanf("%ld %ld",&c,&s);
		if(!c&&!s)
			break;
		next=0;
		memset(w,0,sizeof(w));
		for(i=0;i<s;i++)
		{
			scanf("%s %s %ld",s1,s2,&j);
			a=find(s1);
			b=find(s2);
			w[a][b]=w[b][a]=j;
		}
		for(i=0;i<c;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i==j)
					d[i][j]=0;
				else if(w[i][j])
				d[i][j]=w[i][j];
				else
				d[i][j]=INFINITY;
			}
		}
		for(k=0;k<c;k++)
			for(i=0;i<c;i++)
				for(j=0;j<c;j++)
				{
					a=(d[i][k]<d[k][j])?d[i][k]:d[k][j];
					d[i][j]=(d[i][j]>a)?d[i][j]:a;
				}
	
			scanf("%s %s",s1,s2);
			a=find(s1);
			b=find(s2);
				printf("Scenario #%ld\n",h++);
			printf("%ld tons\n",d[a][b]);
		printf("\n");
	}
	return 0;
}