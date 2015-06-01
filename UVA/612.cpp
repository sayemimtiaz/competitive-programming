#include<stdio.h>
#include<string.h>
int main()
{
	int data,i,j,k,h=0,b[1000],n,m,t,max;
	char a[1000][1000],temp[1000];
	scanf("%d",&data);
	while(data--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			b[i]=0;
			scanf("%s",a[i]);
			for(j=0;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					if(a[i][k]<a[i][j])
						b[i]++;
				}
			}
			if(i==0)
				max=b[i];
			else if(b[i]>max)
				max=b[i];
		}
				if(h==1)
			printf("\n");;
		h=1;
		for(i=0;i<=max;i++)
		{
			for(j=0;j<m;j++)
			{
			if(b[j]==i)
				printf("%s\n",a[j]);
			}
		}

	}
	return 0;
}