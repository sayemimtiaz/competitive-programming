#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long v,size,m,val;
char a[6];
struct S
{
  char store[6];
  long hold;
}R[83685];
int cmp(const void *a,const void *b)
{
    S *x=(S*)a;
    S *y=(S*)b;
    return (strcmp(x->store,y->store)); 
}
void generate(char s,int how)
{
     if(how==size)
     {strcpy(R[v].store,a);R[v++].hold=val;val++;return;}
     char i;
     for(i=s;i<='z';i++)
     {
       a[how]=i;
       generate(i+1,how+1);
     }
}
bool bin(char *str)
{
     long s,e,h;
      s=0;e=v-1;
       while(s<=e)
       {
         m=(s+e)/2;
         h=strcmp(str,R[m].store);
         if(!h)
           return 1;
         if(h>0)
          s=m+1;
         else
          e=m-1;
       }
      return 0;
}
int main()
{
    char str[100];
    val=1;
    for(size=1;size<=5;size++)
    {
      a[size]='\0';
     generate('a',0);
     }
     qsort(R,v,sizeof(S),cmp);
    while(gets(str))
    {
       if(bin(str))
       printf("%ld",R[m].hold);
       else
        printf("0");
       printf("\n");
    }
    return 0;
}
