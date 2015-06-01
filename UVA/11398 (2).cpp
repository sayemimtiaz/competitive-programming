#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char line[60000];
    long long i,j,k,flag,len,n,zero;
    long c[100];
    bool hes;
    while(gets(line)&&line[0]!='~')
    {
       k=0;
       hes=0;
       while(1)
       {
         zero=0;
         len=strlen(line);
          for(i=0;i<=len;i++)
          {
             if(line[i]=='#')
             {
                hes=1;
                break;
             } 
             if(line[i]==' '||line[i]=='\0')
             {
               if(zero==2)
                flag=0;
               else if(zero==1)
                 flag=1;
               else
               {
                   for(j=0;j<(zero-2);j++)
                    c[k++]=flag;
               }
               zero=0;
             }
             else
               zero++;
             
          }
          if(hes)
            break;
          gets(line);
       }
       j=k-1;n=0;
       for(i=0;i<k;i++,j--)
        n+=c[i]*pow(2,j);
       printf("%lld\n",n);       
    }
    return 0;
}
