
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

// Function to initialize array with random data
Array initialise_array(int size);

// Function to display array
void display_array(Array my_arr);

// Function to sort using bubble sort
Array bubble_sort(Array my_arr);

// Function to sort using selection sort
Array selection_sort(Array my_arr);

// Function to sort using insertion sort
Array insertion_sort(Array my_arr);