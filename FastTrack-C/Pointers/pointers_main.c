#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "pointers.h"

int main(){
/*
// Create a dynamic array and insert elements into it, return the array address
    int *test_arr;
    test_arr = insert_in_dynamic_array(10);
    assert(*(test_arr) == 1);
    assert(*(test_arr+4) == 5);
    assert(*(test_arr+9) == 10);
*/

/*
// Create a dynamic 2D array and insert elements into it, return the array address
    int *test_arr;
    test_arr = insert_in_two_dimesion_array(4,5);
    assert(*(test_arr) == 0);   // First row first column
    assert(*(test_arr+4) == 4); // First row last column
    assert(*(test_arr+5) == 1); // second row first column
    display(test_arr, 4, 5);
*/

/*
// create a dynamic 2D array, return double pointer storing array address
    int **test_arr;
    test_arr = insert_double_pointer(4,5);
    display_double_ptr(test_arr, 4, 5);
    printf("\n\nDouble Pointer, Base Address of Row Pointer List:\t%p", test_arr);
    printf("\nList of Row Pointers:\t");
    for(int i=0; i<4; i++){
        printf("%p\t", *test_arr+i);
    }
    printf("\n1st Row:\t");
    for(int i=0; i<5; i++){
        printf("%d\t", (*(*test_arr+0)+i));
    }
    printf("\n2nd Row:\t");
    for(int i=0; i<5; i++){
        printf("%d\t", (*(*test_arr+1)+i));
    }
    printf("\n3rd Row:\t");
    for(int i=0; i<5; i++){
        printf("%d\t", (*(*test_arr+2)+i));
    }
    printf("\n4th Row:\t");
    for(int i=0; i<5; i++){
        printf("%d\t", (*(*test_arr+3)+i));
    }
*/

/*
// Dynamic Structure
    Earray *test;
    Employee data = {1001, "Joel", 30000};
	
    test = initialize_employee(5);
    assert(insert_employee_data(test, data));
    assert(test->arr->emp_id == 1001);

    data.emp_id = 1002;
    data.emp_salary = 25000;
    strcpy(data.emp_name, "Siya");
	
    assert(insert_employee_data(test, data));
    assert((test->arr + 1)->emp_id == 1002);
	assert(search_by_name(test, "Siya") == 1);
    assert(search_by_name(test, "Siyan") == 0);
*/

// Dynamic Array List Merge
    Array *arr_one, *arr_two;
	
	arr_one = initialize_array(10);
    arr_two = initialize_array(15);
	
	assert(arr_one != NULL);
	assert(arr_one->c_size == 0 && arr_one->t_size == 10);
    assert(arr_one->arr != NULL);
	
	assert(arr_two != NULL);
	assert(arr_two->c_size == 0 && arr_two->t_size == 15);
    assert(arr_two->arr != NULL);
	
	// Insert data to array one
	for(int i=0; i<10; i++){
		assert(insert_data(arr_one, 10*i) == SUCCESS);
	}
	assert(arr_one->c_size == 10);
	assert(search(arr_one, 60) == SUCCESS);
	assert(search(arr_one, 160) == FAILURE);
	
	// Insert data to array two
	for(int i=0; i<12; i++){
		assert(insert_data(arr_two, 10+i) == SUCCESS);
	}
	assert(arr_two->c_size == 12);
	assert(search(arr_two, 16) == SUCCESS);
	
	// Testing merge array
	arr_two = merge_array(arr_one, arr_two);
	assert(arr_one->c_size == 22);
    assert(arr_one->t_size == 22);
    assert(arr_two == NULL);
	
	// Testing split array
    arr_two = split_array(arr_one, 8);
	assert(arr_one->c_size == 8);
	assert(arr_two->c_size == 14);
	assert(arr_two->t_size == 14);

	
    return 0;
}