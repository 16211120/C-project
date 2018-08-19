#include<stdio.h>
#include<conio.h>
void inputdata();
void mainmenu();
void entercardetails();
void enterdriverdetails();
void rentercar();
void searchvehical(int v);
void searchdriver();
int c[3][100],d[2][100],date,x=0,z=0;

void main()
{
 clrscr();
 int opt1;

 printf("\n\n\t\t**************P&G TOUR SRILANKA**************");
 printf("\n\n\n\n");
 printf("\n\t\t============MENU============");
 printf("\n--1--input data");
 printf("\n--2--main menu");
 printf("\n--3--Exit");
 do
 {
  printf("\nenter your option=");
  scanf("%d",&opt1);
  switch(opt1)
  {
   case 1:inputdata();break;
   case 2:mainmenu();break;
   case 3:printf("\n Exit");break;
   default:printf("\n Invalid option ");
  }
 }
 while(opt1!=3);
 getch();
}
void inputdata()
{
 int opt2;

 printf("\n=====MENU=====");
 printf("\n--1--Enter car details");
 printf("\n--2--Entre driver details");
 printf("\n--3--Exit");
 do
 {
  printf("\n Enter your option=");
  scanf("%d",&opt2);
  switch(opt2)
  {
   case 1:entercardetails();break;
   case 2:enterdriverdetails();break;
   case 3:printf("\n Exit");break;
   default:printf("\n Invalid option ");
  }
 }
 while(opt2!=3);
}
void entercardetails()
{
 for(int i=0;i!=2;i++)
 {
  for(int j=0;j<100;j++)
  {
   if(i==0)
   {
    x=x+1;
    c[2][j]=0;
    printf("\n Enter car %d number=",j+1);
    scanf("%d",&c[i][j]);
    if(c[i][j]==111)
    {
     break;
    }
  }
  if(i==1)
  {
   printf("Enter comfortable or economical=");
   scanf("%d",&c[i][j]);
   if(c[i][j]==111)
   {
    break;
   }
  }
 }
}
}
void enterdriverditails()
{
  for(int i=0;i!=1;i++)
  {
   for(int j=0;j<100;j++)
   {
    if(i==0)
    {
     printf("\n Enter driver %d id=",j+1);
     z=z+1;
     d[1][j]=0;
     scanf("%d",&d[i][j]);
     if(d[i][j]==111)
     {
      break;
     }
    }
   }
  }
}
void mainmenu()
{
 int opt3;
 do
 {
  printf("\n\t*=*=*=*=MAIN MENU=*=*=*=*");
  printf("\n--1-- Rent a car");
  printf("\n--2-- Tour pacage");
  printf("\n--3-- Exit");
  printf("\nEnter your option=");
  scanf("%d",&opt3);
  switch(opt3)
  {
   case 1:rentercar();break;
   case 2:main();break;
   case 3:printf("\n Exit");break;
   default:printf("\n Invalid option ");
  }
 }
 while(opt3!=3);
}
void rentercar()
{
 int opt4;
 do
 {
  printf("\n*******MENU*******");
  printf("\n--1-- Economic vehical");
  printf("\n--2-- confortable vehical");
  printf("\n--3-- Exit");
  printf("\nenter your option=");
  scanf("%d",&opt4);
  switch(opt4)
  {
   case 1:searchvehical(opt4);break;
   case 2:searchvehical(opt4);break;
   case 3:printf("\n Exit");break;
   default:printf("\n Invalid option ");
  }
 }
 while(opt4!=2);
}
void searchvehical(int v)
{
 int a=0,car=0,opt5=0;
 printf("\n enter date=");
 scanf("%d",&date);
 for(int i=1;i!=2;i++)
 {
  for(int j=0;j!=x-1;j++)
  {
   if(c[i][j]==v)
   {
    if(c[2][j]!=date)
    {
     printf("\n%d",c[0][j]);
     a=1;
    }
   }
  }
 }
 if(a==1)
 {
  printf("\n This vehicals can take %d day",date);
  printf("\n Enter your select vehical id=");
  scanf("%d",&car);
  for(int i=0;i!=1;i++)
  {
   for(int j=0;j!=x-1;j++)
   {
    if(c[i][j]==car)
    {
     c[2][j]=date;
     break;
    }
   }
  }
 }
 else
 {
  printf("\n Sorry we havent vehical %d day",date);
  getch();
  main();
 }
 printf("\n**** MENU****");
 printf("\n--1--Want driver");
 printf("\n--2--Exit");
 do
 {
  printf("\nEnter your option=");
  scanf("%d",&opt5);
  switch(opt5)
  {
   case 1:searchdriver();break;
   case 2:main();break;
   case 3:printf("\n Exit");break;
   default:printf("\n Invalid option ");
  }
 } while(opt5!=1);
}
void searchdriver()
{
 int driver=0,a=0;
 for(int i=1;i!=2;i++)
 {
  for(int j=0;j!=z;j++)
  {
   if(d[i][j]!=date)
   {
    printf("\n%d",d[0][j]);
    a=1;
   }
  }
 }
 if(a==1)
 {
  printf("\n This Drivers can take");
  printf("\n Enter driver ID=");
  scanf("%d",&driver);
  for(int k=0;k!=1;k++)
  {
   for(int l=0;l!=111;l++)
   {
    if(d[k][l]==driver)
    {
     d[1][l]=date;
     break;
    }
   }
  }
  main();
 }
 if(a==0)
 {
  printf("\nSorry we havent Driver %d day", date);
  main();
 }
}









