#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 char dic[50000][30],out[50000][30];
int main()
{
	char que[40];
	long n,l1,l2,cnt,i,j,k,l,t;
	scanf("%ld",&n);
	bool fl=0;
	while(n--)
	{
		for(i=0;;i++)
		{
			scanf("%s",dic[i]);
			if(!strcmp(dic[i],"#"))
				break;
		}
		bool on=0;
		while(1)
		{
			scanf("%s",que);
			if(!strcmp(que,"#"))
				break;
			if(!on&&fl)
				printf("\n");
			fl=1;
			on=1;
			l1=strlen(que);
			bool flag=0;	
			k=0;
			for(j=0;j<i;j++)
			{
				if(!strcmp(dic[j],que))
				{
					flag=1;
					break;
				}
				else
				{
			     l2=strlen(dic[j]);
				 
				if((l1-l2)==0||abs(l1-l2)==1)
				{
					cnt=t=0;
					if(l1>l2)
					{
					for(l=0;l<l2;l++)
					{
						for(;t<l1;t++)
						  if(dic[j][l]==que[t])
						  {
							  t++;
							  cnt++;
							  break;
						  }
					}
					if(cnt==l1-1)
							strcpy(out[k++],dic[j]);
					}
					else if(l1<l2)
					{
						
					for(l=0;l<l1;l++)
					{
						for(;t<l2;t++)
						  if(que[l]==dic[j][t])
						  {
							  t++;
							  cnt++;
							  break;
						  }
					}
					if(cnt==l2-1)
							strcpy(out[k++],dic[j]);
					}
					else
					{
								for(l=0;l<l1;l++)
					{
						  if(que[l]==dic[j][l])
						  {
							  cnt++;
						  }
					}
					if(cnt==l2-1)
							strcpy(out[k++],dic[j]);
					}
				}
				}
			}
	
			if(flag)
				printf("%s is correct",que);
			else
			{
				printf("%s:",que);
				for(j=0;j<k;j++)
					printf(" %s",out[j]);
			}
			printf("\n");
		}
	}
		return 0;
	}


			