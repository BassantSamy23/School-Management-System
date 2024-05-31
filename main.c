Updates to keyboard shortcuts … On Thursday, August 1, 2024, Drive keyboard shortcuts will be updated to give you first-letters navigation.Learn more
#include <stdio.h>
#include "list.h"
#include "STD_TYPES.h"
#include <stdlib.h>
#define ADD 1
#define DELETE 2
#define SEARCH 3 
#define SHOW_LIST 4
#define SIZE 5
#define SCORE 6
#define RANK 7
#define EDIT 8
#define EXIT 9

int main()
{
	u32 choice;
	list_t L;
    STUDENT_Init(&L);
	listEntry st_id;
	do{
	printf("=======================\n");
	printf("please Enter Choice: \n");
	printf("=======================\n");
	printf("1-ADD NEW STUDENT\n2-DELETE STUDENT\n3-SEARCH STUDENT\n4-SHOW LIST \n5-STUDENTS NUMBER\n6-ENTER CS GRADES\n7-RANK\n8-EDIT STUDENT DATA\n9-EXIT\n");
	fflush(stdin);
	scanf("%d",&choice);
	switch(choice){
		case ADD:
		{
			NEW_STUDENT(&L);
			break;
		}
		case DELETE:
		{
			printf("Enter the student ID: ");
			scanf("%d",&st_id);
			DELETE_STUDENT(&L,st_id);
			break;
		}
		case SEARCH:
		{
		studentNode_t *psearch;
		printf("enter the ID: \n");
		scanf("%d",&st_id);
		list_searchNode(&L,st_id,&psearch);
		if(psearch==NULL) printf("ID not found\n");
		else 
		printf("the address of the ID is: %d\n",psearch);
		break;
		}
		case SHOW_LIST:
		{
			STUDENT_LIST(&L);
			break;
		}
		case SIZE:
		{
			u32 size;
			list_listSize(&L, &size);
			printf("the students number= %d\n",size);
			break;
		}
		case SCORE:
		{
			STUDENT_SCORE(&L);
			break;
		}
		case RANK:
		{
			RANK_STUDENT(&L);
			break;
		}
		case EDIT:
		{
			printf("Enter the student id: ");
			scanf("%d",&st_id);
			STUDENT_EDIT(&L,st_id);
			break;
		}
		case EXIT:
		{
			break;
		}
	default: 
	printf("Wrong Choice !\n");
	}
	}
	while(choice!=9);
}
	
	
