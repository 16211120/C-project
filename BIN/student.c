//STUDENT REGISTRATION SYSTEM//
/*WRITTEN BY KAMRAN MEHDI www.kamran-designer.tk.*/
//THIS IS THE PROGRAM LISTING FOR REGISTRATION SYSTEM SYSTEM//
#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<stdlib.h>     //conversion
#include<ctype.h>
#include <io.h>
#include<time.h>
#define password "skm"

//user -define data-type
 typedef struct {
	  int StuID;
	  int  age;
	  char name[30];
	  char add[30];
	  char gender[10];
	  char status[10];
	  char cno[10];
	  char date[12];

  } stu_rec;

 typedef enum{false,true}boolean;

 typedef struct link{
	stu_rec data;
	struct link*next;
 }node;

 typedef struct{
	node*Node;
}list;
//prototypes
int menu();
void AddEntry(list*,stu_rec);
void DeletEntry(list*, int);
void DisplayEntry(node*);
void SearchID(list*,int);
int isEmpty(node*);
stu_rec getRecord(list *);
void init(list*);
void process(int,list*);
void read_file(list*);
void write_file(list*);
void ModifyEntry (list *mylist, int);
void displayRec(node*current);
int getID();
void pass();
char cur_date[9];
char cur_time[9];

void main()
{
	clrscr();
	int choice;
	list mylist;
	init(&mylist);
	pass();
	read_file(&mylist);
	do{
		choice=menu();
		process(choice,&mylist);
	}while(choice!=6);
 write_file(&mylist);
 gotoxy(13,2); printf("DATE: %s\n",cur_date);
 gotoxy(53,2); printf("TIME: %s\n",cur_time);
}

void pass()
{
printf("\n\n\t\t\t  SCHOOL OF COMPUTING & TECHNOLOGY.");
printf("\n\t\t\t  *********************************");
printf("\n\t\t\t  *********************************");
int valid,retry=1;
char  pass[10];
	 _strdate(cur_date);
	 _strtime(cur_time);


do
	 {
	 gotoxy(32,14);  printf("Enter The Password: ");
	 gets(pass);
	 if(strcmp(pass,password)!=0)
	 {
	  clrscr();
	  gotoxy(30,16); printf("Incorrect Password!");
	  valid=0;
	  retry+=1;
	 }
	 else
	 valid=1;
	 }while(!valid&&retry<=3);

	 if(retry>3)
	 {
	 gotoxy(28,16);  printf("Maximum 3 try only! Bye!");
	 getch(); exit(0);
	 }
	 else
	 {
	 clrscr();
	 gotoxy(32,16);  printf("Access approved!");
	 getch();
	 }
}

void init(list*mylist){
		mylist->Node=NULL;
	}

void process(int choice,list *mylist){
		clrscr();
		stu_rec num;
		int ID;
		switch(choice){
		case 1:num=getRecord(mylist);
				AddEntry(mylist,num);
				printf("\n Record Inserted!");
				break;
		case 2: ID = getID();
				  DeletEntry(mylist,ID);
				  break;
		case 3:DisplayEntry(mylist->Node);
					break;
		case 4:  ID = getID();
					ModifyEntry(mylist, ID);
					break;
		case 5: ID=getID();
					SearchID(mylist,ID);
					break;
		case 6: clrscr();
				  printf("\n\n\t\t\t*******T H A N K  Y O U !!******");
				  printf("\n\t\t\t******Done by : KAMRAN MEHDI****");
				  printf("\n\t\t\t*******PROGRAM  TERMINATED******");
				  break;
		default:printf("\INVALID CHOICE!!! PLEASE ENTER AGAIN!");
		}
				 getch();
}


int menu(){
	clrscr();
	int temp;
	gotoxy(13,2); printf("DATE: %s\n",cur_date);
 gotoxy(53,2); printf("TIME: %s\n",cur_time);
	printf("\n\t\t**********************************************");
	printf("\n\t\t*          STUDENT REGISTRATION PROGRAM      *");
	printf("\n\t\t**********************************************");
	printf("\n");
	printf("\n\t\t\t[1]Add New Student Record  ");
	printf("\n\t\t\t[2]Delete Student Record   ");
	printf("\n\t\t\t[3]Display Student Record  ");
	printf("\n\t\t\t[4]Modify Student Record   ");
	printf("\n\t\t\t[5]Search Student Record	  ");
	printf("\n\t\t\t[6]Exit The Program        	  ");
	printf("\n\n\t\t\tPlease Enter Your Choice: ");
	fflush(stdin);
	scanf("%d", &temp);
return temp;
}

boolean IsDuplicate(int temp, list *mylist){
	node* curr = mylist->Node;
	while(curr!= NULL){
		if (curr->data.StuID == temp){
			 printf("\n\t<<StudentID Number already in use !>>");
			 printf("\n");
			 return true;
			 }
		curr= curr->next;
		}
return false;
}


int getCode(char *str, list *mylist){
	 char temp[20];
	 boolean OK;
	 do{
		  OK = true;
		  printf("%s",str);
		  fflush(stdin);
		  gets(temp);
		  if (strlen(temp)!=4){
			  printf("\t\t<< Student ID should not be Empty or It should \n\t\t only 4 digits >>\n");
			  OK= false;
			}
			for(int count=0; temp[count]!='\0'; count++)
				if (!isdigit(temp[count])){
					 printf("\t\t<< Must be digits! >>\n");
					 OK = false;
					 break;
				  }
	  }while(!OK || IsDuplicate(atoi(temp), mylist));
return atoi(temp);
}

char *getString(char * str){
	 char *temp = (char *)malloc(sizeof(80));
	 printf("%s", str);
	 fflush(stdin);
	 gets(temp);
return temp;
}
char *getString(char * str, int size, int status){
	 char *temp = (char *)malloc(sizeof(80));
	 boolean OK;
		 do{

		 OK = true;
		 printf("%s", str);
		 fflush(stdin);
		 gets(temp);
		 if (strlen(temp)>size){
			 printf("\t\t<< Contact No should not be Empty or \n\t\t It should not exceed %d characters! >>\n", size);
			 OK = false;
		 }
			if (status == 1 && strlen(temp)< 4){
		 printf("\t\t<< Name should not be Empty or \n\t\t It should not less than 4 characters.>>\n");
		 OK = false;
		 for(int count=0; temp[count]!='\0'; count++)
		 if (!isalpha(temp[count])){
		 printf("\t\t<< Student Name Must be characters! >>\n");
		 OK = false;
			break;
				  }
		 }

		  if (status == 2)
			 if (strlen(temp) < 8){
					 printf("\t\t<<Contact No should not be Empty or \n\t\tIt should not less than 8 characters>>\n");
					 OK = false;
			 }else
					 for(int count=0; temp[count]!='\0'; count++)
						if (!isdigit(temp[count])){
							 printf("\t\t<< Contact No Must be numeric!>>\n");
							 OK = false;
						 break;
				  }

if (status == 0 && (temp[0]!='m'&& temp[0]!='f' )){
					 printf("\t\t<< Gender should not be Empty or \n\t\t It should be only M or F >>\n");
					 OK = false;

		 }
	 }while(!OK);
return temp;
}
char * getDate(){
  boolean OK;
  char * temp = (char *)malloc(12);
  do{
  OK = true;
  printf("\t  Student D.O.B [DD/MM/YYYY]:");
  fflush(stdin);
  gets(temp);
  if (strlen(temp)!=10){
	printf("\t\t<< Student D.O.B should not be Empty or \n\t\t It should Must be 10 characters >>\n");
	OK = false;
  }else
  if (!isdigit(temp[0]) || !isdigit(temp[1]) || !isdigit(temp[3]) || !isdigit(temp[4])
	|| !isdigit(temp[6])|| !isdigit(temp[7]) || !isdigit(temp[8]) || !isdigit(temp[9])
	 || temp[2]!='/' || temp[5]!='/'){
		printf("\t\t<< Student D.O.B Format must be dd/mm/yyyy >>\n");
		OK = false;
	} else
	if (temp[0] < '0' || temp[0] >'3'){
		printf("\t\t<< Invalid day >>\n ");
	  OK = false ;
	}else
	if (temp[3] < '0' || temp[3] > '1' || temp[4] < '0' || temp[4] > '2') {
		printf("\t\t<< Invalid month >> \n");
	  OK = false ;
	}else

	if (temp[6] < '1' || temp[6] >'2'){
	 printf("\t\t<< Invalid year >>\n ");
	  OK = false ;
	}
	 }while(!OK);
return temp;
}

stu_rec getRecord(list *mylist){
	stu_rec temp;
	clrscr();
	printf("\n\t\t******************************************");
	printf("\n\t\t*********ADD NEW STUDENT RECORD***********");
	printf("\n\t\t******************************************");
	printf("\n");

	temp.StuID=getCode("\t  Student ID: ",mylist);

	strcpy(temp.name,getString("\t  Student Name:", 30,1));

	  do{
	strcpy(temp.add,getString("\t  Student address:"));
	  if(strlen(temp.add)<10)
	  printf("\t\t<< Address should not be Empty or \n\t\tIt should not less than 10 characters >>\n");
	  }while(strlen(temp.add)<10);

	strcpy(temp.gender,getString("\t  Student Gender [F or M]:",1,0));

	do{
	 printf("\t  Student Age:");
	 scanf("%d",&temp.age);

	 if((temp.age)<3)
	 printf("\t  <<Student age should not be Empty or \n\t\tIt should not more than 2 character>>\n");
	 }while((temp.age)<3);

	strcpy(temp.cno,getString("\t  Student Contact No:",10,2));




	do{
	strcpy(temp.status,getString("\t  Marital Status:"));

	 if(strlen(temp.status)>10)
	  printf("\t\t<<Marital Status should not be Empty or \n\t\tIt should not exceed 10 characters>>\n");
	  }while(strlen(temp.status)>10);

	 strcpy(temp.date,getDate());



	printf("\n\tPlease Press any key to continue!!");
	getch();
	clrscr();
	return temp;
}

int isEmpty(node* thelist){
	if(thelist == NULL)
		return 1;
	else
		return 0;
		}


void AddEntry(list*mylist, stu_rec x){
		node*newPtr=(node*)malloc(sizeof(node));
		node*prev=mylist->Node;
		newPtr->data=x;
		newPtr->next=NULL;
		if (isEmpty(mylist->Node))
			mylist->Node=newPtr;
		else
			if (mylist->Node->data.StuID > newPtr->data.StuID){
				  newPtr->next = mylist->Node;
				  mylist->Node = newPtr;
			 }else {
				while((prev->next!=NULL) &&(prev->next->data.StuID <x.StuID))
					prev=prev->next;
				newPtr->next=prev->next;
				prev->next=newPtr;

			}

		}

int getID(){
	int x;
	printf("\nPlease Enter Student ID: ");
	scanf("%d", &x);
return x;
}

void DeletEntry(list*mylist, int x){
		node*prev = mylist->Node;
		node*target;
		if(!isEmpty(mylist->Node))
			  if(mylist->Node->data.StuID == x){
				displayRec(mylist->Node);
				printf("\nDelete this Record [Y] >> ");
				if (toupper(getche()) == 'Y'){
					mylist->Node = mylist->Node->next;
					free(prev);
					printf("\n Record Deleted!");
					getch();
				}
			}
		else{
			target = mylist->Node;
			while((target!=NULL)&&(target->data.StuID !=x)){
				prev = target;
				target=target->next;
				}
				  if((target!=NULL) && (target->data.StuID==x)){
						displayRec(target);
						printf("\nDelete this Record [Y] >> ");
							if (toupper(getche()) == 'Y'){
								prev->next= target->next;
								printf("\n Record Deleted!");
								getch();
								free(target);
								getch();
							}
				  }
				 else
				 printf("\n Record Does Not Exist!");
				 printf("\n Please Press Any Key to Cotinue!!");
				 getch();
				 }
			}
void DisplayEntry(node*thelist){
		node*current=thelist;
		if(isEmpty(thelist)){
			printf("\nNo values insert by the user yet!!");
			getch();
		}else
			clrscr();
			printf("\n\t\t*************************************************");
			printf("\n\t\t  *********DISPLAY STUDENT RECORD****************");
			printf("\n\t\t*************************************************");
			printf("\n");
			while(current!=NULL){
				clrscr();
				displayRec(current);
				current=current->next;
			}
	}

void displayRec(node*current){
				if (current->data.StuID!=0){
					printf("\n\tStudent ID 	     :%d",current->data.StuID);
					printf("\n\tName                 :%s",current->data.name);
					printf("\n\tAddress              :%s",current->data.add);
					printf("\n\tGender               :%s",current->data.gender);
					printf("\n\tStatus               :%s",current->data.status);
					printf("\n\tAge                  :%d",current->data.age);
					printf("\n\tContact Number	     :%s",current->data.cno);
					printf("\n\tStudent D.O.B       :%s ",current->data.date);
					printf("\n\n\t Press any key to continue!!");
					getch();
					current=current->next;
			}

}

node * update(node * curr){
	 printf("\nChange Address [Y] >> ");
	 if (toupper(getche())== 'Y'){
			fflush(stdin);
			printf("\nEnter new Address >> ");
			gets(curr->data.add);
	 }
	 printf("\nChange contact No >>[Y] ");
	 if (toupper(getche())== 'Y'){
			printf("\nEnter new contact No >> ");
			gets(curr->data.cno);
	}
return curr;
}


void ModifyEntry(list *mylist, int ID){
	node *curr = mylist->Node;
	while(curr!=NULL){
		if(curr->data.StuID==ID){
			clrscr();
			printf("\n\t\t*************************************************");
			printf("\n\t\t**********R E C O R D    F O U N D!!*************");
			printf("\n\t\t*************************************************");
			printf("\n");
			displayRec(curr);
			curr = update(curr);
			return;
		}
		curr = curr->next;
	  }
	printf("Record does not exist!");
}



void SearchID(list*mylist, int x)
{
	node*curr=mylist->Node;
	while(curr!=NULL)
	{
		if(curr->data.StuID==x)
			{
			clrscr();
			printf("\n\t\t*************************************************");
			printf("\n\t\t**********R E C O R D    F O U N D!!*************");
			printf("\n\t\t*************************************************");
			printf("\n");
			displayRec(curr),
			getch();
				break;
			}
				curr=curr->next;
				}
				if(curr==NULL){
				printf("\n\t Sorry Record Does Not Exist!!");
				printf("\n\t Please PRESS any key to continue!!");
				getch();
				clrscr();
				}
	}

void write_file(list*mylist){
clrscr();
	FILE *fp;
	stu_rec temp;
	node* curr = mylist->Node;
	if ((fp=fopen("c:\data.dat", "wb"))==NULL)
		printf("\aError opening File! ");
	 else{
			 //printf("\nRecords Written to file from list!!");
			 while (curr!=NULL){
				 temp = curr->data;
				 fwrite((void *) &temp,sizeof(stu_rec),1,fp);
				 curr=curr->next;
			 }
	 fclose(fp);
	  }
}

void read_file(list*mylist){
clrscr();
	 FILE *fp;
	 node *curr;
	 node * prev =NULL;
	 stu_rec temp;
	 if ((fp=fopen("c\:Data.dat", "rb"))==NULL)
		printf("\aError opening File! ");
	 else{
		//printf("\nRecords Written from binary file to list!");
		while (!feof(fp)){
			 fread((void *)&temp,sizeof(stu_rec),1,fp);
			 AddEntry(mylist, temp);
			}
		curr = mylist->Node;
		while (curr->next!=NULL){
				 prev = curr;
				 curr=curr->next;
			 }
			 if (prev!=NULL) prev->next = curr->next;
//		DeletEntry(mylist,temp.StuID);
		fclose(fp);

		}
}