#include <stdio.h>
#include "STD_TYPES.h"

#define USERNAME_SIZE 1
#define PASSWORD_SIZE 1

typedef struct Lock
{
	u8 UserName[USERNAME_SIZE] ;
	u8 UserPassword[PASSWORD_SIZE] ;
	
}Lock ;

u8 Check_Lock(u8 *user,u8 *password) ;



Lock User1 ={"",""};


/*void main (void)
{
	u8 c;
	c=Check_Lock("osama","01234") ;
	if (c)
	{
		printf("OK") ;
	}
	else 
	{
		printf("NOT OK") ;
	}
	
}*/


u8 Check_Lock(u8 *user,u8 *password) 
{
	u8 flag=0 ;
	for (u8 i=0;i<USERNAME_SIZE;i++)
	{
		if (user[i]==User1.UserName[i])
		{	flag=1;			}
		else 
		{	flag=0; break ;	}
	}
	printf("%d\n",flag) ;
	if (flag==1)
	{
		for (u8 i=0;i<PASSWORD_SIZE;i++)
		{
			if (password[i]==User1.UserPassword[i])
			{	
				flag=1;	
			}
			else 
			{
				flag=0;
				break ;
			}
			
		}
		
		
	}
	printf("%d\n",flag) ;
	
	return flag ;

}
