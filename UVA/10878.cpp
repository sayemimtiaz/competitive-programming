#include<string.h>
#include<stdio.h>
#include<math.h>
char o[1000000];
int main()
{
    char str[55000];
    int num[25000],i,j,k,r,l=0;
    while(gets(str))
    {
       for(i=1, k=0;str[i]!='|'; i++)
        {
            if(str[i]=='o')
                num[k++]=1;
            else if(str[i]==' ')
                num[k++]=0;
        }
      for(r=0,j=k-1,i=0;i<k;i++,j--)
       r+=(num[i]*pow(2,j));
      o[l++]=char(r);
      if(str[0]=='_' &&str[10]=='_')
         {
                for(i=0; i<l-1; i++)
                    printf("%c", o[i]);
                l=0;
         }
    }
   // getchar();
    return 0;
}
