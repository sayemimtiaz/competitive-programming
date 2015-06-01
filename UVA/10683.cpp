#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char str[100],temp[100];
    long long t4,a;
    while(gets(str))
    {
      temp[0]=str[0];temp[1]=str[1];temp[2]='\0';
      sscanf(temp,"%lld",&a);
      t4=a*60*60*100;
      temp[0]=str[2];temp[1]=str[3];temp[2]='\0';
      sscanf(temp,"%lld",&a);
      t4+=(a*60*100);
      temp[0]=str[4];temp[1]=str[5];temp[2]='\0';
      sscanf(temp,"%lld",&a);
      t4+=(a*100);
      temp[0]=str[6];temp[1]=str[7];temp[2]='\0';
      sscanf(temp,"%lld",&a);
      t4+=a;
      t4*=10000000; 
      t4/=8640000;
      printf("%07lld\n",t4); 
    }
    return 0;
}
