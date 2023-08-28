/*
//----------------------------------------------------------------------
// Static Array List Example
//----------------------------------------------------------------------

#define MAX_SIZE 20 // Maximum size of array
#define SUCCESS 1
#define FAILURE 0

// Structure definition for array list
struct _array_{
    int array[MAX_SIZE]; // Array is fixed
    int c_size, t_size;
};
typedef struct _array_ Array;

// Function to initialize array
Array initialise_array(int size);

// Function to insert data into array
Array insert_data(Array my_arr, int data);

// Function to search given element within array using linear search
int search(Array my_arr, int element);
*/


//----------------------------------------------------------------------
// Static Array List - Employee details
//----------------------------------------------------------------------

#define MAX_SIZE 20 // Maximum size of array
#define NAME_SIZE 20
#define SUCCESS 1
#define FAILURE 0

// Structure definition to store employee details
struct _employee_{
    int emp_id; // Employee ID
    char emp_name[NAME_SIZE]; // Employee Name
    float emp_salary; // Salary
};
typedef struct _employee_ Employee;

// Structure definition for employee array list
struct _emp_array_{
    Employee arr[MAX_SIZE];
    int c_size, t_size;
	float salary_sum; // Total salary
};
typedef struct _emp_array_ Emp_Array;

// Function to initialize array
Emp_Array initialise_employee_list(int size);

// Function to insert data into array
Emp_Array insert_employee_data(Emp_Array my_arr, Employee emp_detail);

// Function to display employee details
int display_employee_details(Emp_Array my_arr, int emp_id);

// Function to search employee by name
int search_employee(Emp_Array my_arr, char *emp_name);

// Function to get average salary of employee array list
float average_employee_salary(Emp_Array my_arr);

// Function to find employee with heighest salary
int max_salary_employee(Emp_Array my_arr);

// Function to find employee with least salary
int min_salary_employee(Emp_Array my_arr);