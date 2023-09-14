
//----------------------------------------------------------------------
// Dynamic Array List Example
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

// Structure definition for array list
struct _array_{
    int *array; // Array pointer
    int c_size, t_size;
};
typedef struct _array_ Array;

// Function to initialize array
Array *initialise_array(int size);

// Function to insert data into array
int insert_data(Array *my_arr, int data);

// Function to search given element within array using linear search
int search(Array *my_arr, int element);

// Function to deallocate array list
Array *deallocate(Array *my_arr);