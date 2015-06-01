#include<stdio.h>
#define SIZE 1000000
long hh[SIZE],ll[SIZE],h,l,n;
bool ishigh()
{
     long i; 
     for(i=0;i<h;i++)
      if(n>=hh[i])
       return 0;
     return 1;
}
bool islow()
{
     long i;
     for(i=0;i<l;i++)
      if(n<=ll[i])
       return 0;
     return 1;
}
int main()
{
    long kas=0,kase;
    char str[1000];
    scanf("%ld",&kase);
   
    while(kase--)
    {
        scanf("%ld",&n);
         getchar();
       l=h=0;
       while(gets(str)&&str[0]!='p')
       {
         if(str[4]=='t')
          hh[h++]=n;
         else
          ll[l++]=n;
         scanf("%ld",&n);
         getchar();
       }
       printf("Case %ld: ",++kas);
       if(ishigh()&&islow())
        printf("Alice found her size without mistakes\n");
       else
        printf("Alice made a mistake\n"); 
    }
    return 0;
}
