#include<cstdio>
#include<cstring>
using namespace std;
bool R[10][10];
bool isAc(int a,int b,int c)
{
   if(R[a][b]&&R[b][a]&&R[a][c]&&R[c][a]&&R[c][b]&&R[b][c])
    return true;
   return false;
}
bool isNAc(int a,int b,int c)
{
   if(!R[a][b]&&!R[b][a]&&!R[a][c]&&!R[c][a]&&!R[c][b]&&!R[b][c])
    return true;
   return false;
}
bool check()
{
     int i,j,k;
     for(i=1;i<=3;i++)
        for(j=i+1;j<=4;j++)
         for(k=j+1;k<=5;k++)
           if(isAc(i,j,k)||isNAc(i,j,k))
           {printf("WIN\n");return 0;}
     return 1;
}
int main()
{
    int a,b,m;
    while(~scanf("%d",&m))
    {
       while(m--)
       {
         scanf("%d %d",&a,&b);
         R[a][b]=R[b][a]=1;
       }
       if(check())
        printf("FAIL\n");
       memset(R,0,sizeof(R));
       
    }
    return 0;
}
