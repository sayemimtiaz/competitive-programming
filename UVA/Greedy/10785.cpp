#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char vow[250],con[250];
    int kase,n,i,j,kas=1;
    char Stored[3][29]={{'A','U','E','O','I','\0'},
      {'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R','\0'}};
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      printf("Case %d: ",kas++);
      int count[3][29]={0};
      int k=0,l=0;
      for(i=1;i<=n;i++)
      {
        if(i%2)
        {
          for(j=0;Stored[0][j]!='\0';j++)
           if(count[0][j]<21)
           {
             vow[k++]=Stored[0][j];
             count[0][j]++;
             break;
           }
        }
        else
        {
          for(j=0;Stored[1][j]!='\0';j++)
           if(count[1][j]<5)
           {
             con[l++]=Stored[1][j];
             count[1][j]++;
             break;
           }
        }
      }
      sort(vow,vow+k);
      sort(con,con+l);
      bool used1[300]={0},used2[300]={0};
      for(i=1;i<=n;i++)
      {
        if(i%2)
        {
          for(j=0;j<k;j++)
           if(!used1[j])
           {
             printf("%c",vow[j]);
             used1[j]=1;
             break;
           }
        }
        else
        {
          for(j=0;j<l;j++)
           if(!used2[j])
           {
             printf("%c",con[j]);
             used2[j]=1;
             break;
           }
        }
      }
      printf("\n");
    }
    return 0;
}
