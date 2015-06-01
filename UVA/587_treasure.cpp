#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[2000],*end,ch[2000];
	long len,i,j,k,h=0;
	double x,y,a,d,s;
	while(gets(str)&&str[0]!='E')
	{
		j=0;
		x=10e-12;
        y=10e-12;
        s=sqrt(0.5);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='W'||str[i]=='N'||str[i]=='E'||str[i]=='S')
			{
				ch[j]='\0';
				a=strtod(ch,&end);
				j=0;
				ch[j]=str[i];
				i++;
				if(str[i]!='.'&&str[i]!=',')
				{
					ch[1]=str[i];
					if(ch[0]=='N'&&ch[1]=='W')
					{	x-=(a*s);	y+=(a*s);}
					else if(ch[0]=='S'&&ch[1]=='W')
						{	x-=(a*s);	y-=(a*s);}
					else if(ch[0]=='S'&&ch[1]=='E')
							{	x+=(a*s);	y-=(a*s);}
					else
					 	{	x+=(a*s);	y+=(a*s);}
				}
				else
				{
					if(ch[0]=='N')
						y=y+a;
					else if(ch[0]=='S')
						y=y-a;
					else if(ch[0]=='E')
						x=x+a;
					else if(ch[0]=='W')
						x=x-a;
				}

			}

			else if(str[i]!=','&&str[i]!='.')
			{
				ch[j]=str[i];
				j++;
			}
		}
		d=sqrt((x*x)+(y*y));
		printf("Map #%ld\n",++h);
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
        printf("The distance to the treasure is %.3lf.\n\n",d);
	}
	return 0;
}


