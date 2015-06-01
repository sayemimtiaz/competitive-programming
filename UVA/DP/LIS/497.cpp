#include<stdio.h>
#include<string.h>
#define MAXN 5000
long a[MAXN],len[MAXN],pa[MAXN];
void pr(long k)
{
if(pa[k]==k)
{
    printf("%ld\n",a[k]);
	return;
}
pr(pa[k]);
printf("%ld\n",a[k]);
}

int main()
{
    char str[MAXN];
	long ka,i,j,k;
	long max,s;
	bool h=0;
    scanf("%ld",&ka);
    getchar();
    getchar();
	while(ka--)
	{
 	i=0;
		while(gets(str)&&strlen(str)>0)
		{	sscanf(str,"%ld",&a[++i]);
        }
		for(j=1;j<=i;j++)
		{
           pa[j]=j;
           len[j]=1;
        }
        max=1;s=1;
		for(j=1;j<i;j++)
			for(k=j+1;k<=i;k++)
				if(a[k]>a[j])
				if(len[j]+1>len[k])
				{
					len[k]=len[j]+1;
					if(max<len[k])
					 {s=k;max=len[k];}
					pa[k]=j;
				}
				if(h)
					printf("\n");
				h=1;
				printf("Max hits: %ld\n",max);
				pr(s);
	}

	return 0;
}
