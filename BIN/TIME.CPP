#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
char a[19];
printf("Enter value : ");
scanf("%19s",a);//how many char you want specify after the % symbol
printf("\n The value is : ");
puts(a);
getch();
}