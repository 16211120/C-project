#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
void main()
{
    int n,nd;
    clrscr();

    FILE *f;
    char c;
    f=fopen("DRDATA.txt","r");
    while((c=fgetc(f))!=EOF)
    {
	printf("%c",c);
    }
    fclose(f);
    printf("\n \n");

    printf("\nIf you want a Driver,please enter 1:");
    scanf("%d",&n);
    if(n==1)
    {
      printf("\n Enter driver ID: ");
      scanf("%d",&nd);
      f=fopen("Bookd.txt","w");

      if(nd==2)
      {
	fprintf(f,"2 \t \t Sunil \n Booking is Succesfully");
      }
      else if(nd==5)
      {
	fprintf(f,"5 \t \t Charith \n Booking is Succesfully");
      }
      else if(nd==10)
      {
	fprintf(f,"10 \t \t Surendra, \n Booking is Succesfully");
      }
      else
      {
       printf("This DRIVER is allready booked");
      }

     fclose(f);
    }
    else
    {
    printf("Invalid enter number");
    }

    f=fopen("Book1.txt","r");
     while((c=fgetc(f))!=EOF)
    {
	printf("%c",c);
    }
    getch();
    fclose(f);

}