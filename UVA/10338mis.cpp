#include<stdio.h>
#include<string.h>
int main()
{
	int test,i,j,k,count,a[20],len;
	scanf("%d",&test);
	char word[20];
	double f,t,y;
	for(i=1;i<=test;i++)
	{
		scanf("%s",&word);
		len=strlen(word);
int		m=0;
		int con[20]={0};
		for(j=0;j<len;j++)
		{
			count=1;
			for(k=j+1;k<len;k++)
			{
				if(word[j]==word[k]&&con[k]==0)
				{
					con[k]=1;
					count++;
				}
			}
			if(count!=1)
			{
				a[m]=count;
				m++;
			}
		}
		f=1;
		for(j=len;j>0;j--)
			f=f*j;
		y=1;
		for(j=0;j<m;j++)
		{
			t=1;
			for(k=a[j];k>0;k--)
			{
				t=t*k;
			}
			y=y*t;
		}
		f=f/y;
		printf("Data set %d: %0.lf\n",i,f);
	}
	return 0;
}

