#include<stdio.h>
#include<string.h>
char grid[120][120],str[1000000];
bool taken[120][120];
int main()
{
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    int O[150];
    O['O']=0;O['N']=1;O['L']=2;O['S']=3;
    char ch;
    long star,i,row,col,o,si,sj,c,d,in,j;
    bool flag;
    while(scanf("%ld %ld %ld",&row,&col,&in)&&(row||col||in))
    {
       getchar();
       flag=1;
       for(i=0;i<row;i++)
       { gets(grid[i]);
         for(j=0;flag&&j<col;j++)
          if(grid[i][j]!='.'&&grid[i][j]!='*'&&grid[i][j]!='#')
          {o=O[grid[i][j]];si=i;sj=j;flag=0;break;}
       }
       star=0;
       gets(str);
          for(i=0;str[i]!='\0';i++)
          {
           ch=str[i];
          if(ch=='D')
           o=(o+1)%4;
          else if(ch=='E')
          { o--;if(o<0)o=3;}
          else if(ch=='F')
          {
               c=si+x[o];
               d=sj+y[o];
               if(c<0||d<0||c>=row||d>=col||grid[c][d]=='#')
                continue;
               si=c;sj=d;
               if(!taken[c][d]&&grid[c][d]=='*')
               {
                taken[c][d]=1;
                star++;
               }
          }
          }
       printf("%ld\n",star);
       memset(taken,0,sizeof(taken));
    }
    return 0;
}
     
