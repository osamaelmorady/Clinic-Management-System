#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Database.c"
#include "Reservations.c"
#include "Lock.c"


/***************************************************************************************************************/
/*************************************** App Functions` Prototypes *********************************************/
/***************************************************************************************************************/
void AddPatient(void) ;
void RemovePatient(void) ;
void ViewPatient(void) ;
void MakeReservation(void) ;
void ViewReservations(void) ;
void PressAnyKey(void) ;


u32 Patient_ID ;
u8 Patient_Name[NAME_SIZE] ;
u8 Patient_Age[AGE_SIZE] ;
u8 Patient_Gender[GENDER_SIZE] ;
s32 ID_Exist ;
u8 CHK_key=0 ;
/***************************************************************************************************************/
/***************************************************************************************************************/



node *PatientDatabase=NULL ;
Tnode Reservations[6];


void main (void) {


/*******************************************************************************************************/
/*************************************** Welcome Interface *********************************************/
/*******************************************************************************************************/

system("cls");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
printf("*** Welcome To Alpha Clinic ***\n") ;
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
PressAnyKey() ;
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;



/***********************************************************************************************************/
/*************************************** Mode Selection Window *********************************************/
/***********************************************************************************************************/
u8 mode;
while (1)
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
	printf(" Admin Mode  -->  1 \n");
	printf(" User Mode   -->  2 \n");
	printf(" Exit        -->  # \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
	printf("Enter Mode : ");
	scanf("%c",&mode) ;
	fflush(stdin) ;
	
	
   /**************************************************************/
   /********************** Admin Mode Window *********************/
   /**************************************************************/
	if (mode=='1')
	{		

		/************* Password check  **************/
		/********************************************/
		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
		printf("~~~~~~~~  Login Window  ~~~~~~~\n") ;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
		u8 username[5];
		u8 password[5];
		printf("Enter Username : ") ;
		scanf("%[^\n]%*c",username) ;
		fflush(stdin) ;
		printf("Enter Password : ") ;
		scanf("%[^\n]%*c",password) ;
		fflush(stdin) ;
		u8 status=Check_Lock(username,password) ; 
		if (status)
		{
			while(1) 
			{
				system("cls");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
				printf(" To Add Patient         ->  1  \n") ;
				printf(" To Remove Patient      ->  2  \n") ;
				printf(" To Print Patient Data  ->  3  \n") ;
				printf(" To Make Reservation    ->  4  \n") ;
				printf(" Back                   ->  #  \n") ;
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
				u8 cmd ;
				printf("Enter Command : ");
				scanf("%c",&cmd) ;
				fflush(stdin) ;
		
				/******************** To Add Patient *******************/
				/*******************************************************/
				if (cmd=='1')
				{
					AddPatient() ;
					PressAnyKey() ;
			
				}
			
				/******************** To Remove Patient *******************/
				/**********************************************************/
				else if(cmd=='2')
				{
					RemovePatient() ;
					PressAnyKey() ;
				}
			
				/******************** To View Patient Data *******************/
				/*************************************************************/
				else if(cmd=='3')
				{
					ViewPatient() ;
					PressAnyKey() ;
				}
			
				/******************* To Make a Reservation ******************/
				/************************************************************/
				if (cmd=='4')
				{
					MakeReservation() ;
					PressAnyKey() ;
				}
			
				/***************** Back To the Previous Window **************/
				/************************************************************/
				else if(cmd=='#')
				{
					break ;
				}
			
				/************************* Wrong Input **********************/
				/************************************************************/
				else 
				{
					;
				}
			}
			
		}
		else 
		{
			printf("Wrong Password\n") ;
			PressAnyKey() ;	
		}
		
	}
	
	
   /**************************************************************/
   /*********************** User Mode Window *********************/
   /**************************************************************/
	else if (mode=='2')
	{
		
		while (1)
		{
			system("cls");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			printf(" To View Patient Data            ->  1  \n") ;
			printf(" To View Today`s Reservations    ->  2  \n") ;
			printf(" Back                            ->  #  \n") ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
		
		
			/******************** To View Patient Data *******************/
			/*************************************************************/
		
			u8 cmd ;
			printf("Enter Command : ");
			scanf("%c",&cmd) ;
			fflush(stdin) ;
			if (cmd=='1')
			{			
				ViewPatient() ;
				PressAnyKey() ;
				continue ;
			}
		
		
			/**************** To View Today`s Reservations ****************/
			/**************************************************************/
			else if (cmd=='2')
			{
				ViewReservations() ;
				PressAnyKey() ;		
				continue ;
			}
		
			/**************** To Back To Selection Mode ****************/
			/***********************************************************/
			else if(cmd=='#')
			{
				break ;
			
			}
			else 
			{
				continue ;
			}

		}
	
	}
	/*********************************************************************/
	/********************************* Exit ******************************/
	/*********************************************************************/
	else if (mode=='#')
	{
		exit(0) ;
	}
	
   /*********************************************************************/
   /****************************** Wrong Input **************************/
   /*********************************************************************/
	else 
	{
		
		printf("Wrong Input, Try again.")  ;
		continue ;
	}
}




}
















/********************************************************************************************************/
/*********************************************  App Fuctions  *******************************************/
/********************************************************************************************************/

void AddPatient(void)
{
system("cls");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
while (1) 
	{			
		printf("Enter Patient ID     : ");
		scanf("%d",&Patient_ID) ;
		fflush(stdin) ;
		
		// HotKey ('#')
		if (Patient_ID=='#') {break ;}
		
		ID_Exist=Index(&PatientDatabase,Patient_ID) ;
		if (ID_Exist!=-1)
		{
			printf("ID Already Exist \n") ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			printf("Press (a) To Add New ID : ") ;
			scanf("%c",&CHK_key) ;
			fflush(stdin) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			if (CHK_key=='a')
				{ continue ;  }
			else 
				{ break ;     }
		}
		else 
		{
			printf("Enter Patient Name   : ");
			scanf("%[^\n]%*c",Patient_Name) ;
			fflush(stdin) ;
			// HotKey ('#')
			if (Patient_Name[0]=='#') {break ;}
				
			printf("Enter Patient Age    : ");
			scanf("%[^\n]%*c",Patient_Age) ;
			fflush(stdin) ;
			// HotKey ('#')
			if (Patient_Age[0]=='#') {break ;}
				
			printf("Enter Patient Gender : ");
			scanf("%[^\n]%*c",Patient_Gender) ;
			fflush(stdin) ;
			// HotKey ('#')
			if (Patient_Gender[0]=='#') {break ;}
				
			Push(&PatientDatabase,Patient_ID,Patient_Name,Patient_Age,Patient_Gender) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			printf(" [ %d : %s ] has been added\n",Patient_ID,Patient_Name) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			break;	
		}
	}							
}




void RemovePatient(void)
{
system("cls");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
while (1) 
	{
		printf("Enter Patient ID     : ");
		scanf("%d",&Patient_ID) ;
		fflush(stdin) ;
		
		// HotKey ('#')
		if (Patient_ID=='#') {break ;}
		
		ID_Exist=Index(&PatientDatabase,Patient_ID) ;
		if (ID_Exist==-1)
		{
			printf("ID Already Not Exist \n") ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			printf("Press (a) To Add New ID : ") ;
			scanf("%c",&CHK_key) ;
			fflush(stdin) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			if (CHK_key=='a')
				{ continue ;  }
			else 
				{ break ;     }
			
		}
		else 
		{
			Get_Name(&PatientDatabase,Patient_ID,Patient_Name) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			printf("[ %d :  %s ]  has been deleted \n",Patient_ID,Patient_Name) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			Pop(&PatientDatabase,Patient_ID) ;
			break;
						
		}
	}
}





void ViewPatient(void)
{
system("cls");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
while(1)
	{
		printf("Enter Patient ID to Print Data : ") ;
		scanf("%d",&Patient_ID) ;
		fflush(stdin) ;
		
		// HotKey ('#')
		if (Patient_ID=='#') {break ;}
	
		ID_Exist=Index(&PatientDatabase,Patient_ID) ;
		if (ID_Exist==-1)
		{
			printf("ID Not Exist \n") ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			printf("Press (a) To Add New ID : ") ;
			scanf("%c",&CHK_key) ;
			fflush(stdin) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			if (CHK_key=='a')
				{ continue ;  }
			else 
				{ break ;     }
		}
		else 
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			Get_Name(&PatientDatabase,Patient_ID,Patient_Name) ;
			Get_Age(&PatientDatabase,Patient_ID,Patient_Age);
			Get_Gender(&PatientDatabase,Patient_ID,Patient_Gender) ;
			printf("Patient ID      : %d\n",Patient_ID) ;
			printf("Patient Name    : %s\n",Patient_Name) ;
			printf("Patient Age     : %s\n",Patient_Age) ;
			printf("Patient Gender  : %s\n",Patient_Gender) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			break;
		}
	}			
}






void MakeReservation(void)
{
		
	
system("cls");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
printf("~  2:00  ~  2:30  ~  3:00  ~  3:30  ~  4:00  ~  4:30  ~\n") ;
printf("~    0   ~    1   ~    2   ~    3   ~    4   ~    5   ~\n") ;
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
while(1)
	{
		printf("Enter Patient ID to Make a Reservation : ") ;
		scanf("%d",&Patient_ID) ;
		fflush(stdin) ;
		
		// HotKey ('#')
		if (Patient_ID=='#') {break ;}
				
		ID_Exist=Index(&PatientDatabase,Patient_ID) ;
		if (ID_Exist==-1)
		{
			printf("ID Not Exist \n") ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			printf("Press (a) To Add New ID : ") ;
			scanf("%c",&CHK_key) ;
			fflush(stdin) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			if (CHK_key=='a')
				{ continue ;  }
			else 
				{ break ;     }
		}
		else 
		{
			
			u8 Time_num ;
			u8 Time_data[TIME_SIZE] ;
			printf("Enter The Time To Make Reservation : ") ;
			scanf("%d",&Time_num) ;
			fflush(stdin) ;
			Get_Name(&PatientDatabase,Patient_ID,Patient_Name) ;
			Set_Time(Reservations,Time_num,Patient_ID) ;
			Get_Time(Reservations,Time_num,Time_data) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			printf(" Reservation has been Submitted [ %s ~~>>  %d  : %s  ] \n",Time_data,Patient_ID,Patient_Name) ;
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			break;	
				
		}
	}	
	
	
}



void ViewReservations(void)
{
system("cls") ;
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`\n") ;
u8 searched_id ;
u8 Time_data[TIME_SIZE] ;
for (u8 i=0;i<6;i++)
{
	Get_ResID(Reservations,i,&searched_id) ;
	Get_Name(&PatientDatabase,searched_id,Patient_Name) ;
	Get_Time(Reservations,i,Time_data) ;
	printf("Time : %s ~~  Name :  %s   \n",Time_data,Patient_Name)	;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`\n") ;
}	
	
}



void PressAnyKey()
{
	
printf("Press any key to continue... ") ;
scanf("%c",&CHK_key) ;
fflush(stdin) ;	
}

