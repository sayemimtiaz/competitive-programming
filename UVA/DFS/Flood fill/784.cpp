#include<cstdio>
#include<stack>
using namespace std;
typedef stack<long>s;
s s1,s2;
char str[100][100];
long j;
bool vis[100][100];
int x[]={-1,1,0,0,1,-1,-1,1};
int y[]={0,0,1,-1,1,-1,1,-1};
void dfs()
{
     long a,b,c,d,i;
     while(!s1.empty())
     {
        a=s1.top();s1.pop();
        b=s2.top();s2.pop();
        for(i=0;i<8;i++)
        {
          c=a+x[i];d=b+y[i];
          if(c>0&&d>=0&&!vis[c][d])
          {
             vis[c][d]=1;
             str[c][d]='#';
             s1.push(c);s2.push(d);                            
          }
        }  
     }
     for(i=1;i<j;i++)
      printf("%s\n",str[i]);
}
int main()
{
    long i,kase;
    bool flag;
    scanf("%ld",&kase);
    getchar();
    while(kase--)
    {
      for(i=0;i<100;i++)
       for(j=0;j<100;j++)
       {vis[i][j]=1;}
      j=1;flag=1;
      while(gets(str[j])&&str[j][0]!='_')
      {
         if(str[j][0]=='\0')
         {
            if(flag)
            {dfs();flag=0;}
            printf("\n");
         }
         else
         {
             for(i=0;str[j][i]!='\0';i++)
             {
              if(str[j][i]=='*')
              {s1.push(j);s2.push(i);str[j][i]='#';}
              else if(str[j][i]!='X')
              vis[j][i]=0;
              }
         }
         j++;
      }
      if(flag)
       dfs();
      printf("%s\n",str[j]);
    }
    return 0;
}
