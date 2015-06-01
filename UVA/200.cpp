#include<stdio.h>
#include<string.h>
char _2d[100000][50],list[100000];
long L[100000];
bool flag[1000];
int main()
{
	long i,j,k,l,h;
	memset(_2d,'-',sizeof(_2d));
	i=0;
	while(gets(_2d[i]))
	{
		if(strcmp(_2d[i],"#")==0)
			break;
		L[i]=strlen(_2d[i]);
		i++;
	}
	h=0;
	for(j=0;j<i;j++)
	{
		for(k=0;k<i;k++)
		{
			if(L[k]>j&&!flag[_2d[k][j]])
			{flag[_2d[k][j]]=1;list[h++]=_2d[k][j];}
		}
	}
	for(i=0;i<h;i++)
		printf("%c",list[i]);
	printf("\n");
	return 0;
}
