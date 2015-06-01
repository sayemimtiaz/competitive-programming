#include<stdio.h>
#include<string.h>
long a[1000000],b[1000000],w[1000000],i,d[1000];
void init()
{
	long j;
	for(j=1;j<i;j++)
		d[j-1]=1000000000;
}
void relax(long a,long b,long w)
{
	if(d[b]>(d[a]+w))
	{
		d[b]=d[a]+w;
	}
}
int main()
{
	char str[10000];
	long sum,l,j,len,k,s[10];
	while(gets(str))
	{
		long st[300]={0},degree[300]={0};
		i=1;
		l=0;
		sum=0;
		while(1)
		{
			if(!strcmp(str,"deadend"))
				break;
			len=strlen(str);
			if(!st[str[0]])
			{
			   st[str[0]]=i;
			   i++;
			}
			if(!st[str[len-1]])
			{
				st[str[len-1]]=i;
				i++;
			}
			sum+=len;
			degree[st[str[0]]-1]++;degree[st[str[len-1]]-1]++;
			a[l]=st[str[0]]-1;b[l]=st[str[len-1]]-1;w[l]=len;
			l++;
			a[l]=st[str[len-1]]-1;b[l]=st[str[0]]-1;w[l]=len;
			l++;
			gets(str);
		}
		k=0;
		for(j=1;j<i;j++)
		{
			if(degree[j-1]%2)
			{
				s[k++]=j-1;
			}
		}
		if(k)
		{
			init();
			d[s[0]]=0;
			for(j=1;j<i-1; j++)
			{
			  for(k=0;k<l;k++)
			  {
				relax(a[k],b[k],w[k]);
			  } 
			}
			sum+=d[s[1]];
		}
		printf("%ld\n",sum);


	}
	return 0;
}
