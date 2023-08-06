#define INVALID -1
#define ROW 4
#define COL 4

// Function to print integer array
int print_int_array(int arr[], int arr_size);

// Find sum of elements of array
int sum_of_elements_array(int arr[], int arr_size);

// Find product of elements of array
int product_of_elements_array(int arr[], int arr_size);

// Reverse the given array
int reverse_array(int arr[], int arr_size);

// Rotate the array towards right specified amount of times
int rotate_array(int arr[], int arr_size, int shift_amount);

// Find the number of occurrences of given element
int frequency_of_element(int arr[], int arr_size, int element);

// Check if given element is present within array
int search_array(int arr[], int arr_size, int element);

// Return index position of the element if found
int return_index_of_element(int arr[], int arr_size, int element);

// Function to return maximum and minimum elements within array
int max_min_array(int arr[], int arr_size, int *max, int *min);

// Find Intersection of two arrays
int intersection_set(int arr_a[], int size_a, int arr_b[], int size_b, int arr_c[], int size_c);

// Concatenate two arrays
int concantenate_array(int src[], int size_src, int tgt[], int size_tgt);

// Insert data in to 2D Array
void insert_data(int row, int col, int arr[row][col]);

// Print data of 2D Array
void display_data(int row, int col, int arr[row][col]);

// Get Maximum Column sum of 2D Array
int return_max_sum_col(int row, int col, int arr[][col], int *);
