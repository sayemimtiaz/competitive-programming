#include<stdio.h>
long step;
void recur(long n)
{
   if(!n)
   return;
   long a;
   if(n%2==0)
    recur(n/2);
   else
   {
       a=(n-1)/2;
       if(a==1)
         a=2;
    if(a%2==0)
        recur(n-1);
    else
    {
        a=(n+1)/2;
       if(a%2==0)
        recur(n+1);
   else
    recur(n-1);
}
  }
    step++;
}
int main()
{
    long s;
    while(scanf("%ld",&s)==1)
    {
       step=0;
       recur(s);
       printf("%ld\n",step);                       
    }
    return 0;
}
