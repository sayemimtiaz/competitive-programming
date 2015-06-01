#include<stdio.h>
#include<string.h>
int main()
{
	char ch[]={'B','U','S','P','F','T','M'};
	long long ch_val[]={1,10,100,1000,10000,100000,1000000};
	char line[10000];
	long long kase,sum,i,j,len,s,c[1000];
	bool flag,flag_2,flag_3;
	scanf("%lld",&kase);
	while(kase--)
	{
		memset(c,0,sizeof(c));
		scanf("%s",line);
		len=strlen(line);
		flag=0;
		flag_2=1;
		sum=0;
		for(i=0;i<len;i++)
		{
		  for(j=0;j<7;j++)
			if(line[i]==ch[j])
				break;
		  c[j]++;
		  
		  if(c[j]>9)
		  {	
			  flag=1;
			  break;
		  }
		  if(i==0)
		  {
			  s=j;
		  }
		  else if(j>s&&flag_2)
		  {
			  flag_2=0;
			  s=j;
			  flag_3=1;
		  }
		  else if(j<s&&flag_2)
		  {
			  flag_2=0;
			  s=j;
			  flag_3=0;
		  }
		  else
		  {
			  if(flag_3&&j<s)
			  {
				  flag=1;
				  break;
			  }
			  else if(!flag_3&&j>s)
			  {
				  flag=1;
				  break;
			  }
			  s=j;
		  }
		  sum+=ch_val[j];
		}
		if(flag)
			printf("error\n");
		else
			printf("%lld\n",sum);
		}
	return 0;
}