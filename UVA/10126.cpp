#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char word[11000][500],again[11000][500];
int t[20000];
int comp(const void *a,const void *b)
{
	return (strcmp((char *)a,(char*)b));
}
int main()
{
	char line[20000],c[20000];
	long n,i,j,k,l,len,count,h;
	h=0;
	while(scanf("%ld\n",&n)==1)
	{
		k=0;
		while(gets(line))
		{
			if(!strcmp(line,"EndOfText"))
				break;
			len=strlen(line);
			j=0;
			for(i=0;i<=len;i++)
			{
		    	line[i]=tolower(line[i]);
				if(line[i]>='a'&&line[i]<='z')
				{
					c[j]=line[i];
					j++;
				}
				else 
				{
					c[j]='\0';
					if(j!=0)
					{
					strcpy(word[k],c);
					k++;
					}
					j=0;
				}
			}
		}
		l=0;
		memset(t,0,sizeof(t));
		for(i=0;i<k;i++)
		{
			if(!t[i])
			{
				count=1;
			for(j=i+1;j<k;j++)
			{
				if(!strcmp(word[i],word[j]))
				{
					t[j]=1;
					count++;
				}
			}
			if(count==n)
			{
			
				strcpy(again[l],word[i]);
				l++;
			}
			}
		}
	qsort((void*)again,l,sizeof(again[0]),comp);
			if(h)
				printf("\n");
			h=1;
			bool yes;
			yes=true;
			for(i=0;i<l;i++)
			{
				yes=false;
			printf("%s\n",again[i]);
			}
			if(yes)
				printf("There is no such word.\n");

	}

	return 0;
}