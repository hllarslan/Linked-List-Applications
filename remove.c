// Halil Arslan - @hllarslan

//This very beginner version of my first linked list implementation and first experience on GitHub


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct node{
	char string[100];
	struct node *next;
}node_t;



void push(node_t *head);
void print_list(node_t *head);
void rem(node_t *head);


int main()
{
	
	node_t *head=NULL;
	char string1[100];
    	
	
	printf("Enter a word:");
	scanf("%s",string1);
	
	head=malloc(sizeof(node_t));
	if(head==NULL)
	{
		return 1;
	}
	
	
	strcpy(head->string,string1);
	head->next=NULL;
	push(head);
	print_list(head);
	
	
	printf("\n\n New List\n\n");
	rem(head);
	print_list(head);
	
	
	
}


void push(node_t *head)
{
	node_t *current=head;
	char string2[100];
	int i;
	do{
	printf("Enter a word:");
	scanf("%s",string2);
	
	while(current->next!=NULL)
	{
		current=current->next;
	}
	
	current->next=malloc(sizeof(node_t));
	strcpy(current->next->string,string2);
	current->next->next=NULL;
	printf("to exit:");
	scanf("%d",&i);
	}while(i!=-1);
	

}

void print_list(node_t *head)
{
	node_t *current=head;
	
	while(current!=NULL)
	{
		printf("%s ",current->string);
		current=current->next;
	}
}


void rem(node_t *head)
{
	node_t *currentPtr;
	
	node_t *previousPtr=NULL;
	
	currentPtr=head;
	char string3[100];
	printf("Enter a string to remove:");
	scanf("%s",string3);
	
	
	
	while(strcmp(currentPtr->string,string3))
	{
		previousPtr=currentPtr;
		currentPtr=currentPtr->next;
	}
	
	previousPtr->next=currentPtr->next;
	free(currentPtr);
	

	
	
	
}
