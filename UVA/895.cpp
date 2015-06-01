#include<stdio.h>
#include<string.h>
char str[2000][100],s[10000];
bool flag[10000];
int main()
{
	long i,j,k,m,l,len,cnt,final;
	i=0;
	while(1)
	{
		gets(str[i]);
		if(!strcmp(str[i],"#"))
			break;
		i++;
	}
	while(1)
	{
		
		gets(s);
		if(!strcmp(s,"#"))
			break;
		final=0;
		l=strlen(s);
		for(j=0;j<i;j++)
		{
			len=strlen(str[j]);
			cnt=0;
			memset(flag,0,sizeof(flag));
			for(k=0;k<len;k++)
			{
				for(m=0;m<l;m++)
				{
					if(str[j][k]==s[m]&&!flag[m])
					{
						flag[m]=1;
						cnt++;
						break;
					}
				}
			}
			if(cnt==len)
				final++;
		}
		printf("%ld\n",final);
	}
	return 0;
}