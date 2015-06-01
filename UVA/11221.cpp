#include<stdio.h>
#include<string.h>
#include<math.h>
char str[120][120],nstr[12000];
long a;
bool check()
{
     long i,j,k;
     k=0;
       for(i=0;i<a;i++)
        for(j=0;j<a;j++)
         str[i][j]=nstr[k++];
       k=0;
       for(i=0;i<a;i++)
        for(j=0;j<a;j++)
         if(str[j][i]!=nstr[k++])
          return 0;
         k=0;
       for(i=a-1;i>=0;i--)
        for(j=a-1;j>=0;j--)
         if(str[i][j]!=nstr[k++])
          return 0;
          k=0;
         for(i=a-1;i>=0;i--)
        for(j=a-1;j>=0;j--)
         if(str[j][i]!=nstr[k++])
          return 0;
        return 1; 
}
int main()
{
    char st[12000];
    long kase,i,kas=1,j;
   scanf("%ld",&kase);
   getchar();
   while(kase--)
   {
     gets(st);
     j=0;
     for(i=0;st[i]!='\0';i++)
      if(st[i]>='a'&&st[i]<='z')
       nstr[j++]=st[i];
     nstr[j]='\0';
     a=sqrt(j);
     printf("Case #%ld:\n",kas++);
     if(a*a==j&&check())
       printf("%ld\n",a);
     else
      printf("No magic :(\n");
   }
   return 0;   
}
