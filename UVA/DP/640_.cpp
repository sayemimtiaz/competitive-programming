    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>

    #define MAX 1000000

    char table[MAX+2];

    long  sumdigit(long  n)
    {
       long  sum = 0;
       while(n>0)
       {
          sum+=(n%10);
          n/=10;
       }
       return sum;
    }


 void unself(long n)
    {
       long i, sum;
       i = n;
       while(i<=MAX)
       {
          sum = sumdigit(i);
          i+=sum;
		  if(table[i]=='1')
			  return;
          table[i] = '1';

       }
    }
   int main()
    {
       long i;
       memset(table,'0',MAX);

       for(i = 1;i<=MAX;i++)
       {
          if(table[i]=='0')
          {
             printf("%ld\n",i);
             unself(i);
          }
       }
	   printf("1000000\n");
	   return 0;

    }