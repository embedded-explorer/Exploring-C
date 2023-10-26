/*
//----------------------------------------------------------------------
// Problem 1. 
//----------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "problems.h"

int main(){
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
*/

/*
//----------------------------------------------------------------------
// Problem 2. 
//----------------------------------------------------------------------
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main(){
	List *test_list;
    int i;
    
    // Participant Details
	Participant details[6] = {{"Ramesh S", 223345687895, 0, Beginner},
	                          {"Suresh", 223347898895, 0, Beginner},
	                          {"Ramesh", 222845987635, 0, Intermediate},
	                          {"Suresh", 223347898895, 0, Beginner},
	                          {"Sheela", 123447898895, 0, Expert},
	                          {"Jaya", 589635694568, 0, Intermediate}};
    
    // Test Initialize List
	test_list = initialize_list();
	assert(test_list != NULL);
	assert(test_list->head == NULL && test_list->tail == NULL);
    
    // Test Register for Course Function
	assert(register_for_course(test_list, details[0]) == SUCCESS);
	assert(register_for_course(test_list, details[1]) == SUCCESS);
	assert(register_for_course(test_list, details[2]) == SUCCESS);
	assert(test_list->count == 3);
	assert(register_for_course(test_list, details[3]) == FAILURE); // Duplicate Entry
	assert(test_list->count == 3);
	assert(register_for_course(test_list, details[4]) == SUCCESS);
	assert(register_for_course(test_list, details[5]) == SUCCESS);
	assert(test_list->count == 5);
    
    // Test get number of participants
	get_no_of_participants(test_list);
    
    // Test print participant list
	print_participant_list(test_list);
    
    // Test deallocate memory function
	test_list = deallocate_memory(test_list);
	assert(test_list == NULL);

	return 0;
}
*/

/*
//----------------------------------------------------------------------
// Problem 3. 
//----------------------------------------------------------------------
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "problems.h"

int main(){
	List *test_list;

	Details booking_details[9] = {{"Ramesh", 7896586952, "18Oct2023", full_day},
                                  {"Suresh", 8356985623, "18Oct2023", morning},
                                  {"Dinesh", 8956456231, "18Oct2023", evening},
                                  {"Kunal", 9856239865, "19Oct2023", morning},
                                  {"Akhil", 7563986523, "19Oct2023", full_day},
                                  {"Dhanush", 8963562389, "19Oct2023", evening},
                                  {"Vikram", 8963569870, "20Oct2023", evening},
                                  {"Vijay", 9635698963, "20Oct2023", full_day},
                                  {"Varun", 8963569635, "20Oct2023", morning}};
    
    // Initialize List
	test_list = initialize_list();
	assert(test_list != NULL);
	assert(test_list->head == NULL && test_list->tail == NULL);
	assert(test_list->count == 0);

	// Test Booking Function
	// 1. Booked for full day
	assert(book_auditorium(test_list, booking_details[0]) == SUCCESS);
	assert(book_auditorium(test_list, booking_details[1]) == FAILURE);
	assert(book_auditorium(test_list, booking_details[2]) == FAILURE);
	// 2. Booked for morning
	assert(book_auditorium(test_list, booking_details[3]) == SUCCESS);
	assert(book_auditorium(test_list, booking_details[4]) == FAILURE);
	assert(book_auditorium(test_list, booking_details[5]) == SUCCESS);
	// 3. Booked for evening
	assert(book_auditorium(test_list, booking_details[6]) == SUCCESS);
	assert(book_auditorium(test_list, booking_details[7]) == FAILURE);
	assert(book_auditorium(test_list, booking_details[8]) == SUCCESS);

	// Display Booking Status
	show_details(test_list, booking_details[0].name);
	show_details(test_list, booking_details[1].name);
	show_details(test_list, booking_details[2].name);
	show_details(test_list, booking_details[3].name);
	show_details(test_list, booking_details[4].name);
	show_details(test_list, booking_details[5].name);
	show_details(test_list, booking_details[6].name);
	show_details(test_list, booking_details[7].name);
	show_details(test_list, booking_details[8].name);
    
    // Deallocate
    test_list = deallocate_list(test_list);
    assert(test_list == NULL);

	return 0;
}
*/

//----------------------------------------------------------------------
// Problem 4.
//----------------------------------------------------------------------

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "problems.h"

int main(){
    
    List *my_list;

    // Test Initialize Function
    my_list = initialize_list(50);
    assert(my_list != NULL);

    // Test insert function
    assert(insert_object(my_list, 30, 15) == SUCCESS);
    assert(insert_object(my_list, 20, 13) == SUCCESS);
    assert(insert_object(my_list, 25, 18) == SUCCESS);
    assert(insert_object(my_list, 15, 9) == SUCCESS);

    print_list(my_list);
	printf("\n");
	
	// Test selection function
	printf("Profit = %f\n", select_objects(my_list));
	
	printf("\n");
	print_list(my_list);

	return 0;
}