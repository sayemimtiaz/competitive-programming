#include<stdio.h>
#include<string.h>
#include<math.h>
void parse(char *str);
long minbase(char *str);
void process();
unsigned long long todec(char *str,long b);
char n1[50000],n2[50000];
int main()
{
    char str[50000];
    while(gets(str))
    {
      parse(str);
      process();
    }
    return 0;
}
void process()
{
     unsigned long long v1[100],v2[100];
     long a,b,i,j;
     a=minbase(n1);
     b=minbase(n2);
     for(i=a;i<=36;i++)
     {
       v1[i]=todec(n1,i);
     }
      for(j=b;j<=36;j++)
      {
         v2[j]=todec(n2,j);
      }
      for(i=a;i<=36;i++)
       for(j=b;j<=36;j++)
       {
          if(v1[i]==v2[j])
          {
            printf("%s (base %ld) = %s (base %ld)\n",n1,i,n2,j);
            return;
          }
       }
       printf("%s is not equal to %s in any base 2..36\n",n1,n2);
}
void parse(char *str)
{
     long i,j;
     for(i=0;str[i]==' '&&str[i]!='\0';i++);
     j=0;
     for(;str[i]!=' '&&str[i]!='\0';i++)
      n1[j++]=str[i];
     n1[j]='\0';
     for(;str[i]==' '&&str[i]!='\0';i++);
     j=0;
     for(;str[i]!=' '&&str[i]!='\0';i++)
      n2[j++]=str[i];
     n2[j]='\0';
}
long minbase(char *str)
{
     long i,n,max=-100;
     for(i=0;str[i]!='\0';i++)
     {
     if(str[i]>='A'&&str[i]<='Z')
       n=str[i]-55;
     else
      n=str[i]-'0';
      max=(max<n)?n:max;
      }
      return (max!=0)?max+1:max+2;
}
unsigned long long todec(char *str,long b)
{
         unsigned long long s=0;
         long i,j,n;
         long len=strlen(str);
         j=len-1;
         for(i=0;i<len;i++)
         {
         if(str[i]>='A'&&str[i]<='Z')
           n=str[i]-55;
         else
           n=str[i]-'0';
          s+=(n*pow(b,j--));
         }
         return s;
}
