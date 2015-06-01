#include<stdio.h>
#define MAXN 1000000

void TrieAdd(char *,int);
bool IsMember(char *,int);
bool TrieRemove(char *,int);

struct Trie
{
  char key;
  int next,child;
}T[MAXN];

int root=0,Tsize=1;

int main()
{
    bool flag;
    char ch;
    char wrd[1000];
    printf("*****Application Based On Trie******\n");
    printf("1.Add a Word In Your Dictionary\n");
    printf("2.Search A word\n");
    printf("3.Destroy Current Dictionary Database\n");
    printf("4.Remove A word from Dictionary:\n");
    printf("5.Count Number of Words with prefix\n");
    printf("Any Other Key To Exit...\n");
    flag=1;
    do
    {
      scanf("%c",&ch);
      switch(ch)
      {
        case '1':
             printf("Enter Word:\n");
             scanf("%s",wrd);
             TrieAdd(wrd,root);
             break;
        case '2':
             printf("Enter A Word To Search:\n");
             scanf("%s",wrd);
             if(IsMember(wrd,root))
              printf("Found\n");
             else
              printf("Not Found\n");
              break;
        case '3':
             root=0;
             printf("Dictionary database destroyed.\n");
             break;
        case '4':
             printf("Enter Word:\n");
             scanf("%s",wrd);
             if(TrieRemove(wrd,root))
              printf("Succesfully Removed\n");
             else
              printf("Word doesn't exist\n");
              break;
        default:
                flag=0;
                break;
      }
      getchar();
    }while(flag);
    return 0;
}

void TrieAdd(char *wrd,int temp)
{
   bool found;
   int par,level,i,cur;
   par=level=temp;
   i=0;
   while(1)
   {
     found=false;
     if(level==0)
     {
         //printf("%d %c %d\n",Tsize,wrd[i],par);
         T[Tsize].key=wrd[i];
         T[Tsize].child=0;T[Tsize].next=0;T[par].child=Tsize;
         par=Tsize;Tsize++;i++;
         if(wrd[i-1]=='\0')
          break;
         continue;
     }
     for(cur=level;cur!=0;cur=T[cur].next)
     {
        par=cur;
       if(T[cur].key==wrd[i])
       {
         found=true;
         break;
       }
     }
     if(found)
      level=T[par].child;
     else
     {
         //printf("%d %c %d\n",Tsize,wrd[i],par);
         T[Tsize].key=wrd[i];T[Tsize].child=0;T[Tsize].next=0;
         T[par].next=Tsize;
         level=0;
         par=Tsize;
         Tsize++;
     } 
     /*if(found)
     printf("Matched with %c and went to %d\n",T[par].key,level);*/
     if(found&&wrd[i]=='\0')
      break; 
     i++;
   } 
   root=1; 
}
bool IsMember(char *wrd,int temp)
{
   bool found;
   int par,level,i,cur;
   par=level=temp;
   i=0;
   while(1)
   {
     found=false;
     for(cur=level;cur!=0;cur=T[cur].next)
     {
       if(T[cur].key==wrd[i])
       {
         par=cur;
         found=true;
         break;
       }
     }
     if(found)
      level=T[par].child;
     else
      return 0;
     /*if(found)
     {
     printf("Parent %d Matched with %c and went to %d\n",par,T[par].key,level);
     printf("%c %d\n",T[level].key,T[level].next);
     }*/
     if(wrd[i]=='\0')
      return 1;
     i++;
   } 
}
bool TrieRemove(char *wrd,int temp)
{
   bool found;
   int par,level,i,cur;
   par=level=temp;
   i=0;
   while(1)
   {
     found=false;
     for(cur=level;cur!=0;cur=T[cur].next)
     {
       if(T[cur].key==wrd[i])
       {
         found=true;
         if(wrd[i]=='\0')
         {
           T[par].next=T[cur].next;
           return 1;
         }
         par=cur;
         break;
       }
       par=cur;
     }
     if(found)
      level=T[par].child;
     else
      return 0;
     if(wrd[i]=='\0')
       return 0;
     i++;
     if(T[level].key=='\0'&&wrd[i]=='\0')
     {
       T[par].child=T[level].next;
       return 1;
     }
   } 
}
