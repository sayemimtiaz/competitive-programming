#include<stdio.h>
#include<string.h>
char str[10000000],ch[10000000],s[10000000];
int main()
{
	long i,j,k,len;
	while(gets(str))
	{
		j=0;
		len=strlen(str);
		for(i=0;i<=len;i++)
		{
			if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
			{
				ch[j++]=str[i];
			}
			else
			{
					ch[j]='\0';
				if(j!=0)
				{
				    if(ch[0]=='a'||ch[0]=='A'||ch[0]=='e'||ch[0]=='E'||ch[0]=='i'||ch[0]=='I'||ch[0]=='o'||ch[0]=='O'||ch[0]=='u'||ch[0]=='U')
					{
						ch[j++]='a';ch[j++]='y';ch[j]='\0';
						printf("%s",ch);
						
					}
					else
					{
						ch[j++]=ch[0];ch[j++]='a';ch[j++]='y';ch[j]='\0';
						strcpy(s,&ch[1]);
						printf("%s",s);
					}
				}
				j=0;
				if(str[i]!='\0')
			  printf("%c",str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}