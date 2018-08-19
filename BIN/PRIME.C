#include<stdio.h>
#include<conio.h>
void main()
{
int n;
clrscr();
printf("\n enter no ");
scanf("%d",&n);
for(int i=2;i<=n;i++)
 {
 for(int c=2;c<=n;c++)
  {
  if(i%c==0)
   {
   if(i==c)
   printf("\n %d",i);
   else
     break;
   }
  }
 }
getch();
}