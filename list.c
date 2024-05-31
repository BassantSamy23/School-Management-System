Updates to keyboard shortcuts … On Thursday, August 1, 2024, Drive keyboard shortcuts will be updated to give you first-letters navigation.Learn more
#include <stdio.h>
#include "list.h"
#include "STD_TYPES.h"
#include <stdlib.h>
#include <string.h>

studentNode_t *rootPtr ;
static ErrorState STUDENT_IsEmpty(const list_t *pL,bool_t *pstate);
ErrorState STUDENT_Init(list_t *pL)//done
{
	pL->phead=pL->ptail=NULL;
	pL->listSize=0;
	rootPtr=NULL;
}
ErrorState NEW_STUDENT(list_t *pL)//done
{
	studentNode_t* pn=(studentNode_t*)malloc(sizeof(studentNode_t));
	if(pn==NULL)
	{
		printf("heap is full\n");
	}
	else
	{
		printf("Enter the Student Name: ");
		fflush(stdin);
		gets(pn->name);
		fflush(stdin);
		printf("Enter the Student Date of birth: ");
		fflush(stdin);
		gets(pn->date);
		fflush(stdin);
		printf("Enter the Student Address: ");
		fflush(stdin);
		gets(pn->address);
		fflush(stdin);
		printf("Enter the Student Phone Number: ");
		fflush(stdin);
		gets(pn->phone_number);
		fflush(stdin);
		printf("Enter the Student ID: ");
		fflush(stdin);
		scanf("%d",&pn->ID);
		fflush(stdin);
		printf("Enter the Student CS grade: ");
		fflush(stdin);
		scanf("%d",&pn->grade_cs);
		fflush(stdin);
		pn->pnext=NULL;
		pn->pprev=NULL;
		bool_t state;
	STUDENT_IsEmpty(pL, &state);
	if(state==TRUE) 
	{
		pL->phead=pL->ptail=pn;
		pL->listSize++;
	}
	else
	{
		studentNode_t *temp=pL->phead;
		while(temp!=NULL&&(strcmp(temp->name,pn->name))==-1)
		{
			temp=temp->pnext;
		}
		if(temp==pL->phead)//@ head while will be false becase the second condition is false
		{
			pn->pnext=temp;
			temp->pprev=pn;
			pL->phead=pn;
		}
		else if(temp==NULL)
		{
			pn->pprev=pL->ptail;
			pL->ptail->pnext=pn;
			pL->ptail=pn;
		}
		else//middle
		{
			pn->pprev=temp->pprev;
			pn->pnext=temp;
			temp->pprev->pnext=pn;
			temp->pprev=pn;
		}
		pL->listSize++;
	}
	}
	insertNode(&rootPtr,pn->grade_cs,pn->name);
}
ErrorState DELETE_STUDENT(list_t *pL,listEntry id)//done
{
		bool_t state;
	STUDENT_IsEmpty(pL, &state);
	if(state==TRUE) 
	{
		printf("can not delete\n");
	}
	else{
		studentNode_t *temp;
		list_searchNode(pL,id,&temp);
		if(temp==NULL) printf("ID not found\n");
		else
		{
			if(pL->phead==pL->ptail)
			{
				free(pL->phead);
				pL->phead=pL->ptail=NULL;
			}
			else if(pL->phead==temp)
			{
				pL->phead=pL->phead->pnext;
				free(pL->phead->pprev);
				pL->phead->pprev=NULL;
			}
			else if(pL->ptail==temp)//@head
			{
				pL->ptail=pL->ptail->pprev;
				free(pL->ptail->pnext);
				pL->ptail->pprev->pnext=NULL;
			}
			else //@mid
			{
				temp->pprev->pnext=temp->pnext;
				temp->pnext->pprev=temp->pprev;
			}
			pL->listSize--;
		}
	}
}
ErrorState STUDENT_LIST(const list_t *pL)//done
{
	bool_t state;
	STUDENT_IsEmpty(pL, &state);
	if(state==TRUE) printf("List is empty:");
	else
	{
		studentNode_t *temp;
	for(temp=pL->phead;temp!=NULL;temp=temp->pnext)
	{
		printf("Name : %s\n",temp->name);
		printf("Date of bith : %s\n",temp->date);
		printf("Address : %s\n",temp->address);
		printf("Phone number : %s\n",temp->phone_number);
		printf("ID : %d\n",temp->ID);
		printf("CS Grade : %d\n",temp->grade_cs);
		printf("=======================================================\n");
	}
	}
}
ErrorState STUDENT_EDIT(list_t *pL,listEntry id)
{
	bool_t state;
	STUDENT_IsEmpty(pL, &state);
	if(state==TRUE) 
	{
		printf("List is Empty!!!\n");
	}
	else{
		studentNode_t *temp;
		list_searchNode(pL,id,&temp);
		if(temp==NULL) printf("ID not found\n");
		else
		{
		printf("Enter the Student Date of birth: ");
		fflush(stdin);
		gets(temp->date);
		fflush(stdin);
		printf("Enter the Student Address: ");
		fflush(stdin);
		gets(temp->address);
		fflush(stdin);
		printf("Enter the Student Phone Number: ");
		fflush(stdin);
		gets(temp->phone_number);
		fflush(stdin);
		}
	}
}
ErrorState RANK_STUDENT( list_t *pL)
{
	inOrder(rootPtr);
}
ErrorState STUDENT_SCORE(list_t *pL)//done
{
	studentNode_t *temp;
	for(temp=pL->phead;temp!=NULL;temp=temp->pnext)
	{
		printf("Enter the CS Grade of the studend: ");
		scanf("%d",&(temp->grade_cs));
		printf("\n");
	}
}
ErrorState list_listSize(const list_t *pL, u32 *pSize)//done
{
	*pSize=pL->listSize;
}
ErrorState list_searchNode(const list_t *pL,listEntry id,studentNode_t **ppNode)//done
{
	bool_t state;
	STUDENT_IsEmpty(pL, &state);
	if(state==TRUE) {printf("List is empty!\n"); *ppNode=NULL;}
	else{
	studentNode_t *temp=pL->phead;
	u8 i=0;
	while(temp!=NULL && temp->ID !=id)//1-list ends, 2- or there's an element smaller than the data  entered----> those break the loop
		{
			temp=temp->pnext;
			i++;
		}
		*ppNode= temp;
		printf("Student number is : %d\n",i+1);
	}
}
static ErrorState STUDENT_IsEmpty(const list_t *pL,bool_t *pstate)//done
{
	if(pL->phead==NULL) *pstate=TRUE;
	else *pstate =FALSE;
}
void insertNode( studentNode_t **treePtr, u32 value,u8 name1[name_size])
{
	 if ( *treePtr == NULL ) {
		 *treePtr =(studentNode_t*) malloc( sizeof( studentNode_t ) );
		 if ( *treePtr != NULL ) {
			 ( *treePtr )->grade_cs = value; 
             strcpy(( *treePtr )->name,name1);
			 ( *treePtr )->leftPtr = NULL; 
			 ( *treePtr )->rightPtr = NULL;
		 } 
	 }
	 else
	 {
		 if ( value < ( *treePtr )-> grade_cs) {
			insertNode( &( ( *treePtr )->leftPtr ), value,name1);
		} 
		else if ( value >=( *treePtr )->grade_cs) {
			insertNode( &( ( *treePtr )->rightPtr ), value ,name1);
		}
	 }
}
void inOrder( studentNode_t *treePtr )
{
	if ( treePtr != NULL ) {
	inOrder( treePtr->rightPtr );
	printf( "%s============>%3d\n",treePtr->name, treePtr->grade_cs);
	inOrder( treePtr->leftPtr );
	} 
}
