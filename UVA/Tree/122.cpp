#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000000
bool test[SIZE],got;
long arr[SIZE],k,l,fr[SIZE],m,duke_nai;
char store[40000][1500];
bool search(char *s)
{
	long i;
	for(i=0;i<m;i++)
		if(!strcmp(store[i],s))
			return 0;
	return 1;
}
bool process(char *s)
{
	char ch[50000];
	bool h,f1,f2=0;
	long i,len,j=0,a;
	len=strlen(s);
	h=1;
	for(i=0;i<len;i++)
	{
		if(s[i]==','||s[i]==')')
		{
			ch[j]='\0';
			if(h)
			{
				h=0;
				a=atol(ch);
		        arr[k++]=a;
			}
			else if(j==0) 
			{
				f2=1;
				if(!got)
					return 0;
				got=0;
				fr[l++]=0;
				strcpy(store[m++],ch);
			}
			else
			{
				f1=search(ch);
				if(!f1)
					return 0;
				strcpy(store[m++],ch);
				fr[l++]=j;
			}
			j=0;
		}
		else if(s[i]!='(')
		{
			ch[j++]=s[i];
		}
	}
	if(!f2)
		duke_nai++;
	return 1;
}
int main()
{
	char s[50000];
	bool flag,yes;
		char tomp[40000];
	long i,j,temp;
	while(cin>>s)
	{
		k=l=m=0;
		duke_nai=0;
		flag=0;
		yes=1;
		got=1;
		while(1)
		{
			if(!strcmp(s,"()"))
				break;
			flag=process(s);
				if(!flag)
				yes=false;
				cin>>s;
		
		}
		if(duke_nai==k)
			yes=0;
		if(yes)
		{
			for(i=0;i<k;i++)
			{
				for(j=i+1;j<k;j++)
				{
					if(fr[i]>fr[j])
					{
							strcpy(tomp,store[i]);
							strcpy(store[i],store[j]);
							strcpy(store[j],tomp);
						temp=fr[i];
						fr[i]=fr[j];
						fr[j]=temp;
						temp=arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
					}
					else if(fr[i]==fr[j])
					{
						if(strcmp(store[i],store[j])>0)
						{
						
							strcpy(tomp,store[i]);
							strcpy(store[i],store[j]);
							strcpy(store[j],tomp);
						  temp=arr[i];
						  arr[i]=arr[j];
						  arr[j]=temp;
						}
					}
				}
			}
			for(i=0;i<k-1;i++)
			{
				if((fr[i+1]-fr[i])>1)
				{
					yes=0;
					printf("not complete");
					break;
				}
			}
			if(yes)
			{
		for(i=0;i<k;i++)
		{
			printf("%ld",arr[i]);
			if(i<k-1)
				printf(" ");
		}
			}
		}
		else
			printf("not complete");
		printf("\n");
	}
	return 0;
}