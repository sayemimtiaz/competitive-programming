#include<stdio.h>
#include<string.h>
#include<ctype.h>
char c[1000000],ex[30][100000],word[30][100000],line[1000000],a;
int main()
{
	long az,i,j,im,k,len,l,n,m,count,max;
	bool h;
	az=0;
	while(scanf("%ld %ld",&n,&m)==2)
	{
		im=0;
		h=true;
		for(i=0;i<n;i++)
			scanf("%s",word[i]);
		getchar();
		for(i=0;i<m;i++)
		{
			count=0;
			gets(line);
			len=strlen(line);
			k=0;
			for(j=0;j<=len;j++)
			{
				a=tolower(line[j]);
			  if((a>='a'&&a<='z'))
				{
					c[k]=a;
					k++;
				}
				else
				{
					c[k]='\0';
					if(k!=0)
					{
					for(l=0;l<n;l++)
						if(strcmp(c,word[l])==0)
						{
							count++;
						}
					}
					k=0;
				}
			}
			if(h)
			{
				strcpy(ex[im++],line);
				max=count;
				h=false;
			}
			else if(count>max)
			{
				im=0;
				strcpy(ex[im++],line);
				max=count;
			}
			else if(count==max)
			{
				strcpy(ex[im++],line);
			}

		}
		printf("Excuse Set #%ld\n",++az);
		for(i=0;i<im;i++)
			printf("%s\n",ex[i]);
		printf("\n");
			
	}

	return 0;
}