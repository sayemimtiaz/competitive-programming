#include<stdio.h>

struct Dominos
{
  int x,y;
}D[20],Tile[20];

bool Found,taken[20];
int n,m;

void BackTrack(int how)
{
     if(Found)
      return;
     if(how==n)
     {
      Found=1;
      return;
     }
     int i;
     for(i=2;i<m;i++)
     {
       if(!taken[i])
       {
         if((how!=n-1&&D[i].y==Tile[how-1].y)||(how==n-1&&D[i].y==Tile[how-1].y&&D[i].x==D[1].x))
         {Tile[how].x=D[i].y;Tile[how].y=D[i].x; 
         taken[i]=1;
         BackTrack(how+1);
         taken[i]=0;
         }
         else if((how!=n-1&&D[i].x==Tile[how-1].y)||(how==n-1&&D[i].x==Tile[how-1].y&&D[i].y==D[1].x))
         {Tile[how]=D[i]; 
         taken[i]=1;
         BackTrack(how+1);
         taken[i]=0;
         }       
       }
     }
}

int main()
{
    int i;
    while(scanf("%d",&n)&&n)
    {
       scanf("%d",&m);
       m+=2;n++;
       for(i=0;i<m;i++)
        scanf("%d %d",&D[i].x,&D[i].y);
      Tile[0]=D[0];
      Found=0;
      BackTrack(1);
      if(Found)
       printf("YES\n");
      else
         printf("NO\n"); 
    }
    return 0;
}
