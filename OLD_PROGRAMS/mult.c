/*dit wise multiplication*/
#include<conio.h>
#include<stdio.h>
main()
{
   int n1,n2,res;
   printf("Enter two numbers\t");
   scanf("%d%d",&n1,&n2);
   res=0;
   while(n2 != 0)
   {
      if (n2&01)               
         res=res+n1; 
      n1<<=1; 
      n2>>=1; 
   }
   printf(" Product  is  %d",res);
   getch();
}
