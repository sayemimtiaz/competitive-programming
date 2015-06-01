
#include<stdio.h>
#include<string.h>
int main()
{
	char name[1000][1000],a[1000];
	long n,b,c,d,i,j,k;
	int im=0;
	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%s",&name[i]);
		long val[1000]={0};
		for(i=0;i<n;i++)
		{
			scanf("%s %ld %ld",&a,&b,&c);
			for(j=0;j<n;j++)
				if(!strcmp(name[j],a))
					break;
			if(c==0)
				d=0;
			else
			d=b/c;
			val[j]-=(b-(b-(c*d)));
			for(j=0;j<c;j++)
			{
				scanf("%s",&a);
				for(k=0;k<n;k++)
				if(!strcmp(name[k],a))
					break;
				val[k]+=d;
			}
		}
		if(im)
			printf("\n");
		im=1;
		for(j=0;j<n;j++)
		{
			printf("%s %ld\n",name[j],val[j]);
		}
	}
	return 0;
}


