#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream.h>
int main()
{
	long val;
	int from,to,len,i,j,a;
	bool flag,t;
	char num[100],b[100],c[100];
	char x[6]={'A','B','C','D','E','F'};
	int x_val[6]={10,11,12,13,14,15};
	while(cin>>num>>from>>to)
	{
		val=atol(num);
		while(1)
		{
		i=0;
		if(from==10)
		{
			flag=true;
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
				if(i>7)
				{
					flag=false;
					break;
				}
			}
			if(flag==false)
				printf("  ERROR");
			else
			{
				if(i==0)
					printf("      0");
				else
				{
				for(j=i-1;j>=0;j--)
					c[(i-1)-j]=b[j];
				c[i]='\0';
				printf("%7s",c);
				}
			}
			break;
		}
			else
			{
				i=0;
				len=strlen(num)-1;
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
		printf("\n");
	}
	return 0;
}


