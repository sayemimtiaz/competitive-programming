#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int len;
bool div(char *s,int num)
{
	int hold,i;
	for(i=0,hold=0;i<len;i++)
	{
		hold=hold*10+(s[i]-'0');
		hold%=num;
	}
	return (hold==0)?0:1;
}
int main()
{
    int n,m,kase;
	char c,str[2000];
	scanf("%d",&kase);
	while(kase--)
	{
       scanf("%s",str);
	   scanf("%d",&n);
	   len=strlen(str);
	   bool flag=1;
	   while(n--)
	   {
         scanf("%d",&m);
	    if(div(str,m))
	     flag=0;
      }
      printf("%s - ",str);
      if(flag)
       printf("Wonderful.\n");
      else
       printf("Simple.\n");
   }
   return 0;
}
