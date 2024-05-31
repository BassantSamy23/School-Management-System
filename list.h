Updates to keyboard shortcuts … On Thursday, August 1, 2024, Drive keyboard shortcuts will be updated to give you first-letters navigation.Learn more
#ifndef _LIST_H
#define _LIST_H
#include "STD_TYPES.h"
#define name_size 30
#define date_size 11
#define address_size 30 
#define phone_size 13
typedef u32 listEntry;
typedef struct student{
	u8 name[name_size];
	u8 date[date_size];
	u8 address[address_size];
	u8 phone_number [phone_size];
	listEntry ID; 
	listEntry grade_cs;
	struct student *pnext;
	struct student *pprev;
	struct student *pleft;
	struct student *pright;
	struct student *leftPtr;
	struct student *rightPtr;
}studentNode_t;

typedef struct {
	studentNode_t *phead;
	studentNode_t *ptail;
	listEntry listSize;
}list_t;

typedef enum{
	FALSE,//0
	TRUE//1
}bool_t;

typedef enum{
	NULL_PTR=1,//SAME SIZE OF INT
	OUT_OF_RANGE=2,
	SUCCESS=3
}ErrorState;
void insertNode( studentNode_t **treePtr, u32 value,u8 name1[name_size] ); 
void inOrder( studentNode_t *treePtr );
ErrorState STUDENT_Init(list_t *pL);//done 
ErrorState NEW_STUDENT(list_t *pL);//take the data inside the fn and order it alphabetic with strcompare  
ErrorState DELETE_STUDENT(list_t *pL,listEntry ID);//
ErrorState STUDENT_LIST(const list_t *pL);//done 
ErrorState STUDENT_EDIT(list_t *pL,listEntry ID);
ErrorState RANK_STUDENT(list_t *pL);//according to the grade of cs
ErrorState STUDENT_SCORE(list_t *pL);//update the score of all the students
ErrorState list_listSize(const list_t *pL, u32 *pSize);//print the number of the students
ErrorState list_searchNode(const list_t *pL,listEntry ID,studentNode_t **ppNode);
#endif
