#include<stdio.h>
int m,n;
char grid[150][150];
void LongestSide(int x,int y)
{
  int a,b,i,side,cnt; 
  char ch=grid[x][y];
  for(i=y-1,side=0;i>=0&&grid[x][i]==ch;i--,side++);
  a=x;b=i+1;
  if(b==y)
   side=0;
  else
  {
  while(b<=y)
  {
    //printf("%d %d %d\n",a,b,side);
    for(i=a-1,cnt=0;i>=0&&grid[i][b]==ch;i--,cnt++);
    if(cnt>side)
      cnt=side;
    //printf("Up %d\n",cnt);
    if(cnt!=side)
    {
      if(cnt>=(y-b))
       side=cnt;
      else
      {
       side=y-b-1;
       b++;
       continue;
       }
    }
    for(i=a+1,cnt=0;i<m&&grid[i][b]==ch;i++,cnt++);
    if(cnt>side)
      cnt=side;
      //printf("Down %d\n",cnt);
    if(cnt!=side)
    {
      if(cnt>=(y-b))
       side=cnt;
      else
      {
       side=y-b-1;
       b++;
       continue;
       }
    }
    
    b++;
  }
  a=x;
  for(b=y+side;b>=n;b--);
  if(b==y)
   side=0;
  else
  {
      side=b-y;
      while(b>y)
      {
                
        //         printf("%d %d %d\n",a,b,side);
        if(grid[a][b]!=ch)
        {side=b-1-y;b--;continue;}
         for(i=a-1,cnt=0;i>=0&&grid[i][b]==ch;i--,cnt++);
          if(cnt>side)
           cnt=side;
    //printf("Up %d\n",cnt);
    if(cnt!=side)
    {
      if((b-y)<=cnt)
       side=cnt;
      else
      {
       side=b-1-y;
       b--;
       continue;
       }
    }
    for(i=a+1,cnt=0;i<m&&grid[i][b]==ch;i++,cnt++);
    if(cnt>side)
      cnt=side;
      //printf("Down %d\n",cnt);
    if(cnt!=side)
    {
      if((b-y)<=cnt)
       side=cnt;
      else
      {
       side=b-1-y;
       b--;
       continue;
       }
    }
    
    b--;
    }
  }
}
/*for(i=x-1,cnt=0;i>=0&&grid[i][y]==ch;i--,cnt++);
if(cnt<side)
 side=cnt;
for(i=x+1,cnt=0;i<m&&grid[i][y]==ch;i++,cnt++);
    if(cnt<side)
      side=cnt;*/
  printf("%d\n",2*side+1);
}
int main()
{
    int kase,x,y,q,i,j;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d %d",&m,&n,&q);
      for(i=0;i<m;i++)
      {
         getchar();
         for(j=0;j<n;j++)
          scanf("%c",&grid[i][j]);
      }
      printf("%d %d %d\n",m,n,q);
      while(q--)
      {
        scanf("%d %d",&x,&y);
        LongestSide(x,y);
      }
    }
    return 0;
}
