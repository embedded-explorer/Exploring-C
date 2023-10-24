/*
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
*/

/*
//----------------------------------------------------------------------
// Problem 2.
//----------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//--------------------------------------------------------------
// Function to Initialize the List
// @param : 
// @return: List Pointer
//--------------------------------------------------------------
List *initialize_list(){

	List *my_list;
    
    // Allocate memory for list
	my_list = (List *)malloc(sizeof(List));
    
    // Memory allocation failed
	if(my_list == NULL)
		return NULL;

	my_list->count = 0;
	my_list->head = NULL;
	my_list->tail = NULL;

	return my_list;
}

//--------------------------------------------------------------
// Function to Create New Node
// @param : Participant Details
// @return: Node Pointer
//--------------------------------------------------------------
Node *create_node(Participant details){
	Node *new_node;
	static int reg_no; // Registration Number
    
    // Allocate Memory for Node
	new_node = (Node *)malloc(sizeof(Node));
  
    if(new_node == NULL)
		return NULL;
    
	new_node->participant = details;
	new_node->participant.reg_no = ++reg_no; // Insert Registration Number
	new_node->ptr = NULL;

	return new_node;
}

//--------------------------------------------------------------
// Function to search participant by Aaadhaar Number
// @param : List Pointer
// @param : long int Aadhaar Number
// @return: Node Pointer
//--------------------------------------------------------------
int serch_for_participant(List *my_list, long int aadhaar_num){
    Node *temp;

    temp = my_list->head;
    while(temp != NULL){
    	if(temp->participant.aadhaar_num == aadhaar_num)
    		return SUCCESS;
    	temp = temp->ptr;
    }

    return FAILURE;

}

//--------------------------------------------------------------
// Function to rgister for course
// @param : List Pointer
// @param : Participant participant details
// @return: int Status
//--------------------------------------------------------------
int register_for_course(List *my_list, Participant participant){
    Node *new_node;
    
    // Check if participant is already registered
    if(serch_for_participant(my_list, participant.aadhaar_num)){
	  return FAILURE;
    }
    
    // Create Node for participant
    new_node = create_node(participant);
    
    // If Participant creation fails
    if(new_node == NULL)
    	return FAILURE;
    
    // Insert at beginning
    if(my_list->count == 0){
    // When list is empty update both head and tail
    	my_list->head = new_node;
    	my_list->tail = new_node;
    }
    else{
    // Add new participant node and update head
        new_node->ptr = my_list->head;
        my_list->head = new_node;
    }
    
    // Increment Count
    my_list->count ++;

    return SUCCESS;
}

//--------------------------------------------------------------
// Function to print number of participants in each level
// @param : List Pointer
// @return:
//--------------------------------------------------------------
void get_no_of_participants(List *my_list){
	Node *temp;
	int beg_count, int_count, exp_count;

	temp = my_list->head;
	while(temp != NULL){
        if(temp->participant.level == Beginner){
        	beg_count++;
        }
        else if(temp->participant.level == Intermediate){
            int_count++;
        }
        else{
            exp_count++;
        }
        temp = temp->ptr;
	}
    
    printf("Number of Participants Registered for Course\n");
	printf("Beginner    : %d\n", beg_count);
	printf("Intermediate: %d\n", int_count);
	printf("Expert      : %d\n", exp_count);
	printf("\n");
}

//--------------------------------------------------------------
// Function to print entire list
// @param : List Pointer
// @return:
//--------------------------------------------------------------
void print_participant_list(List *my_list){
    Node *temp;
    char *level_name[] = {"Beginner", "Intermediate", "Expert"};

    temp = my_list->head;
    while(temp != NULL){
    	printf("Name               : %s\n", temp->participant.name);
    	printf("Aadhaar Number     : %ld\n", temp->participant.aadhaar_num);
    	printf("Registration Number: %d\n", temp->participant.reg_no);
    	printf("Level              : %s\n", level_name[temp->participant.level]);
    	printf("\n");
    	temp = temp->ptr;
    }
}

//--------------------------------------------------------------
// Function to deallocate memory
// @param : List Pointer
// @return: List Pointer NULL
//--------------------------------------------------------------
List *deallocate_memory(List *my_list){
	Node *temp;
    
    // Free each node
	while(my_list->head != NULL){
		temp = my_list->head;
		my_list->head = temp->ptr;
		free(temp);
	}
    
    // Free list
	free(my_list);

	return NULL;
}
*/

//----------------------------------------------------------------------
// Problem 3.
//----------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "problems.h"

// Function to initialize list
List *initialize_list(){
	List *my_list;

	my_list = (List *)malloc(sizeof(List));

	if(my_list == NULL)
		return NULL; // Memory Allocation Failed

	my_list->head = NULL;
	my_list->tail = NULL;
	my_list->count = 0;

	return my_list;
}

// Function to create new node
Node *create_node(Details details){
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));

    if(new_node == NULL)
    	return NULL;

    new_node->details = details;

    // Add price
    if(details.slot == full_day){
        new_node->details.price = full_day_price;
    }
    else if(details.slot == morning){
    	new_node->details.price = morning_price;
    }
    else{
    	new_node->details.price = evening_price;
    }

    new_node->ptr = NULL;

    return new_node;
}

// Function to check availability of slot
int check_avilability(List *my_list, char *date, Slot slot){
	Node *temp;

	for(temp = my_list->head; temp != NULL; temp = temp->ptr){
		if(!strcmp(temp->details.date, date)){
		// When requested date is already booked
			if(temp->details.slot == full_day){
			// When slot is booked already for whole day
				return FAILURE;
			}
			else if(temp->details.slot == morning){
			// When slot is booked already for morning
				if(slot == full_day || slot == morning){
					return FAILURE;
				}		
			}
			else{
            // When slot is booked already for evening
				if(slot == full_day || slot == evening){
                    return FAILURE;
				}
			}
		}
	}

	return SUCCESS;
}

// Function to book auditorium
int book_auditorium(List *my_list, Details details){
	Node *new_node;
    
    // Check Slot avilability
    if(!check_avilability(my_list, details.date, details.slot))
    	return FAILURE;

    // Book slot
	new_node = create_node(details);

	if(new_node == NULL)
		return FAILURE;

	if(my_list->count == 0){
		my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
		new_node->ptr = my_list->head;
		my_list->head = new_node;
	}

	my_list->count ++;

	return SUCCESS;
}

// Function to show details
void show_details(List *my_list, char *name){
	Node *temp;
	char *slot_name[] = {"Full Day", "Morning", "Evening"};

	for(temp = my_list->head; temp != NULL; temp = temp->ptr){
		if(!strcmp(temp->details.name, name)){
			printf("\nSlot Booked Successfully\n");
			printf("Name : %s\n", temp->details.name);
			printf("Name : %ld\n", temp->details.phone_no);
			printf("Name : %s\n", temp->details.date);
			printf("Name : %s\n", slot_name[temp->details.slot]);
			printf("Name : %d\n", temp->details.price);
			return;
		}
	}

	printf("\nSlot is not booked\n");
}

// Function to deallocate list
List *deallocate_list(List *my_list){
	Node *temp;

	while(my_list->head->ptr != NULL){
        temp = my_list->head;
        my_list->head = temp->ptr;
        free(temp);
	}

	free(my_list);

	return NULL;
}
