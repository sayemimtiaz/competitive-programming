#include<stdio.h>
main()
{
  long a=0;
 while(scanf("%ld",&a)!=EOF)
 {
   long i=1;
   long sum=1;
  if(a<0)
   {
	 a=-1*a;
	 if(a%2==0)
	  printf("Underflow!");
	 else
	  printf("Overflow!");
	}
  else
   {
   if(a==13)
	printf("6227020800");
  if(a>13)
	printf("Overflow!");
  if(a<8&&a>=0)
	printf("Underflow!");
  if(a>=8 && a<=12)
	{
	   for(i=1;i<=a;i++)
	   sum*=i;
	   printf("%lld",sum);
	 }
   }
	printf("\n");

  }
  return 0;
}