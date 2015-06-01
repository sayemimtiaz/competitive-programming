#include<stdio.h>
bool pal(int n)
{
     int j,k,a[10],i;
     i=0;
     while(n)
     {
       a[i++]=n%10;
       n/=10;
     }
     if(i>1&&a[1]>=6)
      return 0;
     for(j=0,k=i-1;k>j;j++,k--)
      if(a[j]!=a[k])
        return 0;
   return 1;
}
int main()
{
    int m[3000],nr[3000],n,kase,i,j;
    char str[1000];
    m[2359]=0;m[0]=1;m[1]=2;m[2]=3;m[3]=4;m[4]=5;m[5]=6;m[6]=7;m[7]=8;
    for(i=2358;i>8;i--)
    {
      m[i]=m[i+1];
      if(pal(i))
      {m[i-1]=i;i--;}
    }
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
        gets(str);
        j=0;
        n=0;
        for(i=0;str[i]!='\0';i++)
        {
          if(str[i]==':')
           continue;
           if(j==0)
           n+=(str[i]-'0')*1000;
           else if(j==1)
          n+=(str[i]-'0')*100;
          else if(j==2)
          n+=(str[i]-'0')*10;
          else
          n+=(str[i]-'0');
           j++;
        }
        printf("%.2d:%.2d\n",(m[n]/100),(m[n]%100));
    }
    return 0;
}
