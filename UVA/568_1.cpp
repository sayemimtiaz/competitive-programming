    #include <stdio.h>
    int main()
    {
           int N,m[10009];
           m[0]=1;
           unsigned long long fact = 1;

                   for(int i=1; i<=10000; i++)
                   {
                           fact *= i;

                           while( !(fact % 10) )
                              { fact/=10;}

                           fact %= 1000000;
                           m[i]=fact%10;
                   }
           while(~scanf("%d",&N))
           {
               printf("%5d -> %d\n",N,m[N]);
           }

           return 0;
    }
