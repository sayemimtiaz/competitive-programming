#include<stdio.h>
#include<math.h>
int main()
{
    long sol;
    double i,j,s2,s1;
    sol=0;
    i=8;
    while(sol<10)
    {
       s1=(i*(i+1))/2;
       s2=floorl(sqrtl(s1));
       if((s2*s2)==s1)
       {
        sol++;
        printf("%10.0lf%10.0lf\n",s2,i);
         i=i*5;
        continue;
       }
       i++;
       
    }
    return 0;
}
