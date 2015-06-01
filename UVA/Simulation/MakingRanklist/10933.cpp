#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct CUP
{
 char TeamName[30];
 int Win,Point,Set,lose,TWin;
}cup[1200];

int T;

int cmp1(const void *a,const void *b)
{
    return (strcmp((char*)a,(char*)b));
}
int cmp2(const void *a,const void *b)
{
    CUP *x=(CUP*)a;
    CUP *y=(CUP*)b;
    if(x->TWin!=y->TWin)
     return y->TWin-x->TWin;
    if(x->Set!=y->Set)
     return y->Set-x->Set;
    if(x->Point!=y->Point)
     return y->Point-x->Point;
    return (strcmp((char*)a,(char*)b));
}

int binser(char *str)
{
    int h,s=0,e=T-1,m;
    while(s<=e)
    {
      m=(s+e)/2;
      h=strcmp(cup[m].TeamName,str);
      if(!h)
       return m;
      if(h>0)
       e=m-1;
      else
       s=m+1;
    }
}
int main()
{
    int *ptr;
    char *pch;
    int M,i,sideL,sideR,a,b,w,c;
    char str[5000];
    while(scanf("%d",&T)&&T)
    {
      getchar();
      for(i=0;i<T;i++)
      {
         gets(cup[i].TeamName);
         cup[i].Win=cup[i].TWin=cup[i].lose=cup[i].Set=cup[i].Point=0;
      }
      qsort(cup,T,sizeof(CUP),cmp1);
      scanf("%d",&M);
      getchar();
      while(M--)
      {
        gets(str);
        pch=strtok(str,"-");
        sideL=binser(pch);
        pch=strtok(NULL,":");
        sideR=binser(pch);
        pch=strtok(NULL,"-");
        w=c=0;
        while(pch!=NULL)
        {
          sscanf(pch,"%d",&a);
          pch=strtok(NULL," ");
          sscanf(pch,"%d",&b);
          pch=strtok(NULL,"-");
          if(a>b&&a-b>=2&&a>=25)
           w++,cup[sideL].Win++,cup[sideR].lose++;
          else  if(b>a&&b-a>=2&&b>=25)
           c++,cup[sideR].Win++,cup[sideL].lose++;
          cup[sideR].Point+=b;
          cup[sideL].Point+=a;
        }
        if(w>c)
         cup[sideL].TWin++;
        else
         cup[sideR].TWin++;
      }
      for(i=0;i<T;i++)
       cup[i].Set=cup[i].Win-cup[i].lose;
      qsort(cup,T,sizeof(CUP),cmp2);
      //printf("1234567890123456789012345678901234567890\n");
      for(i=0;i<T;i++)
       printf("%-20s%5d%5d%10d\n",cup[i].TeamName,cup[i].TWin,cup[i].Set,cup[i].Point);
      printf("\n");
    }
    return 0;
}
