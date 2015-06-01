#include<stdio.h>
#include<string.h>
long M[120][120];
bool B[120][120];
int main()
{
    long w,h,n,a,b,i,j;
    while(scanf("%ld %ld",&w,&h)&&(w||h))
    {
        scanf("%ld",&n);
        while(n--)
        {
          scanf("%ld %ld",&a,&b);
          B[b+1][a+1]=1;
        }
        j=2;M[1][1]=1;w++;h++;
        for(i=1;i<=h;i++)
         {for(;j<=w;j++)
         {
           if(B[i][j])
            continue;
            M[i][j]=M[i-1][j]+M[i][j-1];
         }j=1;}
        if(M[h][w]>1)
         printf("There are %ld paths from Little Red Riding Hood's house to her grandmother's house.\n",M[h][w]);
        else if(M[h][w]==1)
         printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else
         printf("There is no path.\n");
         memset(M,0,sizeof(M));
         memset(B,0,sizeof(B));
    }
    return 0;
}
