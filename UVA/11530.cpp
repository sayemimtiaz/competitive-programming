
#include<string.h>
#include<stdio.h>
int main()
{
	char store[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
		'w','x','y','z',' '};
	int value[27]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,1};
	int test,count,len,j,k;
	char word[200];
	while(scanf("%d",&test)==1)
	{
	for(int i=0;i<=test;i++)
	{
		gets(word);
		len=strlen(word);
		count=0;
		for(j=0;j<len;j++)
		{
			for(k=0;k<27;k++)
			{
				if(word[j]==store[k])
				{
					count+=value[k];
					break;
				}
			}
		}
		if(i!=0)
		printf("Case #%d: %d\n",i,count);
	}
	}
	return 0;
}