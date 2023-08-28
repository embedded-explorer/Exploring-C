#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "static_arrays.h"

int main(){

/*
//----------------------------------------------------------------------
// Static Array List Example
//----------------------------------------------------------------------
    Array test_arr, test_max;
    
	// Test initialization function
    test_arr = initialise_array(10);
    assert(test_arr.c_size == 0 && 10 == test_arr.t_size);

    test_max = initialise_array(40);
    assert(test_max.c_size == 0 && test_max.t_size == MAX_SIZE);
    
	// Test insert data function
    test_arr = insert_data(test_arr, 10);
    test_arr = insert_data(test_arr, 90);
    test_arr = insert_data(test_arr, 80);
    test_arr = insert_data(test_arr, 70);
    test_arr = insert_data(test_arr, 30);
    test_arr = insert_data(test_arr, 20);
    test_arr = insert_data(test_arr, 50);
    test_arr = insert_data(test_arr, 60);
    test_arr = insert_data(test_arr, 40);
    test_arr = insert_data(test_arr, 20);
    assert(test_arr.c_size == test_arr.t_size);

    // Insert data to a filled array
    test_arr = insert_data(test_arr, 10);
    assert(test_arr.c_size == test_arr.t_size);
    
	// Test search array function
    assert(search(test_arr, 30) == SUCCESS);
    assert(search(test_arr, 90) == SUCCESS);
    assert(search(test_arr, 20) == SUCCESS);
    assert(search(test_arr, 55) == FAILURE);
*/


//----------------------------------------------------------------------
// Static Array List - Employee details
//----------------------------------------------------------------------
    Emp_Array emp_arr;
	Employee emp_1 = {1001, "Akshay", 70000};
	Employee emp_2 = {1002, "Alia", 50000};
	Employee emp_3 = {1003, "Prabhas", 85000};
	Employee emp_4 = {1004, "Kareena", 47000};
	Employee emp_5 = {1005, "Ranbir", 63000};
	Employee emp_6 = {1006, "Deepika", 27000};
	Employee emp_7 = {1007, "Salman", 56000};
	Employee emp_8 = {1008, "Amir", 48500};
	Employee emp;
	int emp_id;
	
	// Test initialization function
	emp_arr = initialise_employee_list(10);
	assert(emp_arr.c_size == 0 && emp_arr.t_size == 10);
    
	// Test insert data function
	emp_arr = insert_employee_data(emp_arr, emp_1);
	emp_arr = insert_employee_data(emp_arr, emp_2);
	emp_arr = insert_employee_data(emp_arr, emp_3);
	emp_arr = insert_employee_data(emp_arr, emp_4);
	emp_arr = insert_employee_data(emp_arr, emp_5);
	emp_arr = insert_employee_data(emp_arr, emp_6);
	emp_arr = insert_employee_data(emp_arr, emp_7);
	emp_arr = insert_employee_data(emp_arr, emp_8);

	emp.emp_id = 1009;
	strcpy(emp.emp_name, "Ajay");
	emp.emp_salary = 63200;
	emp_arr = insert_employee_data(emp_arr, emp);
	
	emp.emp_id = 1010;
	strcpy(emp.emp_name, "Rajni");
	emp.emp_salary = 73200;
	emp_arr = insert_employee_data(emp_arr, emp);
	
	assert(emp_arr.c_size == 10);
	
	// Test display function
	assert(display_employee_details(emp_arr, 1005) == SUCCESS);
	
	// Test search function
	emp_id = search_employee(emp_arr, "Prabhas");
	assert(emp_id == 1003);
	emp_id = search_employee(emp_arr, "Hrithik");
	assert(emp_id == FAILURE);
	
	// Test average salary function
	printf("\nAverage Salary : %f\n", average_employee_salary(emp_arr));
	
	// Test max salary function
	emp_id = max_salary_employee(emp_arr);
	assert(emp_id == 1003);
	
	// Test min salary function
    emp_id = min_salary_employee(emp_arr);
	assert(emp_id == 1006);

    return 0;
}