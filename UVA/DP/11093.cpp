#include<stdio.h>
#include<string.h>
bool found,vis[100009];
long n,start,a[100009],b[100009];
void boka(long cur,long capa)
{
     if(cur==start)
     {found=1;return;}
     long next;
     vis[cur]=1;
     next=(cur+1)%n;
     if(b[cur]<=(capa+a[cur]))
      boka(next,capa+a[cur]-b[cur]);
}
int main()
{
    long kas=1,kase,i,next;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld",&n);
       for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
       for(i=0;i<n;i++)
        scanf("%ld",&b[i]);
        found=0;
        printf("Case %ld: ",kas++);
       for(i=0;i<n;i++)
       {
         if(!vis[i])
         {
           found=0;
           start=i;
           vis[i]=1;
           next=(i+1)%n;
           if(b[i]<=a[i])
             boka(next,a[i]-b[i]);
           if(found)
           {
            printf("Possible from station %ld\n",i+1);
            break;
           }
         }
       }
       if(!found)
        printf("Not possible\n");
       memset(vis,0,sizeof(vis));
    }
    return 0;
}
