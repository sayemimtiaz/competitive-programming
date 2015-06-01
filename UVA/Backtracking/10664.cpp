#include<stdio.h>
#include<stdlib.h>
long a[100],s,k;
bool flag,vis[100];
void check(long sum)
{
	if(flag||sum==s/2)
	{
		flag=1;
		return;
	}
	long i;
	for(i=0;i<k;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			check(sum+a[i]);
			vis[i]=0;
		}
	}
}
int main()
{
	long i,kase,j;
	char str[1000],ch[1000];
	scanf("%ld",&kase);
	getchar();
	while(kase--)
	{
		gets(str);
		j=k=s=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]==' ')
			{
				if(j)
				{
					ch[j]='\0';
					a[k++]=atol(ch);
					vis[k-1]=0;
					s+=a[k-1];
					j=0;
				}
			}
			else
				ch[j++]=str[i];
		}
		if(j)
		{
			ch[j]='\0';
			a[k++]=atol(ch);
			s+=a[k-1];
			vis[k-1]=0;
			j=0;
		}
		flag=0;
		if(s%2==0)
		{
			for(i=0;i<k&&!flag;i++)
			{
				vis[i]=1;
			   check(a[i]);
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}