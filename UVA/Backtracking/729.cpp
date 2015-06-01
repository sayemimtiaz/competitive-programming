#include<stdio.h>
char a[1000];
int n,h;
void fun(int i,int zero)
{
	if(zero>(n-h))
		return;
   if(i>=n)
	{
	   if(zero==n-h)
	   {
	   printf("%s\n",a);
	   }
		return;
	}
   a[i]='0';
	fun(i+1,zero+1);
	a[i]='1';
	fun(i+1,zero);
}
int main()
{
	long kase;
	bool flag=0;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%d %d",&n,&h);
		a[n]='\0';
		if(flag)
			printf("\n");
		flag=1;
	    fun(0,0);
	}
	return 0;
}