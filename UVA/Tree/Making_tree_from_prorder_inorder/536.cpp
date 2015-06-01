#include<stdio.h>
struct Tree
{
  char info;
  int left,right;
}T[100];
int root,Tsize,L;
char Pre[1000],In[1000];

bool left(char info,char Tinfo)
{
     int i;
     for(i=0;i<In[i]!='\0';i++)
     {
        if(In[i]==Tinfo)
         return 0;
        if(In[i]==info)
         return 1;
     }
}
void MakeTree(char info,int temp)
{
     int save;
     if(!root)
     {
       T[Tsize].info=info;
       T[Tsize].left=0;
       T[Tsize].right=0;
       root=1;
     }
     else
     {
       while(temp)
       {
         save=temp;
         if(left(info,T[temp].info))
         {
          temp=T[temp].left;
          // printf("%d %d\n",save,temp);
          }
         else
         {
          temp=T[temp].right;
          //printf("%d %d\n",save,temp);
          }
       }
       T[Tsize].info=info;
       T[Tsize].left=0;
       T[Tsize].right=0;
       if(left(info,T[save].info))
        T[save].left=Tsize;
       else
         T[save].right=Tsize;
     }
     Tsize++;
}
void PostOrder(int temp)
{
     if(!temp)
       return;
     PostOrder(T[temp].left);
     PostOrder(T[temp].right);
     printf("%c",T[temp].info);
}
int main()
{
    char str[5000];
    int kase,i;
    while(gets(str))
    {
      sscanf(str,"%s %s",Pre,In);
      Tsize=1;root=0;
      for(i=0;Pre[i]!='\0';i++)
        MakeTree(Pre[i],root);
      PostOrder(root);
     printf("\n");
    }
    return 0;
}
