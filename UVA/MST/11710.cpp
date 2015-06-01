#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100000
struct S
{
  long u,v,cost;
}P[SIZE];
long N,rank[SIZE],par[SIZE];
char name[500][50];
int cmp(const void *a,const void *b)
{
    return (strcmp((char*)a,(char*)b));
}
int cmp1(const void *a,const void *b)
{
    S *x=(S*)a;
    S *y=(S*) b;
    return (x->cost-y->cost);
}
long binser(char *str)
{
  long s,e,mid,h;
  s=0;e=N-1;
  while(s<=e)
  {
    mid=(s+e)/2;
    h=strcmp(name[mid],str);
    if(!h)
     return mid;
    if(h>0)
     e=mid-1;
    else
     s=mid+1;
  }
}

void make_set()
{
     long i;
     for(i=0;i<N;i++)
     {
        rank[i]=0;
        par[i]=i;
     }
}
void link(long a,long b)
{
     if(rank[a]>rank[b])
      par[b]=a;
     else
     {
         par[a]=b;
         if(rank[a]==rank[b])
          rank[b]++;
     }
}
long find(long a)
{
     if(a!=par[a])
      par[a]=find(par[a]);
     return par[a];
}
int main()
{
    long i,j,sum,a,b,c,M;
    char s1[1000],s2[1000],str[1000];
    while(scanf("%ld %ld",&N,&M)==2&&(N||M))
    {
         getchar();
         make_set();
         for(i=0;i<N;i++)
            gets(name[i]);
         qsort(name,N,sizeof(name[0]),cmp);
         for(i=0;i<M;i++)
         {
           gets(str);
           sscanf(str,"%s %s %ld",s1,s2,&c);
           a=binser(s1);
           b=binser(s2);
           P[i].u=a;P[i].v=b;P[i].cost=c;
         }
         gets(str);
         qsort(P,M,sizeof(S),cmp1);
       j=0;sum=0;
       for(i=0;j<N-1&&i<M;i++)
       {
          a=find(P[i].u); b=find(P[i].v);
          if(a!=b)
          {
             j++;
             sum+=P[i].cost;
             link(a,b);
          }             
       }
       if(j!=N-1)
        printf("Impossible\n");
       else
        printf("%ld\n",sum);

    }
    return 0;
}
