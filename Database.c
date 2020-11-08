#include "STD_TYPES.h"
#define NAME_SIZE 30
#define AGE_SIZE 10
#define GENDER_SIZE 10 
	
	
	
	



typedef struct node {
	u8 ID ;
	u8 Name[NAME_SIZE] ;
	u8 Age[AGE_SIZE] ;
	u8 Gender[GENDER_SIZE] ;
	struct node *next ;   }node ;
	

	
node * CreateNode();
u8 Empty(node **head) ;	
s32 Index(node **head,u32 id) ;
u32 Length(node **head) ;


void Set_Name ( node *ptr , u8 word[NAME_SIZE] )  ;
void Set_Age ( node *ptr , u8 word[AGE_SIZE] )  ;
void Set_Gender ( node *ptr , u8 word[GENDER_SIZE] )  ;

void Push(node **head,u32 id,u8 name[NAME_SIZE],u8 age[AGE_SIZE],u8 gender[GENDER_SIZE]) ;
s32 Pop(node **head,u32 id) ;
void Edit(node **head,u32 id,u8 newname[NAME_SIZE],u8 newage[AGE_SIZE],u8 newgender[GENDER_SIZE]) ;


void Get_Name(node **head,u32 id,u8 name[NAME_SIZE]);
void Get_Age(node **head,u32 id,u8 age[AGE_SIZE]);
void Get_Gender(node **head,u32 id,u8 gender[GENDER_SIZE]);

void Print_Info(node **head,u32 id) ;












node * CreateNode(){
	node *temp=(node *)malloc(sizeof(node)) ;
	return temp ;
}



u8 Empty(node **head) {
	node * temp=*head ;
	if (temp==NULL) {return 1 ;}
	else { return 0 ;     }
}


s32 Index(node **head,u32 id){
	if (Empty(head)) {return -1 ;}
	else {
		s32 count=0 ; u8 flag=0 ;
		node *current=*head ;
		
		while(current!=NULL)
			{ if (current->ID==id){
				flag=1 ;
				break ;}
				
			else {
				current=current->next ;
				count++;
				flag=0 ;}			
			}
			
		if (flag)  {return count ;}
		else 	   {return -1 ; }

	}
}



u32 Length(node **head) {
	if (Empty(head)) {return 0 ;}
	else {
		node * current=*head ;
		u32 count=0 ;
		
		while (current!=NULL)  {
			current=current->next ;
			count++ ;
		} 
		
		return count ;
		
	}
	
}




void Set_Name ( node *ptr , u8 word[NAME_SIZE] ) 
{	u8 i=0 ;
	u8 count ;
	for (i=0;word[i]!='\0';i++)
	{
	ptr->Name[i]=word[i] ;
	count=i ;
	}
	count=count+1;
	for (count;count<NAME_SIZE;count++)
	{
	ptr->Name[count]='\0' ;
	}
	
}

void Set_Age ( node *ptr , u8 word[AGE_SIZE]) 
{	
	u8 i=0 ;
	u8 count ;
	for (i=0;word[i]!='\0';i++)
	{
	ptr->Age[i]=word[i] ;
	count=i ;
	}
	count=count+1;
	for (count;count<AGE_SIZE;count++)
	{
	ptr->Age[count]='\0' ;
	}
	
	
}

void Set_Gender ( node *ptr , u8 word[GENDER_SIZE]) 
{	
	u8 i=0 ;
	u8 count ;
	for (i=0;word[i]!='\0';i++)
	{
	ptr->Gender[i]=word[i] ;
	count=i ;
	}
	count=count+1;
	for (count;count<GENDER_SIZE;count++)
	{
	ptr->Gender[count]='\0' ;
	}
	
}



void Push(node **head,u32 id,u8 name[NAME_SIZE],u8 age[AGE_SIZE],u8 gender[GENDER_SIZE]) {
	if (Empty(head)) {*head=CreateNode() ;  
						(*head)->ID=id;
						Set_Name(*head,name) ;
						Set_Age(*head,age) ; 
						Set_Gender(*head,gender) ;
						(*head)->next=NULL ;         }
	else {
		node *temp=CreateNode() ; 
		temp->ID=id ;
		Set_Name(temp,name) ;
		Set_Age(temp,age) ; 
		Set_Gender(temp,gender) ;
		temp->next=NULL ;
		
		
		node *current=*head ;
		while (current->next!=NULL) {
			current=current->next ;		}
			
		current->next=temp ;
	}

}



s32 Pop(node **head,u32 id) {
	s32 index=Index(head,id) ;
	if (index!=-1) {
		if (index==0) {
			node *temp=*head ;
			*head=(*head)->next ;
			free(temp) ;
			return index ;
		}
		
		else {
		node *current=*head ;
		
		for(u32 i=0;i<index-1;i++)
			{current=current->next ;	}
		
		node *temp =current->next ;
		current->next=temp->next ;
		free(temp) ;

		return index ;}
	}	

	else {
		return index ;
	}

}


void Edit(node **head,u32 id,u8 newname[NAME_SIZE],u8 newage[AGE_SIZE],u8 newgender[GENDER_SIZE]) {
	s32 index=Index(head,id) ;
	if (index==-1) { 
	// no operation
	}
	else {
		node *current=*head ;
		for (u32 i=0;i<index ; i++)
		{current=current->next ;
			
		}
		Set_Name(current,newname) ;
		Set_Age(current,newage) ;
		Set_Gender(current,newgender) ;
	}
}



void Get_Name(node **head,u32 id,u8 name[NAME_SIZE]) {
	u32 len=Length(head) ;
	s32 pos=Index(head,id) ;
	if (pos>=len || pos==-1) {
		for (u8 i=0;i<NAME_SIZE;i++)
		{
		name[i]='\0' ;
		}
	
	}
	else  {
		
		node *current=*head ;
		for (u32 i=0;i<pos;i++) {
			current=current->next ;
		}
		
		for (u8 i=0;i<NAME_SIZE;i++)
		{
		name[i]=current->Name[i] ;
		}		
	}
}


void Get_Age(node **head,u32 id,u8 age[AGE_SIZE]) 
{
	u32 len=Length(head) ;
	s32 pos=Index(head,id) ;
	if (pos>=len || pos==-1) {
		for (u8 i=0;i<AGE_SIZE;i++)
		{
		age[i]='\0' ;
		}
	
	}
	else  {
		
		node *current=*head ;
		for (u32 i=0;i<pos;i++) {
			current=current->next ;
		}
		
		for (u8 i=0;i<AGE_SIZE;i++)
		{
		age[i]=current->Age[i] ;
		}		
	}
	
}


void Get_Gender(node **head,u32 id,u8 gender[GENDER_SIZE]) {
	u32 len=Length(head) ;
	s32 pos=Index(head,id) ;
	if (pos>=len || pos==-1) {
		for (u8 i=0;i<GENDER_SIZE;i++)
		{
		gender[i]='\0' ;
		}
	
	}
	else  {
		
		node *current=*head ;
		for (u32 i=0;i<pos;i++) {
			current=current->next ;
		}
		
		for (u8 i=0;i<GENDER_SIZE;i++)
		{
		gender[i]=current->Gender[i] ;
		}		
	}
}



void Print_Info(node **head,u32 id) {	
	s32 index=Index(head,id) ;
	if (index==-1) {printf("NONE\n") ;}
	else  {
		u8 name[NAME_SIZE] ;
		u8 age[AGE_SIZE] ;
		u8 gender[GENDER_SIZE] ;
		Get_Name(head,id,name);
		Get_Age(head,id,age);
		Get_Gender(head,id,gender) ;
		printf("ID     : %d\n",id) ;
		printf("Name   : %s\n",name) ;
		printf("Age    : %s\n",age) ;
		printf("Gender : %s\n",gender) ;
	}
	
}


