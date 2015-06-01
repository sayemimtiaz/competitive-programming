#include<stdio.h>
#include<stdlib.h>
struct table
{
       long c,s;
}T[1000];
long place[1000][1000];
int cmp(const void *a,const void *b)
{
    table *x=(table*)a;
    table *y=(table*)b;
    return (y->c-x->c);
}
int main()
{
    long cnt,j,i,m,n,t[1000],ct[1000];
    while(scanf("%ld %ld",&m,&n)==2&&(m||n))
    {
        for(i=0;i<m;i++)
        {
           scanf("%ld",&t[i]);
           ct[i]=t[i];
        }
        for(i=0;i<n;i++)
        {
           scanf("%ld",&T[i].c);
           T[i].s=i+1;
        }
        cnt=0;
        qsort(T,n,sizeof(table),cmp);
        for(i=0;i<n;i++)
        {
           for(j=0;j<m;j++)
           {
               if(T[i].c>0&&t[j]>0)
               {
                 place[j][t[j]]=T[i].s;T[i].c--;t[j]--;
               }
           } 
        }
        for(i=0;i<m;i++)
          if(t[i]<=0)
            cnt++;
        if(cnt==m)
        {
         printf("1\n");
        for(i=0;i<m;i++)
        {
            for(j=1;j<=ct[i];j++)
            {
               if(j!=1)
                printf(" ");
               printf("%ld",place[i][j]);
            }
         printf("\n");
        }
        }
        else
        printf("0\n");
    }
    return 0;
}
