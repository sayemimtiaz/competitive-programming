#include<stdio.h>
#include<string.h>

int main()
{
    bool flag=0;
    int kase,i,j,p;
    char prv[100],str[100];
    scanf("%d",&kase);
    getchar();
    getchar();
    while(kase--)
    {
      p=0;prv[0]='\0';
      if(flag)
       printf("\n");
      else
       flag=1;
      while(gets(str)&&str[0]!='\0')
      {
        for(i=0;str[i]!='\0'&&prv[i]!='\0'&&i<p&&str[i]==prv[i];i++);
         for(j=0;j<i;j++)
           putchar(' ');
        if(!i)
          p=1;
        else if(i==p)
          p++;
        else
         p=i+1;
        printf("%s\n",str);
        strcpy(prv,str);
      }
    }
    return 0;
}
