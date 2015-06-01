#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
long yr,dy,mn;
char month[13][30]={"#","January","February","March","April","May","June","July","August","September","October","November","December"};
int m_d[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
void parse()
{
     char date[10000],c[10000];
     long i,j;
     gets(date);
     for(i=0;date[i]!='-';i++)
        c[i]=date[i];
        c[i]='\0';
        yr=atol(c);
        j=0;i++;
        for(;date[i]!='-';i++)
        c[j++]=date[i];
        c[j]='\0';
        for(j=1;j<=12;j++)
          if(!strcmp(c,month[j]))
            break;
        mn=j;
        j=0;i++;
        for(;date[i]!='\0';i++)
        c[j++]=date[i];
        c[j]='\0';
        dy=atol(c);
}
int main()
{
    long kase,k,m,a,b,kas=1;
    scanf("%ld",&kase);
    while(kase--)
    {
        getchar();
        parse();
        scanf("%ld",&k);
        m=mn;
        while(k)
        {
           b=m_d[m];
           if(m==2)
           if(m==2&&((yr%4==0&&yr%100)||(yr%100==0&&yr%400==0)))
            b++;
           a=b-dy;
           if(k>=a)
           {
           dy+=a;
           k-=a;
           }
           else
           {
           dy+=k;
           k=0;
           }
           if(k)
           {
                k--;
                mn++;dy++;
                if(mn>12)
                {
                 yr++;
                 mn=1;
                }
                dy=1;
           }
           m++;
           if(m>12)
            m=1;
        }
        printf("Case %ld: ",kas++);
        printf("%ld-%s-%.2ld\n",yr,month[mn],dy);
    }
    return 0;
}
