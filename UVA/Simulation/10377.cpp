#include<stdio.h>
#include<string.h>
int main()
{
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    char O[4]={'W','N','E','S'};
    char grid[100][100],str[1000],ch;
    long i,row,col,o,si,sj,c,d,kase;
    bool flag=0;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld %ld",&row,&col);
       getchar();
       for(i=0;i<row;i++)
        gets(grid[i]);
       scanf("%ld %ld",&si,&sj);
       o=1;si--;sj--;
       getchar();
       if(flag)
        printf("\n");
       flag=1;
       while(gets(str)&&str[0]!='\0')
       {
          for(i=0;str[i]!='\0';i++)
          {
           ch=str[i];
          if(ch==' ')
           continue;
          if(ch=='R')
           o=(o+1)%4;
          else if(ch=='L')
          { o--;if(o<0)o=3;}
          else if(ch=='F')
          {
               c=si+x[o];
               d=sj+y[o];
               if(c<0||d<0||c>=row||d>=col||grid[c][d]=='*')
                continue;
               si=c;sj=d;
          }
          }
          //printf("%ld %ld %c\n",si+1,sj+1,O[o]);
       }
       printf("%ld %ld %c\n",si+1,sj+1,O[o]);
    }
    return 0;
}
     
