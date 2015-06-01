#include<cstdio>
#include<cstring>
using namespace std;

#define UP 1
#define DOWN 0

int Table[31][2][4],n;

int dp(int pos,bool tile_state,int tile_num)
{
  int &rs=Table[pos][tile_state][tile_num];
  if(rs!=-1) return rs;
  if(pos==n)
  { 
   if(tile_num==3||tile_num==1) return rs=1;
   return rs=0;
  }
  rs=0;
  if(tile_num==3)
  {
    rs=dp(pos+1,tile_state,0);
  }
  else if(tile_num==0)
  {
    rs=dp(pos+1,UP,1)+dp(pos+1,DOWN,1)+dp(pos+1,tile_state,3);
  }
  else if(tile_state)
  {
    if(tile_num==1){
     rs=dp(pos+1,DOWN,2)+dp(pos+1,tile_state,0);
    }
    else
     rs=dp(pos+1,DOWN,1);
  }
  else
  {
   if(tile_num==1){
     rs=dp(pos+1,UP,2)+dp(pos+1,tile_state,0);
    }
    else
     rs=dp(pos+1,UP,1);
  }
  return rs;
}
int main()
{
  while(scanf("%d",&n)&&n!=-1)
  {
    memset(Table,-1,sizeof(Table));
    if(n==0) printf("1\n");
    else
    printf("%d\n",dp(1,0,0));
  }
  return 0;
}
