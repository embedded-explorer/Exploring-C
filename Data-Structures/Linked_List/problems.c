
//----------------------------------------------------------------------
// Problem 1.
//----------------------------------------------------------------------

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include "problems.h"

// ------------------ Transaction Handling Functions -------------------

//--------------------------------------------------
// Function to create and initialize transaction list
// @return : List pointer
//--------------------------------------------------
Transaction_List *initialize_trans_list(){

	Transaction_List *trans_list;

	trans_list = (Transaction_List*)malloc(sizeof(Transaction_List));

	if(trans_list == NULL)
		return NULL;

	trans_list->head = NULL;
	trans_list->tail = NULL;
	trans_list->trans_count = 0;
	trans_list->insert_count = 0;
	trans_list->delete_count = 0;

	return trans_list;
}

//--------------------------------------------------
// Function to create transaction node
// @param  : Operation {insert, delete}
// @return : Transaction_Node pointer
//--------------------------------------------------
Transaction_Node *create_trans_node(Operation oper){
	
	Transaction trans; // Transaction structure variable
	Transaction_Node *new_node; // Node pointer
    
	time_t curr_time; // variable to store current time
	struct tm *time_comp; // variable to store components of time
	
	// Allocate memory for node
	new_node = (Transaction_Node *)malloc(sizeof(Transaction_Node));

	if(new_node == NULL)
		return NULL; // Memory allocation failed
    
	time(&curr_time); // Obtain current time
	time_comp = localtime(&curr_time); // Get time components
	
	// Set transaction operation
	trans.type_of_operation = oper;
	
	// Convert transaction date to string
	strftime(trans.transaction_date, sizeof(trans.transaction_date),\
            	"%d-%m-%Y", time_comp);
	// Convert transaction time to string
	strftime(trans.transaction_time, sizeof(trans.transaction_time),\
	            "%H-%M-%S", time_comp);

	new_node->trans_data = trans;
	new_node->ptr  = NULL;

	return new_node;
}

//--------------------------------------------------
// Function to insert transaction details at beginning
// @param  : Transaction_List pointer
// @param  : Operation {insert, delete}
// @return : int status
//--------------------------------------------------
int insert_transaction(Transaction_List *my_list, Operation oper){

	Transaction_Node *new_node; // Pointer for new node

	new_node = create_trans_node(oper);

	if(new_node == NULL)
		return FAILURE; // Insertion Failed

	// If list is empty
	if(my_list->trans_count == 0){
	// Both head and tail poit to same node
		my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
		new_node->ptr = my_list->head;
		my_list->head = new_node; // Insert at beginning
	}

	my_list->trans_count++;

	// Increment trascation type count
	if(oper == insert)
		my_list->insert_count++;
	else
		my_list->delete_count++;

	return SUCCESS;
}

//--------------------------------------------------
// Function to print transaction log
// @param  : Student_List pointer
// @return : void
//--------------------------------------------------
void print_transaction_log(Student_List *my_list){
	Transaction_Node *temp; // Transaction node pointer
    char *op_name[] = {"insert", "delete"};
	
	if(my_list->trans_list->head == NULL)
		printf("No Transactions Done!");

	temp = my_list->trans_list->head;

	// Print Recent transaction
	printf("Total Transactions: %d\n", my_list->trans_list->trans_count);
	printf("Total Insertions : %d\n", my_list->trans_list->insert_count);
	printf("Total Deletions  : %d\n", my_list->trans_list->delete_count);
	
	for(temp = my_list->trans_list->head; temp != NULL; temp = temp->ptr){
        printf("\nType \t\t: %s\n", op_name[temp->trans_data.type_of_operation]);
	    printf("Date \t\t: %s\n", temp->trans_data.transaction_date);
        printf("Time \t\t: %s\n", temp->trans_data.transaction_time);
	}
	
}

//--------------------------------------------------
// Function to Deallocate Transaction list
// @param  : Transaction_List pointer
// @return : Transaction_List pointer (NULL)
//--------------------------------------------------
Transaction_List *deallocate_trans_list(Transaction_List *trans_list){

	Transaction_Node *temp;

	// Deallocate each node from beginning
	while(trans_list->head != NULL){
		temp = trans_list->head;
		trans_list->head = trans_list->head->ptr;
		free(temp);
	}

	free(trans_list);

	return NULL;
}

//----------------------------------------------------------------------

// ----------------- Student List Handling Functions -------------------

//--------------------------------------------------
// Function to create and initialize student list
// @return : List pointer
//--------------------------------------------------
Student_List *initialize_list(){

    Student_List *my_list;

	// Allocate memory for student list
	my_list = (Student_List *)malloc(sizeof(Student_List));

	if(my_list == NULL)
		return NULL; // Memory allocation failed

    my_list->head = NULL;
	my_list->tail = NULL;
	my_list->count = 0;

	// Call Initialize transaction list function
	my_list->trans_list = initialize_trans_list();

    return my_list; // Return student list pointer
}

//--------------------------------------------------
// Function to create student node
// @param  : Student student_details
// @return : Student_Node pointer
//--------------------------------------------------
Student_Node *create_student_node(Student student_details){

	Student_Node *new_node;

	// Allocate memory for node
	new_node = (Student_Node *)malloc(sizeof(Student_Node));

	if(new_node == NULL)
		return NULL; // Memory allocation failed

	new_node->student_data = student_details;
	new_node->ptr  = NULL;

	return new_node;
}

//--------------------------------------------------
// Function to insert student details at end
// @param  : Student_List pointer
// @param  : Student student_detail
// @return : int status
//--------------------------------------------------
int insert_student(Student_List *my_list, Student student_details){

	Student_Node *new_node; // Pointer for new node

	new_node = create_student_node(student_details);

	if(new_node == NULL)
		return FAILURE; // Insertion Failed

	// If list is empty
	if(my_list->count == 0){
	// Both head and tail poit to same node
		my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
		my_list->tail->ptr = new_node;
		my_list->tail = new_node; // Insert at tail
	}

	my_list->count++;

	// Insert transaction
    assert(insert_transaction(my_list->trans_list, insert));

	return SUCCESS;
}

//--------------------------------------------------
// Function to search given student by roll no
// @param  : Student_List pointer
// @param  : int roll_no
// @return : int status
//--------------------------------------------------
int search_student(Student_List *my_list, int roll_no){
	Student_Node *temp;

	if(my_list == NULL)
		return FAILURE;

	for(temp = my_list->head; temp != NULL; temp = temp->ptr){
		if(temp->student_data.roll_no == roll_no)
			return SUCCESS;
	}

	return FAILURE;
}

//--------------------------------------------------
// Function to delete student details by roll no
// @param  : Student_List pointer
// @param  : int roll_no
// @return : int status
//--------------------------------------------------
int delete_student(Student_List *my_list, int roll_no){

	Student_Node *curr_node;
	Student_Node *prev_node;

	if(my_list == NULL)
		return FAILURE;

	for(prev_node = NULL, curr_node = my_list->head;
	    curr_node != NULL;
		prev_node = curr_node, curr_node = curr_node->ptr){
        
		// When given roll no is matched
		if(curr_node->student_data.roll_no == roll_no){
			// If only 1 student is present
			if(my_list->count == 1){
				// Delete student and make head as well as tail as NULL
				my_list->head = NULL;
				my_list->tail = NULL;
			}
			// If data is present at beginning
			else if(curr_node == my_list->head){
				// Delete student at beginning and update head
				my_list->head = my_list->head->ptr;
			}
			// If data is present at end
			else if(curr_node == my_list->tail){
				prev_node->ptr = NULL;
				my_list->tail = prev_node;
			}
			// If data is present in between
			else{
				prev_node->ptr = curr_node->ptr;
			}

			free(curr_node);
			my_list->count --;

			// Insert transaction
            assert(insert_transaction(my_list->trans_list, delete));

			return SUCCESS;
		}

	}

	return FAILURE;
}

//--------------------------------------------------
// Function to Print student list
// @param  : Student_List pointer
// @return : void
//--------------------------------------------------
void print_student_list(Student_List *my_list){
	Student_Node *temp;

	if(my_list == NULL)
		printf("Empty List!");

	for(temp = my_list->head; temp != NULL; temp = temp->ptr){
		printf("Student Name : %s\n", temp->student_data.name);
		printf("Course : %s\n", temp->student_data.course);
		printf("Roll No : %d\n", temp->student_data.roll_no);
		printf("CGPA : %f\n", temp->student_data.cgpa);
		printf("\n");
	}

}

//--------------------------------------------------
// Function to Deallocate student list
// @param  : Student_List pointer
// @return : Student_List pointer
//--------------------------------------------------
Student_List *deallocate_list(Student_List *my_list){

	Student_Node *temp;

	// Call deallocate transaction list function
	my_list->trans_list = deallocate_trans_list(my_list->trans_list);
	assert(my_list->trans_list == NULL);

	// Deallocate each node from beginning
	while(my_list->head != NULL){
		temp = my_list->head;
		my_list->head = my_list->head->ptr;
		free(temp);
	}

	free(my_list);

	return NULL;
}

//----------------------------------------------------------------------
