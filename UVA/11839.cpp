#include<stdio.h>
int main()
{
	int white,i,j,n,a[10],pos;
	char give[5]={'A','B','C','D','E'};
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		for(i=0;i<n;i++)
		{
			white=0;
		   for(j=0;j<5;j++)
		   {
			   scanf("%d",&a[j]);
			   if(a[j]<=127)
			   {
				   pos=j;
			   }
			   else 
				   white++;
		   }
		   if(white==4)
			   printf("%c",give[pos]);
		   else
			   printf("*");
		   printf("\n");
		}
	}
	return 0;
}

