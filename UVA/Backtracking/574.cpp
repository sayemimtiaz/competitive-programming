#include<stdio.h>
#include<string.h>
char a[10000],s[10000][50],d[10000];
long no,t,b[100000],save,m,n;
bool vis[100000],got;
void check(long sum,long k,long how)
{
	long j,m;
	if(t==sum)
	{
		a[how]='\0';
		for(j=0;j<save;j++)
			if(!strcmp(s[j],a))
				return;
		printf("%s\n",a);
		got=1;
		strcpy(s[save++],a);
		return;
	}
	for(j=k;j<no;j++)
	{
		if(!vis[j])
		{
			vis[j]=1;
			a[how]='+';
			n=b[j];
			m=0;
			while(n)
			{
				d[m++]=n%10+'0';
				n/=10;
			}
			for(n=m-1;n>=0;n--)
				a[how+1+m-1-n]=d[n];
			check(sum+b[j],j+1,how+m+1);
			vis[j]=0;
		}
	}
}
int main()
{
	long i,j;
	while(scanf("%ld %ld",&t,&no)==2&&no)
	{
		for(i=0;i<no;i++)
			scanf("%ld",&b[i]);
		memset(vis,0,sizeof(vis));
		got=0;
		save=0;
		printf("Sums of %ld:\n",t);
		for(i=0;i<no;i++)
		{
			m=0;
			n=b[i];
			while(n)
			{
				d[m++]=n%10+'0';
				n/=10;
			}
			for(n=m-1;n>=0;n--)
				a[m-1-n]=d[n];
			vis[i]=1;
			check(b[i],i+1,m);
			vis[i]=0;
		}
		if(!got)
			printf("NONE\n");
	}
	return 0;
}