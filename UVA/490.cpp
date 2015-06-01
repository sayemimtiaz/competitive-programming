#include<iostream.h>
#include<string.h>
#include<stdio.h>
int main()
{
	char str[100][100];
	int i=0,l[100],max,j,k;
	while(gets(str[i]))
	{
		l[i]=strlen(str[i]);
		if(i==0)
			max=l[i];
		else if(l[i]>max)
			max=l[i];
		i++;
	}
	for(j=0;j<max;j++)
	{
		for(k=i-1;k>=0;k--)
		{
			if(j<l[k])
			{
				cout<<str[k][j];
			}
			else 
				cout<<' ';
		}
		if(j<max-1)
		cout<<endl;
	}
	return 0;
}

