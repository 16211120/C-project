#include<stdio.h>
#include<conio.h>
int c[2][10],d[2][10],date,x=0,z=0;
void inputdata();
void main()
{
 clrscr();
 int opt1;
 printf("\n*****--S&T TOUR SRILANKA--*****");
 printf("\n\n");
 printf("\n----MENU----");
 printf("\n 1.Input Data");
 printf("\n 2.Main Menu");
 printf("\n Exit");
 do
 {
  printf("\n Enter your option: ");
  scanf("%d",opt1);
  switch(opt1)
  {
   case 1:inputdata();break;
   case 2:mainmenu();break;
   case 3:printf("\n EXIT");break;
   default:printf("\n Invalid option");
  }
 } while(opt!=3);
 getch();
}
void inputdata()
{


}