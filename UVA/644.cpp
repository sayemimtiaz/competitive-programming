#include<stdio.h>
#include<string.h>
#include<iostream.h>
char a[10000][100];
int main()
{
	char c[1000],d[1000];
	long i,j,k,l,l1,l2,h,min;
	h=1;
	bool flag,flag1;
	while(cin>>a[0])
	{
		i=1;
		for(;;)
		{
			scanf("%s",a[i]);
			if(a[i][0]=='9')
				break;
			i++;
		}
		flag1=false;
		for(j=0;j<=i;j++)
		{
			l1=strlen(a[j]);
			min=l1;
			strcpy(c,a[j]);
			for(k=j+1;k<=i;k++)
			{
				l2=strlen(a[k]);
				strcpy(d,a[k]);
				if(l1>l2)
				{
					min=l2;
					strcpy(c,a[k]);
					strcpy(d,a[j]);
				}
				l=0;
				flag=false;
				while(c[l])
				{
					if(c[l]!=d[l])
					{
						flag=true;
						break;
					}
					l++;
				}
				if(!flag)
				{
					break;
				}
			strcpy(c,a[j]);
			min=l1;

			}
			if(!flag)
				{
					flag1=true;
					break;
				}
		
		}
		if(!flag1)
			printf("Set %ld is immediately decodable",h);
		else
			printf("Set %ld is not immediately decodable",h);
		h++;
		printf("\n");
	}
	return 0;
}
