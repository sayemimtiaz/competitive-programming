#include<stdio.h>
#include<string.h>
int main()
{
	bool f=0;
	char str[50000],res[50000],st[50000];
	long r,p,n,i,sn,jkas=1;
	double d,sd;
	while(1)
	{
		scanf("%ld %ld",&r,&p);
		if(!r&&!p)
			break;
		getchar();
		for(i=0;i<r;i++)
			gets(str);
		for(i=0;i<p;i++)
		{
			gets(str);
			scanf("%lf %ld",&d,&n);
			getchar();
			for(j=0;j<n;j++)
				gets(st);
			if(!i)
			{
				strcpy(res,str);
				sd=d;
				sn=n;
			}
			else if(n>sn)
			{
				strcpy(res,str);
				sd=d;
				sn=n;
			}
			else if(n==sn&&d<sd)
			{
				strcpy(res,str);
				sd=d;
				sn=n;
			}
		}
		if(f)
			printf("\n");
		f=1;
		printf("RFP #%ld\n%s\n",kas++,res);

	}
	return 0;
}
