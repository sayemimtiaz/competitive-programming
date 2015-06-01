#include<stdio.h>
#include<string.h>
char line[120][50];
int main()
{
	long i,j,k,l1,m,n,sum,min,pos;
	while(1)
	{
		gets(line[0]);
		if(!strcmp(line[0],"#"))
			break;
		i=1;
		while(1)
		{
			if(line[i-1][0]=='e')
				break;
			gets(line[i]);
			i++;
		}
		min=100000000;
		for(j=0;j<i-1;j++)
		{
			sum=0;
		    l1=strlen(line[j]);
			for(m=0;m<i-1;m++)
			{
				if(m!=j)
				{
			      for(k=0;k<l1;k+=4)
				  {  
				    for(n=0;n<l1;n++)
					{
					   if(line[j][k]==line[m][n])
						 break;
					}
			        if(line[j][k+2]!=line[m][n+2])
					   sum++;
				  }
			
				}
			}
			if(min>sum)
				{
					pos=j+1;
					min=sum;
				}
		}
		printf("%ld\n",pos);
	}
	return 0;
}