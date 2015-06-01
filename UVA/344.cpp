#include<stdio.h>
#include<string.h>
int main()
{
	char dec[19][5]={"1","5","10","50","100","4","9","40","90","2","3","6","7","8","20","30","60","70","80"};
	char roman[19][5]={"i","v","x","l","c","iv","ix","xl","xc","ii","iii","vi","vii","viii","xx","xxx","lx","lxx","lxxx"};
	char res[100],c[100],str[100],flag;
	int i,j,len,count,l,a,k;
	while(scanf("%d",&a)==1)
	{
		if(a==0)
			break;
		int count[100]={0};
		for(k=1;k<=a;k++)
		{
				flag=0;
				i=0;
				l=k;
				while(l)
				{
					c[i]=(l%10+'0');
					i++;
					l/=10;
				}
				c[i]='\0';
				for(l=i-1;l>=0;l--)
					str[(i-1)-l]=c[l];
				str[i]='\0';
		for(i=0;i<19;i++)
			if(strcmp(str,dec[i])==0)
			{
				flag=1;
				strcpy(res,roman[i]);
			}
		
		if(flag==0)
		{
			c[0]=str[0];
			c[1]='0';
			c[2]='\0';
			for(i=0;i<19;i++)
			if(strcmp(c,dec[i])==0)
			{
				strcpy(res,roman[i]);
				break;
			}
			c[0]=str[1];
			c[1]='\0';
			for(i=0;i<19;i++)
			if(strcmp(c,dec[i])==0)
			{
				strcat(res,roman[i]);
				break;
			}
		}
		len=strlen(res);
		for(i=0;i<5;i++)
		{
			for(j=0;j<len;j++)
			{
				if(roman[i][0]==res[j])
				{
					count[i]++;
				}
			}
		}
		}
		printf("%d: ",a);
		for(i=0;i<5;i++)
		{
			printf("%d %c",count[i],roman[i][0]);
			if(i<4)
				printf(", ");
		}
		printf("\n");
	}
	return 0;
	}
