#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "problems.h"

int main(){


//----------------------------------------------------------------------
// Problem 1. 
//----------------------------------------------------------------------
    Student_List *test_list;
	Student student_1, student_2, student_3, student_4;
    
	// Test initialization function
    test_list = initialize_list();
	assert(test_list != NULL);
	assert(test_list->count == 0);
    assert(test_list->head == NULL && test_list->tail == NULL);
	
	// Check transaction list initilaization
	assert(test_list->trans_list != NULL);
	assert(test_list->trans_list->trans_count == 0);
	assert(test_list->trans_list->insert_count == 0);
	assert(test_list->trans_list->delete_count == 0);
	assert(test_list->trans_list->head == NULL);
	assert(test_list->trans_list->tail == NULL);
    
	// Cookup student details
    strcpy(student_1.name, "Dinesh");
	strcpy(student_1.course, "VLSI Design");
	student_1.roll_no = 8001;
	student_1.cgpa = 8.65;
	
	strcpy(student_2.name, "Suresh");
	strcpy(student_2.course, "Microelectronics");
	student_2.roll_no = 9001;
	student_2.cgpa = 8.34;
	
	strcpy(student_3.name, "Ramesh");
	strcpy(student_3.course, "VLSI Design");
	student_3.roll_no = 8002;
	student_3.cgpa = 7.87;
	
	strcpy(student_4.name, "Rajesh");
	strcpy(student_4.course, "VLSI Design");
	student_4.roll_no = 8003;
	student_4.cgpa = 9.23;
	
	// Test insert student details function
	assert(insert_student(test_list, student_1) == SUCCESS);
	// Check transaction list
	assert(test_list->trans_list->trans_count == 1);
	assert(test_list->trans_list->insert_count == 1);
	assert(test_list->trans_list->delete_count == 0);
	
	assert(insert_student(test_list, student_2) == SUCCESS);
	assert(insert_student(test_list, student_3) == SUCCESS);
	assert(insert_student(test_list, student_4) == SUCCESS);
	assert(test_list->count == 4);
	// Check transaction list
	assert(test_list->trans_list->trans_count == 4);
	assert(test_list->trans_list->insert_count == 4);
	assert(test_list->trans_list->delete_count == 0);
	
	// Test search student function
	assert(search_student(test_list, 8001) == SUCCESS);
	assert(search_student(test_list, 9001) == SUCCESS);
	assert(search_student(test_list, 8002) == SUCCESS);
	assert(search_student(test_list, 8003) == SUCCESS);
	assert(search_student(test_list, 8004) == FAILURE);
	
	// Test delete student details function
	// Test delete at beginning
	assert(delete_student(test_list, 8001) == SUCCESS);
	assert(test_list->count == 3);
	// Check transaction list
	assert(test_list->trans_list->trans_count == 5);
	assert(test_list->trans_list->insert_count == 4);
	assert(test_list->trans_list->delete_count == 1);
	
	// Test delete in between
	assert(delete_student(test_list, 8002) == SUCCESS);
	assert(test_list->count == 2);
	// Test delete at end
	assert(delete_student(test_list, 8003) == SUCCESS);
	assert(test_list->count == 1);
	assert(test_list->tail->ptr == NULL);
	// Test delete single node
	assert(delete_student(test_list, 9001) == SUCCESS);
	assert(test_list->count == 0);
	assert(test_list->head == NULL && test_list->tail == NULL);
	// Test delete from empty list
	assert(delete_student(test_list, 9001) == FAILURE);
	
	// Check transaction list
	assert(test_list->trans_list->trans_count == 8);
	assert(test_list->trans_list->insert_count == 4);
	assert(test_list->trans_list->delete_count == 4);
	
	// Print transaction log
	print_transaction_log(test_list);
	
	// Test deallocate function
	assert(deallocate_list(test_list) == NULL);
	
    return 0;
}