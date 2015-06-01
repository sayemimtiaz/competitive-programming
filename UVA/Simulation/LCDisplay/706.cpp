#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void process(char);

char disp[50][300];
int colP,s;

int main()
{
    char n[1000];
    int i,j,k,t;
    while(scanf("%d %s",&s,&n)&&s)
    {
      memset(disp,' ',sizeof(disp));
      colP=1;
      for(i=0;n[i]!='\0';i++)
       process(n[i]);
      for(j=1;j<=(2*s+3);j++){
       for(k=1;k<=((s+2)*i+i-1);k++)
        putchar(disp[j][k]);
      putchar('\n'); }           
       putchar('\n');        
    }
    return 0;
}
void process(char ch)
{
  int i,j;
  switch(ch)
  {
    case '0':
         for(i=colP+1;i<=(colP+s);i++)
          disp[1][i]='-';
         for(i=2;i<=(2*s+2);i++)
          disp[i][colP]=disp[i][colP+s+1]='|';
         disp[s+2][colP]=disp[s+2][colP+s+1]=' ';
         for(i=colP+1;i<=(colP+s);i++)
          disp[2*s+3][i]='-';
         colP+=s+3;
         break;
    case '1':
         for(i=2;i<=(2*s+2);i++)
          disp[i][colP+s+1]='|';
         disp[s+2][colP+s+1]=' ';
         colP+=s+3;
         break;
    case '2':
         for(j=1;j<=(2*s+3);j+=s+1)
          for(i=colP+1;i<=(colP+s);i++)
           disp[j][i]='-';
         for(i=2;i<=(s+1);i++)
          disp[i][colP+s+1]='|'; 
         for(j=i+1;j<=(i+s);j++)
          disp[j][colP]='|';
          colP+=s+3;
          break;
   case '3':
          for(i=2;i<=(2*s+2);i++)
          disp[i][colP+s+1]='|';
          disp[s+2][colP+s+1]=' ';
          for(j=1;j<=(2*s+3);j+=s+1)
          for(i=colP+1;i<=(colP+s);i++)
           disp[j][i]='-';
          colP+=s+3;
          break;
   case '4':
           for(i=2;i<=(2*s+2);i++)
          disp[i][colP+s+1]='|';
          disp[s+2][colP+s+1]=' ';
          for(i=colP+1;i<=(colP+s);i++)
           disp[s+2][i]='-';
          for(j=2;j<=(s+1);j++)
          disp[j][colP]='|';
          colP+=s+3;
          break;
   case '5':
          for(j=1;j<=(2*s+3);j+=s+1)
          for(i=colP+1;i<=(colP+s);i++)
           disp[j][i]='-';
          for(j=2;j<=(s+1);j++)
          disp[j][colP]='|';
          for(i=j+1;i<=(j+s);i++)
            disp[i][colP+s+1]='|';
           colP+=s+3;
           break;
   case '6':
        for(j=1;j<=(2*s+3);j+=s+1)
          for(i=colP+1;i<=(colP+s);i++)
           disp[j][i]='-';
         for(i=2;i<=(2*s+2);i++)
          disp[i][colP]='|';
          disp[s+2][colP]=' ';
         for(i=s+3;i<=(2*s+2);i++)
            disp[i][colP+s+1]='|';
          colP+=s+3;
           break;
   case '7':
         for(i=2;i<=(2*s+2);i++)
          disp[i][colP+s+1]='|';
          disp[s+2][colP+s+1]=' ';
         for(i=colP+1;i<=(colP+s);i++)
           disp[1][i]='-';
          colP+=s+3;
          break;
   case '8':
         for(j=1;j<=(2*s+3);j+=s+1)
          for(i=colP+1;i<=(colP+s);i++)
           disp[j][i]='-';
          for(i=2;i<=(2*s+2);i++)
          disp[i][colP+s+1]=disp[i][colP]='|';
          disp[s+2][colP+s+1]=disp[s+2][colP]=' ';
          colP+=s+3;
          break;
   case '9':
        for(j=1;j<=(2*s+3);j+=s+1)
          for(i=colP+1;i<=(colP+s);i++)
           disp[j][i]='-';
        for(i=2;i<=(2*s+2);i++)
          disp[i][colP+s+1]='|';
        disp[s+2][colP+s+1]=' ';
        for(j=2;j<=(s+1);j++)
          disp[j][colP]='|';
          colP+=s+3;
        break;                    
  }
}
