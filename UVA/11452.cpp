#include<stdio.h>
#include<string.h>
int main()
{
    char str[30000],seq[30000];
    long kase,i,j,k,l,len,m;
    scanf("%ld",&kase);
    getchar();
    while(kase--)
    {
        gets(str);
        len=strlen(str);
        seq[0]=str[0];j=1;
        for(i=1;i<len;i++)
        {
              if(str[i]==seq[0])
              {  
                 for(k=i,l=0;k<(i+j);k++,l++)
                  if(str[k]!=seq[l])
                    break;
                  seq[j]='\0';
                  if(k==(i+j))
                  { l=0;
                      for(k=0;k<len;k++)
                      {
                           if(str[k]!=seq[l])
                             break;
                           l++;
                           if(l==j)
                            l=0;
                      }
                      if(k==len)
                      {
                       m=l;
                       for(k=l;k<(l+8);k++)
                        {
                           printf("%c",seq[m]);
                           m++;
                           if(m==j)
                            m=0;
                        }
                        printf("...");
                       break;
                       }
                  }
              }
              seq[j++]=str[i];
        }
        printf("\n");
        }
        return 0;
    }  
       
