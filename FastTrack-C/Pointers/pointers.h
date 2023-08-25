// Create a dynamic array and insert elements into it, return the array address
int * insert_in_dynamic_array(int size);

// Create a dynamic 2D array and insert elements into it, return the array address
int *insert_in_two_dimesion_array(int row, int col);

// Function to display dynamic 2D array
void display(int *arr, int row, int col);

// create a dynamic 2D array, return double pointer storing array address
// Create 2D array using double pointer
int ** create_matrix(int row, int col);

// Insert data into dynamic 2D array using double pointers
int ** insert_double_pointer(int row, int col);

// Function to display dynamic 2D array using double pointers
void display_double_ptr(int **arr, int row, int col);

/*
// Dynamic Structure
#define NAME_SIZE 15

struct _employee_{
    int emp_id;
    char emp_name[NAME_SIZE];
    float emp_salary;
};
typedef struct _employee_ Employee;

struct _employee_array_{
    Employee *arr;
    int c_size, t_size;
    int op_status;
};
typedef struct _employee_array_ Earray;

// Function to initialize dynamic array of structure
Earray * initialize_employee(int size);

// Function to insert employee data into employee array
int insert_employee_data(Earray *my_arr, Employee data);

// Function to search employee by name
int search_by_name(Earray *my_arr, char *element);
*/


// Dynamic Array List Merge
#define FAILURE 0
#define SUCCESS 1

struct _array_{
    int *arr;
    int c_size, t_size;
};
typedef struct _array_ Array;

// Initialize structure array
Array * initialize_array(int size);

// Insert data into array within structure array
int insert_data(Array *my_arr, int data);

// Search element within array
int search(Array *my_arr, int element);

// Deallocate memory allocated for array
Array *deallocate(Array *my_arr);

// Merge arrays
Array *merge_array(Array *arr_a, Array *arr_b);

// Split array
Array *split_array(Array *my_arr, int split_index);