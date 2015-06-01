#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long kase,i,j,k,vv;
    double vd,o;
    bool flag=0;
    char a[1000],d[1000],n1[1000],n2[1000],t[1000];
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%s %s",n1,n2);
      o=pow(2,31);
      a[31]=d[31]='\0';
      if(flag)
      printf("\n");
      flag=1;
      printf("%s %s\n",n1,n2);
      while(1)
      {
         j=30;
         vd=0;
         for(i=0;n1[i]!='\0';i++)
         {
           if(n1[i]!=n2[i])
            a[i]='1';
           else
            a[i]='0';
           if(n1[i]==n2[i]&&n1[i]=='1')
           {vd+=(pow(2,j));d[i]='1';}
           else
            d[i]='0';
            j--;
         }
         vd*=2;
         printf("%s ",a);
         if(vd>=o)
         {printf("overflow\n");break;}
         j=0;
         vv=(long)vd;
         while(vv>1)
         {
            t[j++]=vv%2+'0';
            vv/=2;
         }
         if(j)
         t[j++]='1';
         for(k=0;k<(31-j);k++)
          d[k]='0';
         for(i=j-1;i>=0;i--)
          d[k++]=t[i];
         printf("%s\n",d);
         strcpy(n1,a);
         strcpy(n2,d);
         if(vd==0)
          break;
      }
    }
    return 0;
}
