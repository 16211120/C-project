#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void main()
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
}
