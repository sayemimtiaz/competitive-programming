#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct t
{
	long st[100];
}list[10];
char ch[10][10]={"Ja","Sam","Sha","Sid","Tan"};
long find(char *s)
{
	long l;
	for(l=0;l<5;l++)
		if(!strcmp(s,ch[l]))
				return l;
}
int main()
{
	char beg[1000],s[1000];
	long kase,i,save,j,k,l,m,n,a[10000],u[10000],c[10000],sum;
	scanf("%ld",&kase);
	for(k=1;k<=kase;k++)
	{
		scanf("%ld %ld %s",&m,&n,beg);
		for(i=0;i<5;i++)
		{
			scanf("%ld",&a[i]);
			for(j=0;j<a[i];j++)
			{
				scanf("%s",s);
				l=find(s);	
			     list[i].st[j]=l;
			}
		}
		memset(u,0,sizeof(u));
		memset(c,0,sizeof(c));
		sum=0;
		l=find(beg);
		while(1)
		{
			for(i=1;i<=m;i++)
			{
				sum++;
				if(sum<=n)
					c[l]++;
				else
					break;
			}
			sum+=2;
			if(sum>=n)
				break;
			save=l;
			l=list[l].st[u[l]];
			u[save]++;
			if(u[save]>=a[save])
				u[save]=0;
			
		}
		printf("Case %ld:\n",k);
		for(i=0;i<5;i++)
			printf("%s %ld\n",ch[i],c[i]);
	}
	return 0;
}