#include<stdio.h>

int D[20],F[20];

int DD(int n)
{
     if(n==1||n==2)
      return D[n];
     return (D[n]=((n-1)*(DD(n-2)+DD(n-1))));
     
}

int main()
{
    int n,kase,i;
    D[1]=0;D[2]=1;
    DD(12);
    F[0]=1;
    for(i=1;i<=12;i++)
      F[i]=i*F[i-1];
    scanf("%d",&kase);
    while(kase--)
    {
     scanf("%d",&n);
      printf("%d/%d\n",D[n],F[n]);
    }
    return 0;
}
