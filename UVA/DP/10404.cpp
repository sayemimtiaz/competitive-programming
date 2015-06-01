#include<stdio.h>
bool state[1000009];
int main()
{
    long n,i,j,m,c[30];
    bool dec;
    while(~scanf("%ld",&n))
    {
       scanf("%ld",&m);
       for(i=0;i<m;i++)
        scanf("%ld",&c[i]);
       state[0]=1;
       for(i=1;i<=n;i++)
       {
         dec=0;
         for(j=0;j<m;j++)
            if(c[j]<=i)
              if(state[i-c[j]])
              {
                dec=1;break;
              }
         state[i]=(dec==1)?0:1;
       }
       if(state[n])
        printf("Ollie wins\n");
       else
        printf("Stan wins\n");
    }
    return 0;
}
