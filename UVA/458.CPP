#include<stdio.h>
#include<string.h>
main()
{
  char ch[10000],k;
  int i=0,j=0;
  while(gets(ch))
  {
	   i= strlen(ch);
		for(j=0;j<i;j++)
			{
			 k=ch[j]-7;
			 printf("%c",k);
			 }
		  printf("\n");
		  }
  return 0;
  }

