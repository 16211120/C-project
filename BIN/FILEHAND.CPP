#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void entercardetails();
void enterdriverdetails();
void searchvehical();

void main()
{
 int opt;
 clrscr();
 printf("\n 1.Enter car details ");
 printf("\n 2.Enter driver details ");
 printf("\n 3.Enter to search vehicle ");
 printf("\n 4.EXIT");
 do{
    printf("\n Enter your opltion ");
    scanf("%d",&opt);
    switch(opt)
    {
     case 1:entercardetails();break;
     case 2:enterdriverdetails();break;
     case 3:searchvehical();break;
     case 4:printf("\n EXIT");break;
     default:printf("\n Invalid option");
    }
   }while(opt!=4);
 getch();
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


void searchvehical()
{
    char date[10];
    int n,nc=0;
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
      scanf("%d",&nc);
      f=fopen("Book.txt","w");
      if(nc==3)
      {
       fprintf(f,"3\t1\t%s\nBooking is Succesfully",date);
      }
      else if(nc==6)
      {
	fprintf(f,"6\t2\t%s\nBooking is Succesfully",date);
      }
      else if(nc==10)
      {
	fprintf(f,"10\t2\t%s\nBooking is Succesfully",date);
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

     main();



}