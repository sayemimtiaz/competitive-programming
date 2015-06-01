#include<stdio.h>
#include<string.h>
char str,c[1000000],temp[1000000];
int main()
{
	char save;
	bool final,num,e,flag,got;
	long j,r,m;
	while(1)
	{
		final=flag=num=e=got=0;
		j=r=m=0;
		while(str=getchar())
		{
			if(str=='*')
				break;
			if(str=='\n')
				break;
			if(got&&str==' ')
				temp[m++]=' ';
			else if(got&&m!=0&&str!=' ')
			{
				final=1;
				temp[m]='\0';
				strcat(c,temp);
				j+=m;
				c[j++]=str;
				c[j]='\0';
				temp[0]='\0';
				m=0;
				continue;
			}
			if(str==' ')
				continue;
			got=1;
				c[j++]=str;
				c[j]='\0';
			if(str=='+'||str=='-')
			{
						if(j!=1)
				if(save!='e'&&save!='E')
					final=1;
				save=str;
				continue;
			}
	else if(str=='e'||str=='E')
		r++;
	save=str;
			if(r>1)
				final=1;
			if(str>='0'&&str<='9')
				num=1;
			else if(str=='.')
			{
				if(e)
					final=1;
				if(!flag)
				{
					if(!num)
					{
						final=1;
					}
					num=0;
					flag=1;
				}
				else
				{
					final=1;
				}
			}
			else if(str=='e'||str=='E')
			{
				e=1;
				if((flag&&!num)||(!flag&&!num))
				{
					final=1;
				}
				num=0;
			}
			else
				final=1;
		}
		if(str=='*')
			break;
		if((e&&!num)||(flag&&!num)||(!flag&&!e))
					final=1;
		if(final)
			printf("%s is illegal.\n",c);
		else
			printf("%s is legal.\n",c);
	}
	return 0;
}