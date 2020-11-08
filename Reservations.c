
#include <stdio.h>
#include "STD_TYPES.h"

#define TIME_SIZE 10
#define TIME0 0
#define TIME1 1
#define TIME2 2
#define TIME3 3
#define TIME4 4
#define TIME5 5


typedef struct Tnode
{
	u8 Periods[TIME_SIZE];
	u8 ID_2 ;
}	Tnode ;


u8 Periods[6][TIME_SIZE]={"2:00","2:30","3:00","3:30","4:00","4:30"} ;
// Tnode Reservations[6];

void Set_Time(Tnode *schedule,u8 time_num,u8 id) ;
void Get_Time (Tnode *schedule,u8 reservation_num,u8 Periods[TIME_SIZE]) ;
void Get_ResID(Tnode *schedule,u8 time_num,u8 *res_id) ;




void Set_Time(Tnode *schedule,u8 time_num,u8 id)
{
	
	
	switch (time_num)
	{
		case TIME0 :
			for (u8 i=0;i<TIME_SIZE;i++)  { schedule[0].Periods[i]=Periods[0][i] ; }
			schedule[0].ID_2 = id ;
			break ;
		case TIME1 :
			for (u8 i=0;i<TIME_SIZE;i++)  { schedule[1].Periods[i]=Periods[1][i] ; }
			schedule[1].ID_2 = id ;
			break ;
		case TIME2 :
			for (u8 i=0;i<TIME_SIZE;i++)  { schedule[2].Periods[i]=Periods[2][i] ; }
			schedule[2].ID_2 = id ;
			break ;
		case TIME3 :
			for (u8 i=0;i<TIME_SIZE;i++)  { schedule[3].Periods[i]=Periods[3][i] ; }
			schedule[3].ID_2 = id ;
			break ;
		case TIME4 :
			for (u8 i=0;i<TIME_SIZE;i++)  { schedule[4].Periods[i]=Periods[4][i] ; }
			schedule[4].ID_2 = id ;
			break ;
		case TIME5 :
			for (u8 i=0;i<TIME_SIZE;i++)  { schedule[5].Periods[i]=Periods[5][i] ; }
			schedule[5].ID_2 = id ;
			break ;			
		default :
			break ;
	}
}

void Get_Time (Tnode *schedule,u8 reservation_num,u8 Periods[TIME_SIZE])
{	
	for(u8 i=0;i<TIME_SIZE;i++)
	{
	Periods[i] = schedule[reservation_num].Periods[i] ;
	}
	
}	


	
void Get_ResID(Tnode *schedule,u8 time_num,u8 *res_id)
{
	switch (time_num)
	{
		case TIME0 :
			*res_id=schedule[0].ID_2 ;
			break ;
		case TIME1 :
			*res_id=schedule[1].ID_2 ;
			break ;
		case TIME2 :
			*res_id=schedule[2].ID_2 ;
			break ;
		case TIME3 :
			*res_id=schedule[3].ID_2 ;
			break ;
		case TIME4 :
			*res_id=schedule[4].ID_2 ;
			break ;
		case TIME5 :
			*res_id=schedule[5].ID_2 ;
			break ;			
		default :
			break ;
		
	}
	
}




/*
void main (void) {
	
	 u8 Periods[TIME_SIZE] ;
	
	Set_Time(Reservations,TIME0,1) ;
	Get_Time(Reservations,TIME0,Periods) ;
	printf("%s",Periods) ;
}*/

