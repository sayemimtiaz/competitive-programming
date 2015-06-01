#include<stdio.h>
#include<string.h>
struct Tree
{
       char node[150];
       int left,rite;
       double fr;
}T[15000];
int root=0,treesize;
double n;
void init()
{
     int i;
     root=0;
     treesize=0;
     for(i=1;i<15000;i++)
      T[i].fr=1;
}
void BST(char *str)
{
     int temp,save;
     temp=root;
     while(temp)
     {
         save=temp;
         int h=strcmp(str,T[temp].node);
         if(!h)
         { T[temp].fr++;return;}
         if(h>0)
           temp=T[temp].rite;
         else
           temp=T[temp].left; 
     }
     treesize++;
     strcpy(T[treesize].node,str);
     T[treesize].left=T[treesize].rite=0;
     if(!root)
       {root=1;return;}
     if(strcmp(str,T[save].node)>0)
           T[save].rite=treesize;
     else
           T[save].left=treesize;
     
}
void inorder(int temp)
{
     if(!temp)
      return;
     inorder(T[temp].left);
     double r;
     r=(T[temp].fr/n)*100.0000;
     printf("%s %.4lf\n",T[temp].node,r);
     inorder(T[temp].rite);
}
int main()
{
    char str[1000];
    int kase;
    bool flag=0;
    scanf("%d",&kase);
    gets(str);
    gets(str);
    while(kase--)
    {
       init();
       n=0;
       while(gets(str)&&str[0]!='\0')
       {BST(str);n++;}
       if(flag)
        printf("\n");
        flag=1;
       inorder(root);
       
    }
    return 0;
}
