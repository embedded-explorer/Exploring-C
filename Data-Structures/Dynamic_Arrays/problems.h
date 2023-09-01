
//----------------------------------------------------------------------
// Problem 1.
// X institute is offering a course in M.S. in EmbeddedSystems. Course 
// has total of 15 seats. Of the  15 seats,  10  seats  are  allotted  
// based  on the merit  list (rank  wise),  3  seats  are under 
// management quota and 2 seats under NRI quota (Theses are allotted by 
// first come first serve basis). Students will apply for this course 
// under the different quota. X institute will generate the list of 
// students who have been admitted to the course. Define the data 
// structure required for the above problem (5Marks). Student 
// registration (5marks). Generating the admitted student list (5marks). 
// Coding convention, code organisation, comments (5Marks)
//----------------------------------------------------------------------

#define NAME_SIZE 20 // Maximum characters allowed for name

// Maximum allocated seats under each category
#define MERIT_SEATS 10
#define MGMT_SEATS 3
#define NRI_SEATS 2

// Status of function calls
#define SUCCESS 1
#define FAILURE 0

// Datatype for category of seats available
typedef enum {merit, management, nri} Category;

// Structure definition for course application details
struct _application_{
    int rank; // Rank
    Category category; // Category
    char name[NAME_SIZE]; // Applicants Name
    int is_admitted;
};
typedef struct _application_ Application;

// Structure for list of applications
struct _app_list_{
    Application *app_ptr; // Application list pointer
    int c_size, t_size;
};
typedef struct _app_list_ App_List;

// Function to initialize array
App_List *initialise_array(int size);

// Function to apply for course
int apply_for_course(App_List *my_arr, Application applicant);

// Function to allocate seats
void allocate_seats(App_List *my_arr);

// Function to display application list
void display_app_list(App_List *my_arr);

// Function to deallocate memory of application list
App_List *deallocate(App_List *my_arr);