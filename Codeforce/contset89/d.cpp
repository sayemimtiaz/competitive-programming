# #include<cstdio>
# #include<cstdlib>
# int N,M,len,mem=-1;
# char str[100001],temp[100001],ans[100001];
# bool comp()
# {
#   for(int i=0;i<=len;i++)
#   {  if(ans[i]<temp[i])
#         return false;
#      else if(ans[i]>temp[i])
#         return true;    
#   }  
#   return true;
# }
# int main()
# {
#     scanf("%d %d",&N,&M);
#     scanf("%s",str);
#     for(int i=0;str[i]!='\0';i++)
#       temp[i] = str[i],len = i;
#     for(int x=0;x<10;x++)
#     {
#         for(int i=0;i<=len;i++)
#           temp[i]=str[i];
#         int want = M,col=0;
#         for(int i=0;i<=len;i++)
#           if(temp[i]-'0'==x)
#              want--;
#         for(int delta = 1;delta<=10&&want>0;delta++)
#         {
#            if(x+delta<=9)
#            {
#               for(int i=0;i<=len&&want>0;i++)
#               {
#                  if(temp[i]-'0'==x+delta)
#                    {temp[i] = x+'0'; col += delta;want--;}      
#               }          
#            }      
#            
#            if(x-delta>=0)
#            {
#               for(int i=len;i>=0&&want>0;i--)              
#               {
#                  if(temp[i]-'0'==x-delta)
#                  {temp[i] = x+'0'; col+= delta;want--;}        
#               }          
#            }    
#         }    
#         if(col<mem||mem==-1)
#           {mem=col;for(int i=0;i<=len;i++)ans[i]=temp[i];}
#         else if(col==mem&&comp())
#           {for(int i=0;i<=len;i++)ans[i] = temp[i];}
#     }
