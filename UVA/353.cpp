#include<stdio.h>
#include<string.h>
char record[6000][100];
int set=0;
int ispal(char *str)
{
	int i,len;
	char copy[100];
	for(i=0;i<set;i++)
		if(strcmp(record[i],str)==0)
			return 0;
	strcpy(record[set],str);
	set++;
	len=strlen(str);
	for(i=len-1;i>=0;i--)
		copy[len-(i+1)]=str[i];
	copy[len]='\0';
	if(strcmp(copy,str)==0)
		return 1;
	else
		return 0;
	
}
int main()
{
	char word[100],c[100];
	int i,len,count,k,j;
	while(scanf("%s",&word)==1)
	{
		set=0;
		len=strlen(word);
		count=0;
		for(i=0;i<len;i++)
		{
			c[0]=word[i];
			c[1]='\0';
			if(ispal(c))
				count++;
			k=1;
			for(j=i+1;j<len;j++)
			{
				c[k]=word[j];
				c[k+1]='\0';
				if(ispal(c))
					count++;
				k++;
			}
		}
		printf("The string '%s' contains %d palindromes.\n",word,count); 
	}
	return 0;

}