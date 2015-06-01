#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
	char *x=(char*)a;
	char *y=(char*)b;
	return *x-*y;
}
int main()
{
	char line[2000],s[2000],a,b;
	int test,len,i,j,index,count,max;
	int imtiaz;
scanf("%d\n",&test);
	//while(scanf("%d\n",&test)==1)
	//{
	while(test--)
	{
		imtiaz=0;
		gets(line);
		len=strlen(line);
		index=0;
		int d[2000]={0};
		for(i=0;i<len;i++)
		{
			a=tolower(line[i]);
			if(d[i]==0&&a>='a'&&a<='z')
			{
				count=1;
			for(j=i+1;j<len;j++)
			{
			   b=tolower(line[j]);
			   if(a==b)
			   {
				   d[j]=1;
				   count++;
			   }
			}
			if(imtiaz==0)
			{
				imtiaz=1;
				max=count;
				s[index]=a;
				index++;
			}
			else if(count>max)
			{
				index=0;
				max=count;
				s[index]=a;
				index++;
			}
			else if(count==max)
			{
				s[index]=a;
				index++;
			}
			}
		}
		qsort(s,index,sizeof(char),comp);
		for(i=0;i<index;i++)
			printf("%c",s[i]);
		printf("\n");
	}
	//}
	return 0;
}