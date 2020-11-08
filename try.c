


#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Interface.h"




node *PatientDatabase=NULL ;
node *Reservations=NULL ;
u8 CHK_key ;

u32 Patient_ID ;
u8 Patient_Name[NAME_SIZE] ;
u8 Patient_Age[AGE_SIZE] ;
u8 Patient_Gender[GENDER_SIZE] ;
s32 ID_Exist ;

void main (void) {


/*********************/
/* Welcome Interface */
/*********************/
system("cls");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
printf("*** Welcome To Alpha Clinic ***\n") ;
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;

printf("Press any key to continue... ") ;
scanf("%c",&CHK_key) ;
fflush(stdin) ;
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;



/*********************************/
/***** Mode Selection Window *****/
/*********************************/
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
	
	
	
	/*****************************/
	/***** Admin Mode Window *****/
	/*****************************/
	if (mode=='1')
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
			

			
			
			/***** To Add Patient *****/
			/**************************/
			if (cmd=='1')
			{
				system("cls");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
				while (1) 
				{
					
					printf("Enter Patient ID     : ");
					scanf("%d",&Patient_ID) ;
					fflush(stdin) ;
					ID_Exist=Index(&PatientDatabase,Patient_ID) ;
					if (ID_Exist!=-1)
					{
						printf("ID Already Exist \n") ;
						printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
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
						scanf("%s",Patient_Name) ;
						fflush(stdin) ;
				
						printf("Enter Patient Age    : ");
						scanf("%s",Patient_Age) ;
						fflush(stdin) ;
				
						printf("Enter Patient Gender : ");
						scanf("%s",Patient_Gender) ;
						fflush(stdin) ;
				
						Push(&PatientDatabase,Patient_ID,Patient_Name,Patient_Age,Patient_Gender) ;
						printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
						printf(" [ %d : %s ] has been added\n",Patient_ID,Patient_Name) ;
						printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
						break;	
					}
				}						
				
				printf("Press any key to continue... ") ;
				scanf("%c",&CHK_key) ;
				fflush(stdin) ;
				continue ;
			
			}
			
			/***** To Remove Patient *****/
			/**************************/
			else if(cmd=='2')
			{
				system("cls");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
				while (1) 
				{
					printf("Enter Patient ID     : ");
					scanf("%d",&Patient_ID) ;
					fflush(stdin) ;
					ID_Exist=Index(&PatientDatabase,Patient_ID) ;
					if (ID_Exist==-1)
					{
						printf("ID Already Not Exist \n") ;
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
						printf("[ %d :  %s ]  has been deleted ",Patient_ID,Patient_Name) ;
						Pop(&PatientDatabase,Patient_ID) ;
						break;
						
					}
				}
				printf("Press any key to continue... ") ;
				scanf("%c",&CHK_key) ;
				fflush(stdin) ;
				continue ;
			}
			
			/***** To Print Patient Data *****/
			/*********************************/
			else if(cmd=='3')
			{
				system("cls");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
				while(1)
				{
					printf("Enter Patient ID to Print Data : ") ;
					scanf("%d",&Patient_ID) ;
					fflush(stdin) ;
				
					ID_Exist=Index(&PatientDatabase,Patient_ID) ;
					if (ID_Exist==-1)
					{
						printf("ID Not Exist \n") ;
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
				printf("Press any key to continue... ") ;
				scanf("%c",&CHK_key) ;
				fflush(stdin) ;
				continue ;
				
			}
			
			
			/***** To Make Reservations *****/
			/********************************/
			if (cmd=='4')
			{
				system("cls");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
				while(1)
				{
					printf("Enter Patient ID to Make a Reservation : ") ;
					scanf("%d",&Patient_ID) ;
					fflush(stdin) ;
				
					ID_Exist=Index(&PatientDatabase,Patient_ID) ;
					if (ID_Exist==-1)
					{
						printf("ID Not Exist \n") ;
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
						Get_Age(&PatientDatabase,Patient_ID,Patient_Age);
						Get_Gender(&PatientDatabase,Patient_ID,Patient_Gender) ;
						Push(&Reservations,Patient_ID,Patient_Name,Patient_Age,Patient_Gender) ;
						printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
						printf(" Reservation has been Submitted for [ %d : %s ] \n",Patient_ID,Patient_Name) ;
						printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
						break;	
				
				
					}
				}
				printf("Press any key to continue... ") ;
				scanf("%c",&CHK_key) ;
				fflush(stdin) ;
				continue ;
			}
			
			/***** To Back To The Previous Window ****/
			/*****************************************/
			else if(cmd=='#')
			{
				break ;
			}
			
			
			/***** Wrong Input *****/
			/***********************/
			else 
			{
				continue ;
			}
		}
		;
	}
	
	
	
	/****************************/
	/***** User Mode Window *****/
	/****************************/
	else if (mode=='2')
	{
		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
		printf(" To View Patient Data            ->  1  \n") ;
		printf(" To View Today`s Reservations    ->  2  \n") ;
		printf(" Back                            ->  #  \n") ;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
		
		
		/***** To View Patient Data *****/
		/********************************/
		u8 cmd ;
		printf("Enter Command : ");
		scanf("%c",&cmd) ;
		fflush(stdin) ;
			
		if (cmd=='1')
		{			
			system("cls");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
			while(1)
			{
				printf("Enter Patient ID to Print Data : ") ;
				scanf("%d",&Patient_ID) ;
				fflush(stdin) ;
				
				ID_Exist=Index(&PatientDatabase,Patient_ID) ;
				if (ID_Exist==-1)
				{
					printf("ID Not Exist \n") ;
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
			printf("Press any key to continue... ") ;
			scanf("%c",&CHK_key) ;
			fflush(stdin) ;
			continue ;
		}
		
		
		/***** To View Today`s Reservations *****/
		/****************************************/
		else if (cmd=='2')
		{
			
			break ;	
			
			
		}
		
		
		else if (cmd=='3')
		{
			break ;
		}
		else 
		{
			continue ;
		}
		
		
	}
	
	
	
	/*******************/
	/***** To Exit *****/
	/*******************/
	else if (mode=='#')
	{
		exit(0) ;
	}
	
	
	
	/******************************/
	/***** Wrong Input Window *****/
	/******************************/
	else 
	{
		
		printf("Wrong Input, Try again.")  ;
		continue ;
	}
}

}



