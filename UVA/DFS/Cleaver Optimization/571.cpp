#include<stdio.h>
#include<string.h>
#define INF 100000000
bool memo[2000][2000],flag;
long ca,cb,n;
char step[1000000];
char done[6][20]={"fill A","fill B","pour A B","pour B A","empty A","empty B"};
void bak(long a,long b,long s)
{
     if(flag)
       return;
     //Check whether destination is reached..
     if(a==n||b==n)
     {
       flag=1;
       long i;
       for(i=0;i<s;i++)
            printf("%s\n",done[step[i]]);
         printf("success\n");
       return;
     }
     //Fill A,B
     if(a!=ca&&!memo[ca][b])
     {
     step[s]=0;
     memo[ca][b]=1;
     bak(ca,b,s+1);
     }
     if(b!=cb&&!memo[a][cb])
     {
     step[s]=1;
     memo[a][cb]=1;
     bak(a,cb,s+1);
     }
     //To pour A B. at least one must be contained with less water than 
     //capacity.so Test is here..
     if(b<cb)
     {
        step[s]=2;
        if((cb-b)>=a)
        {
           if(!memo[0][b+a])
           {
             memo[0][b+a]=1;
             bak(0,b+a,s+1);
             }
        }
        else if(!memo[a-cb+b][cb])
        {
           memo[a-cb+b][cb]=1;
           bak(a-cb+b,cb,s+1);
        }
     }
        if(a<ca)
        {
        //Pour B A
       step[s]=3;
       if((ca-a)>=b)
       {
         if(!memo[a+b][0])
         {
            memo[a+b][0]=1;
            bak(a+b,0,s+1);
          }
       }
        else if(!memo[ca][b-ca+a])
        {
          memo[ca][b-ca+a]=1;
          bak(ca,b-ca+a,s+1);
        }
    }
     //Empty A B
     if(a&&!memo[0][b])
     {
     memo[0][b]=1;
     step[s]=4;
     bak(0,b,s+1);
     }
     if(b&&!memo[a][0])
     {
     memo[a][0]=1;
     step[s]=5;
     bak(a,0,s+1);
     }
     
}
int main()
{
    
    long i;
    while(scanf("%ld %ld %ld",&ca,&cb,&n)==3)
    {
         flag=0;
         memset(memo,0,sizeof(memo));
         memo[0][0]=1;
         bak(0,0,0);
         
    }
    return 0;
}
