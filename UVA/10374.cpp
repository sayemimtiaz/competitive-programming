#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct t
 {
       char cand[100];
       char party[100];
       int vote;
 } list[20000];

 int comp(const void *a, const void *b)
  {
       t *x = (t*)a;
       t *y = (t*)b;

       return strcmp(x->cand,y->cand);
   }
   int main()
    {
		bool flag=0;
       char s[1000];
       int i,j,n,kase,k,m,l,h,r,max,t,p;
       scanf("%d",&kase);
      for(k=0; k<kase; k++)
       {
		  scanf("%d",&n);
		  getchar();
		  for(i=0; i<n; i++)
          {
             gets(list[i].cand);
             gets(list[i].party);
          }
		  for(i=0; i<n; i++)
          {
             list[i].vote = 0;      
          }

          qsort((void*)list,n,sizeof(list[0]),comp);

          scanf("%d",&p);
          getchar();
          for(i=0; i<p; i++)
          {
             gets(s);
			 l = 0;
             h = n;

             while(l<=h)
             {
                m = (l+h)/2;

                r = strcmp(s,list[m].cand);

                if(r>0)
                   l = m + 1;
                else if(r<0)
                   h = m - 1;
                else
                {
                   list[m].vote++;
                   break;
                }
             }
          }

          max = -1;
         for(i=0; i<n; i++)
		 {
             if(list[i].vote>max)
             {
				 l=0;
                s[l++]=i;
                max = list[i].vote;
             }
			 else if(list[i].vote==max)
			 {
				 l++;
			 }
		 }
			if(flag)
				printf("\n");
			flag=1;
		if(l>1||max==-1)
			printf("tie\n");
		else   
           printf("%s\n",list[s[0]].party);
       }
       return 0;
    }
