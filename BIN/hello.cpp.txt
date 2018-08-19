#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void inputdata();
void mainmenu();
void entercardetails();
void enterdriverdetails();
void rentercar();
void searchvehicle();
void searchdriver();
int c[10],d[10],t[2],date,x=0,z=0;

void main()
{
 clrscr();
 int opt1;

 printf("\n\n\t\t**************S&T TOUR SRILANKA**************");
 printf("\n\n\n\n");
 printf("\n\t\t============MENU============");
 printf("\n--1--input data");
 printf("\n--2--main me nu");
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
  int c[10],t[2],x=10;

 FILE *carDetails;
 carDetails=fopen("carDetails.txt","w");
 fprintf(carDetails,"New Record \nCar ID \t 1-comfortable,2-economical");
 {
  for(int j=0;j<10;j++)
  {
    printf("\n Enter car ID %d: ",j+1);
    scanf("%d",&c[j]);
    if(c[j]>x)
    {
     x++;
     printf("\n Press 1 for Comfortable,Press 2 For economical: ");
     scanf("%d",&t[j]);
     fprintf(carDetails,"\n %d \t \t %d",c[j],t[j]);
    }
    else
    {
     printf("\n Invalid car ID");
     j--;
    }
    if(c[j]==111)
	{
	 break;
	}
  }
 }
fclose(carDetails);
clrscr();
main();
}
void enterdriverdetails()
{
  int d[10],y=10;
  char name[10];

  FILE *driverDetails;
  driverDetails=fopen("driverDetails.txt","w");
  fprintf(driverDetails,"New Record \nDriver ID");
   for(int j=0;j<10;j++)
   {
     printf("\n Enter driver ID %d: ",j+1);
     scanf("%d",&d[j]);
     printf("\n Enter driver name: ");
     scanf("%s",name);
     if(d[j]>y)
     {
      y++;
      fprintf(driverDetails,"\n %d %s ",d[j],name);
     }
     else
     {
      printf("\n Invalid driver ID");
      j--;
     }
     if(d[j]==111)
	{
	 break;
	}

   }
fclose(driverDetails);
clrscr();
main();
}


void mainmenu()
{
 int opt3;
 do
 {
  printf("\n\t*=*=*=*=MAIN MENU=*=*=*=*");
  printf("\n--1-- Rent a car");
  printf("\n--2-- Exit");
  printf("\nEnter your option=");
  scanf("%d",&opt3);
  switch(opt3)
  {
   case 1:rentercar();break;
   case 2:printf("\n Exit");break;
   default:printf("\n Invalid option ");
  }
 }
 while(opt3!=2);
}
void rentercar()
{
 int opt4;
 do
 {
  printf("\n*******MENU*******");
  printf("\n--1-- Comfortable vehical");
  printf("\n--2-- Economic vehical");
  printf("\n--3-- Exit");
  printf("\n Enter your option: ");
  scanf("%d",&opt4);
  switch(opt4)
  {
   case 1:searchvehicle();break;
   case 2:searchvehicle();break;
   case 3:printf("\n Exit");break;
   default:printf("\n Invalid option ");
  }
 }
 while(opt4!=3);
}

void searchvehical()
{
    char date[10];
    int n,nc,opt5;
    clrscr();
    printf("\n Enter date: ");
    scanf("%10s",&date);

    clrscr();
    printf("\n Customer date %s ",date);

    printf("\n \n");

    FILE *f;
    char c;
    f=fopen("SAVEDATA.txt","r");
    while((c=fgetc(f))!=EOF)
    {
	printf("%c",c);
    }

    fclose(f);
    printf("\n \n");

    printf("\nIf you want a car,please enter 1:");
    scanf("%d",& n);

    if(n==1)
    {
      printf("\n Enter car ID: ");
      scanf("%d",nc);

      f=fopen("Book.txt","w");
      if(nc==3)
      {
       fprintf(f,"3\t1\t%s\nBooking is Succesfully",date);
      }
      else
      {
	printf("This Vehicle is allready booked");
      }

    fclose(f);
    }
    else
    {
     printf("Invalid enter number");
    }

    f=fopen("Book.txt","r");
     while((c=fgetc(f))!=EOF)
    {
	printf("%c",c);
    }
    getch();
    fclose(f);

    clrscr();
    printf("\n**** MENU****");
    printf("\n--1--Want driver");
    printf("\n--2--Exit");
    do
    {
     printf("\nEnter your option: ");
     scanf("%d",&opt5);
     switch(opt5)
     {
      case 1:searchdriver();break;
      case 2:printf("\n Exit");break;
      default:printf("\n Invalid option ");
     }
    } while(opt5!=2);
    getch();
 }

void searchdriver()
{
    int n,nd;
    clrscr();

    FILE *d;
    char c;
    d=fopen("SAVEDATA1.txt","r");
    while((c=fgetc(d))!=EOF)
    {
	printf("%c",c);
    }
    fclose(d);
    printf("\n \n");

    printf("\nIf you want a Driver,please enter 1:");
    scanf("%d",& n);
    if(n==1)
    {
      printf("\n Enter driver ID: ");
      scanf("%d",nd);

      d=fopen("Bookd.txt","w");
      if(nd==3)
      {
	fprintf(d,"3\t1\t%s\nBooking is Succesfully");
      }
      else
      {
       printf("This DRIVER is allready booked");
      }

     fclose(d);
    }
    else
    {
    printf("Invalid enter number");
    }

    d=fopen("Book1.txt","r");
     while((c=fgetc(d))!=EOF)
    {
	printf("%c",c);
    }
    getch();
    fclose(d);


}