/*
//----------------------------------------------------------------------
// Static Array List Example
//----------------------------------------------------------------------

#include "static_arrays.h"

//--------------------------------------------------
// Function to initialize array
// @param  : int array size
// @return : Array List
//--------------------------------------------------
Array initialise_array(int size){
    
    Array my_arr; // variable of type array list

    my_arr.c_size = 0; // current size is made zero
    my_arr.t_size = size > 0 && size <= MAX_SIZE ? size : MAX_SIZE;

    return my_arr; // Return array list
}

//--------------------------------------------------
// Function to insert data into array
// @param  : Array List
// @param  : int data
// @return : Array List
//--------------------------------------------------
Array insert_data(Array my_arr, int data){
    
    // Check if array is already full
    if(my_arr.c_size == my_arr.t_size)
        return my_arr; // Return back original array list
    
    my_arr.array[my_arr.c_size] = data; // Insert data
    my_arr.c_size++; // Increment current size

    return my_arr; // Return updated array list
}

//--------------------------------------------------
// Function to search given element within array 
// using linear search
// @param  : Array List
// @param  : int data
// @return : status
//--------------------------------------------------
int search(Array my_arr, int element){
    int i;

    for(i=0; i<my_arr.c_size; i++)
        if(my_arr.array[i] == element)
			return SUCCESS; // Element is found

    return FAILURE; // Element is not found
}
*/


//----------------------------------------------------------------------
// Static Array List - Employee details
//----------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "static_arrays.h"

//--------------------------------------------------
// Function to initialize array
// @param  : int array size
// @return : Array List
//--------------------------------------------------
Emp_Array initialise_employee_list(int size){
    
    Emp_Array my_arr; // variable of type employee array list

    my_arr.c_size = 0; // current size is made zero
    my_arr.t_size = size > 0 && size <= MAX_SIZE ? size : MAX_SIZE;
	my_arr.salary_sum = 0;

    return my_arr; // Return array list
}

//--------------------------------------------------
// Function to insert data into array
// @param  : Array List
// @param  : int data
// @return : Array List
//--------------------------------------------------
Emp_Array insert_employee_data(Emp_Array my_arr, Employee emp_detail){
    
    // Check if array is already full
    if(my_arr.c_size == my_arr.t_size)
        return my_arr; // Return back original array list
    
    my_arr.arr[my_arr.c_size] = emp_detail; // Insert data
    my_arr.c_size++; // Increment current size
	my_arr.salary_sum += emp_detail.emp_salary; // Calculate total salary

    return my_arr; // Return updated array list
}

//--------------------------------------------------
// Function to display employee details
// @param  : Array List
// @param  : int employee id
// @return : status
//--------------------------------------------------
int display_employee_details(Emp_Array my_arr, int emp_id){
	int i;

	for(i=0; i<my_arr.c_size; i++){
		if(my_arr.arr[i].emp_id == emp_id){
			printf("\nEmployee ID   : %d\n", my_arr.arr[i].emp_id);
			printf("Employee Name : %s\n", my_arr.arr[i].emp_name);
			printf("Salary        : %0.2f\n", my_arr.arr[i].emp_salary);
			return SUCCESS; // Details printed successfully
		}
	}
	
	return FAILURE; // Employee ID not found
}

//--------------------------------------------------
// Function to search employee by name
// using linear search
// @param  : Array List
// @param  : int data
// @return : int Employee ID
//--------------------------------------------------
int search_employee(Emp_Array my_arr, char *emp_name){
    int i;

    for(i=0; i<my_arr.c_size; i++){
		// strcmp returns 0 if two strings are equal
        if(!strcmp(my_arr.arr[i].emp_name, emp_name)){
			return my_arr.arr[i].emp_id; // Return Employee ID
		}
	}

    return FAILURE; // Employee not found
}

//--------------------------------------------------
// Function to get average salary of employee list
// @param  : Array List
// @return : float average salary
//--------------------------------------------------
float average_employee_salary(Emp_Array my_arr){
	
	// Return average salary
	return my_arr.salary_sum / my_arr.c_size;
}

//--------------------------------------------------
// Function to find employee with heighest salary
// @param  : Array List
// @return : int employee id
//--------------------------------------------------
int max_salary_employee(Emp_Array my_arr){
	
	float max_salary = my_arr.arr[0].emp_salary;
	int emp_id = 0;
    int i;
    
    for(i=1; i<my_arr.c_size; i++){
        if(max_salary < my_arr.arr[i].emp_salary){
			max_salary = my_arr.arr[i].emp_salary; // Update max salary
			emp_id = my_arr.arr[i].emp_id;
		}
	}

    return emp_id; // Employee ID with max salary
}

//--------------------------------------------------
// Function to find employee with least salary
// @param  : Array List
// @return : int employee id
//--------------------------------------------------
int min_salary_employee(Emp_Array my_arr){
	
    float min_salary = my_arr.arr[0].emp_salary;
	int emp_id = 0;
    int i;
    
    for(i=1; i<my_arr.c_size; i++){
        if(min_salary > my_arr.arr[i].emp_salary){
			min_salary = my_arr.arr[i].emp_salary; // Update max salary
			emp_id = my_arr.arr[i].emp_id;
		}
	}

    return emp_id; // Employee ID with max salary
}