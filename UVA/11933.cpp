#include<stdio.h>
#include<math.h>
int main()
{
    long  n,tt,i,j,k;
    double fR,sR;
    char temp[2000],f[2000],s[2000],a[2000];
    while(scanf("%ld",&n)&&n)
    {
       i=0;
       tt=n;
       while(n>1)
       {
         temp[i++]=n%2+'0';
         n/=2;
       }
       temp[i]='1';
       for(j=0;j<=i;j++)
       {
          f[j]='0';s[j]='0';
       }
       k=1;
       for(j=0;j<=i;j++)
       {
          if(temp[j]=='1')
          { 
             if(k%2)
              f[i-j]='1';
             else
              s[i-j]='1';
              k++;
          }
       }
       k=i;fR=sR=0;
       for(j=0;j<=i;j++)
       {
         fR+=((f[j]-'0')*pow(2,k));
         sR+=((s[j]-'0')*pow(2,k));
         k--;
       }
       printf("%0.lf %0.lf\n",fR,sR);
    }
    return 0;
}
