#include<stdio.h>
int main()
{
    bool flag=0;
    long i,j,k,kase,kas=1;
    char str[30000],c[20000];
    scanf("%ld",&kase);
    getchar();
    getchar();
    while(kase--)
    {
       if(flag)
         printf("\n");
       flag=1;
       printf("Case #%ld:\n",kas++);
      while(gets(str)&&str[0]!='\0')
      {
         j=k=0;
         for(i=0;str[i]!='\0';i++)
         {
            if(str[i]==' ')
            {
              if(j)
              {
                   if(k<j)
                   {
                    printf("%c",c[k]);
                    k++;
                    }
                   j=0;
              }
            }
            else
             c[j++]=str[i];
         }
         if(j&&k<j)
             printf("%c",c[k]);
         printf("\n");
      }
    }
    return 0;
}
