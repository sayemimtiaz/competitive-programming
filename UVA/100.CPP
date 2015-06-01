#include<stdio.h>
main()
 {
  unsigned long long x=0,y=0;
 while(scanf("%llu %llu",&x,&y)!=EOF)
   {
   unsigned long long  n=1,a=0,k=0,i=0,c=0,d=0;

	  if(x>=y)
		  {c=x;d=y;}
	   else
		  {c=y;d=x;}
		  unsigned long long mm=0;
	 for(i=d;i<=c;i++)
	 {
	  a=i;
	  while(a!=1)
		{
			if(a%2==0)
				 a=a/2;
			else
				 a=(3*a)+1;
			n++;
			if(mm<a)mm=a;
		 }

		if(n>=k)
			k=n;
		  n=1;
	 }
	printf("%llu %llu %llu %llu\n",x,y,k,mm);
	}
 return 0;
}
