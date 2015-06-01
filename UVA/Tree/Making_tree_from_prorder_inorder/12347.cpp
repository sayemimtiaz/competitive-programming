#include<stdio.h>
struct Tree
{
  int info;
  int left,right;
}T[10009];
int root,Tsize;

void MakeTree(int info)
{
     int save,temp=1;
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
         if(info<T[temp].info)
          temp=T[temp].left;
         else
          temp=T[temp].right;
       }
       T[Tsize].info=info;
       T[Tsize].left=0;
       T[Tsize].right=0;
       if(info<T[save].info)
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
     printf("%d\n",T[temp].info);
}
int main()
{
    int kase,i,n;
    Tsize=1;root=0;
    while(scanf("%d",&n)==1){
     MakeTree(n);}
     PostOrder(root);
    // getchar();getchar();
    return 0;
}
