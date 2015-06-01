#include<cstdio>
#include<cstring>
using namespace std;
struct S
{
  long com[4];
}B[100];
long save,n;
bool flag[12];
bool iscon(long a)
{
  long i;
  for(i=0;i<3;i++)
   if(flag[B[a].com[i]])
    return 0;
   return 1;
}
void mark(long a)
{
  long i;
  for(i=0;i<3;i++)
   flag[B[a].com[i]]=1;
}
void unmark(long a)
{
  long i;
  for(i=0;i<3;i++)
   flag[B[a].com[i]]=0;
}
void recur(long s,long depth,long w)
{
  if(depth==3)
   {if(save<w)save=w;return;}
   long i;
  for(i=s+1;i<n;i++)
   if(iscon(i))
   {
     mark(i);
     recur(i,depth+1,w+B[i].com[3]);
     unmark(i);
   }
}
int main()
{
    long i,kase,kas=1,j;
    while(scanf("%ld",&n)==1&&n)
    {
        for(i=0;i<n;i++)
         scanf("%ld %ld %ld %ld",&B[i].com[0],&B[i].com[1],&B[i].com[2],&B[i].com[3]);
            save=-1;
           for(i=0;i<n-2;i++)
           {
             memset(flag,0,sizeof(flag));
             mark(i);
             recur(i,1,B[i].com[3]);
             unmark(i);
             }
            printf("Case %ld: %ld\n",kas++,save);
    }
    return 0;
}
