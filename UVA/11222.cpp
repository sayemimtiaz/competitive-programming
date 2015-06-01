#include<stdio.h>
#include<string.h>
int arr[10][50000]={0};
int main()
{
	int kase,s,a,i,j,k,max,h,m,l;
	int in[10]={0,1,2};
	scanf("%d",&kase);
	for(i=1;i<=kase;i++)
	{
		memset(arr,0,sizeof(arr));
		int c[10]={0};
		h=1;
			for(j=0;j<=2;j++)
			{
					scanf("%d",&s);
					for(k=0;k<s;k++)
					{
							scanf("%d",&a);
							if(h)
							{
								h=0;
								max=a;
							}
							else if(a>max)
								max=a;
							arr[j][a]=1;
			
					}
			}
			for(j=0;j<=max;j++)
			{
				if(arr[0][j])
				{
					if(!arr[1][j]&!arr[2][j])
					{
						arr[0][j]=2;
						c[0]++;
					}
				}
				
				 if(arr[1][j])
				{
					if(!arr[0][j]&!arr[2][j])
					{
						arr[1][j]=2;
						c[1]++;
					}
				}
				
		 	if(arr[2][j])
				{
					if(!arr[1][j]&!arr[0][j])
					{
						arr[2][j]=2;
						c[2]++;
					}
				}

			}
			m=c[0];
			in[0]=0;
			k=1;
			for(j=1;j<3;j++)
			{
				if(c[j]>m)
				{
					k=1;
					m=c[j];
					in[0]=j;
				}
				else if(c[j]==m)
				{
					in[k]=j;
					k++;
				}

			}
			printf("Case #%d:\n",i);
			for(j=0;j<k;j++)
			{
				printf("%d %d",(in[j]+1),c[in[j]]);
				for(l=0;l<=max;l++)
				{
					if(arr[in[j]][l]==2)
					   printf(" %d",l);
				}
				printf("\n");

			}
			

	}
			return 0;
}