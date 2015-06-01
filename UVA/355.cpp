#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream.h>
int main()
{
	long long val;
	int from,to,len,i,j,a;
	bool t;
	char num[100],b[100],c[100];
	char x[6]={'A','B','C','D','E','F'};
	int x_val[6]={10,11,12,13,14,15};
	while(cin>>from>>to>>num)
	{
		int im=0;
			len=strlen(num)-1;
			for(i=0;i<=len;i++)
			{
				a=num[i]-'0';
				for(j=0;j<6;j++)
					if(num[i]==x[j])
					{
						a=x_val[j];
						break;
					}
				if(a>=from)
				{
					printf("%s is an illegal base %d number",num,from);
					im=1;
					break;
				}
			}
			int fr,too;
			fr=from;
			too=to;
			if(im==0)
			{

		val=atol(num);
		while(1)
		{
		i=0;
		if(from==10)
		{
			while(val)
			{
				t=false;
				a=val%to;
				val/=to;
				for(j=0;j<6;j++)
					 if(a==x_val[j])
					 {
						 t=true;
						 b[i]=x[j];
						 break;
					 }
					 if(t==false)
						 b[i]=a+'0';
				i++;
			}
			if(i==0)
			{
				c[0]='0';
				c[1]='\0';
			}
			else
			{
				for(j=i-1;j>=0;j--)
					c[(i-1)-j]=b[j];
				c[i]='\0';
			}
				printf("%s base %d = %s base %d",num,fr,c,too);
			break;
		}
			else
			{
				i=0;
			
				val=0;
				while(num[i])
				{
					a=num[i]-'0';
					for(j=0;j<6;j++)
					 if(num[i]==x[j])
					 {
						 a=x_val[j];
						 break;
					 }
					val+=a*pow(from,len);
					i++;
					len--;
				}
				from=10;
			}
		}
			}
		printf("\n");
	}
	return 0;
}


