#include<stdio.h>
#include<string.h>
int a[2500],b[2500],n,N,c[2500];
bool flag;
void check(int s,int h,int add)
{
   int i;
  if(!flag&&h==n)
  {
    if(add%n==0)
    {    printf("Yes\n");
           printf("%d",b[0]);
         for(i=1;i<n;i++)
           printf(" %d",b[i]);
         printf("\n");
      flag=1;
    }
    return;
  }
   for(i=s;!flag&&i<N;i++)
   {
       b[h]=c[i];
       check(i+1,h+1,(add+a[i])%n);
   }   
}
int main()
{
    int i;
  while(scanf("%d",&n)&&n)
  {
     N=2*n;
     for(i=1;i<N;i++)
     {
        scanf("%d",&a[i]);
        c[i]=a[i];
        a[i]=a[i]%n;
     }
     flag=0;
     for(i=1;!flag&&i<N;i++)
     {
       b[0]=c[i];
       check(i+1,1,a[i]);
     }
     if(!flag)
      printf("No\n");
  }  
  return 0;
}
