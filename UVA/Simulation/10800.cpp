#include<stdio.h>
#include<string.h>

#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a>b)?b:a

int main()
{
    char str[500],disp[70][70];
    int x,y,len,j,curX,maxX,i,kase,maxC[70],cnt,minX,Bistar,kas=1;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
     gets(str);
     curX=1;maxX=1;minX=1;
     for(i=1;str[i]!='\0';i++)
     {
         if((str[i]=='R'&&str[i-1]=='R')||(str[i]=='C'&&str[i-1]=='R'))
          curX++,maxX=MAX(maxX,curX);
         else if(str[i]=='F'&&(str[i-1]=='F'||str[i-1]=='C'))
           curX--,minX=MIN(minX,curX);
     }
     len=i;
     memset(disp,' ',sizeof(disp));
     memset(maxC,0,sizeof(maxC));
     if(minX<1)
      Bistar=maxX-minX+1;
     else
      Bistar=maxX;
     maxC[maxX]=2;
     x=maxX;y=2;
     if(str[0]=='R')
          disp[x][y]='/';
     else if(str[0]=='C')
          disp[x][y]='_';
     else if(str[0]=='F')
          disp[x][y]='\\';
     for(i=1;str[i]!='\0';i++)
     {
         if((str[i]=='R'&&str[i-1]=='R')||(str[i]=='C'&&str[i-1]=='R'))
          x--,y++,maxC[x]=MAX(maxC[x],y);
         else if(str[i]=='F'&&(str[i-1]=='C'||str[i-1]=='F'))
           x++,y++,maxC[x]=MAX(maxC[x],y);
         else
           y++,maxC[x]=MAX(maxC[x],y);
         if(str[i]=='R')
          disp[x][y]='/';
         else if(str[i]=='C')
          disp[x][y]='_';
         else if(str[i]=='F')
          disp[x][y]='\\';   
        //  printf("%d %d %c\n",x,y,disp[x][y]);  
     }
     printf("Case #%d:\n",kas++);
     for(i=1;i<=Bistar;i++)
     {
      putchar('|');
      for(j=1;j<=maxC[i];j++)
       putchar(disp[i][j]);
       putchar('\n');
      }
       putchar('+');
      for(i=1;i<=len+2;i++)
       putchar('-');
       printf("\n\n");
    }
    return 0;
}
