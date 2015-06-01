#include<iostream.h>
#include<stdlib.h>
#include<string.h>
int comp_1(const void *a,const void *b)
{
	char *x=(char*)a;
	char *y=(char*)b;
	return *y-*x;
}
int comp_2(const void *a,const void *b)
{
	char *x=(char*)a;
	char *y=(char*)b;
	return *x-*y;
}
int main()
{
		char str[80];
		long a,b,d,s[100000],g;
		int l=0;
		while(1)
		{
		 cin>>str;
		  if(l==1)
			cout<<endl;
		 if(*str=='0')
			 break;
		 int j=0;
		
		 l=1;
		 int flag=0;
		 cout<<"Original number was "<<str<<endl;
		 while(1)
		 {
		    int i=strlen(str);
	        qsort(str,i,sizeof(char),comp_1);
			a=atol(str);
			qsort(str,i,sizeof(char),comp_2);
			b=atol(str);
			d=a-b;
			cout<<a<<" - "<<b<<" = "<<d<<endl;
			
				for(g=0;g<j;g++)
				{
					if(s[g]==d)
					{
						flag=1;
				        break;
					}
				}
				if(flag==1)
					break;
				s[j]=d;
				j++;
			int k=0;
			if(d==0)
			{
				str[k]='0';
				k++;
			}
			else
			{
			while(d)
			{
				a=d%10;
				d/=10;
				str[k]=a+'0';
				k++;
			}
			}
			str[k]='\0';
		 }
		 cout<<"Chain length "<<j+1<<endl;
		}
	return 0;
}
