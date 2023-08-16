// Example for structure
/*
#define NAME_SIZE   10
#define COURSE_SIZE 20

struct _student_details_{
    int reg_no;
    char student_name[NAME_SIZE];
    char course_name[COURSE_SIZE];
    float cgpa;
};

typedef struct _student_details_ Student;

// Function to insert student data
Student insert_student_data(int reg_no, char stud_name[], char course_name[], float cgpa);

// Function to display student information
void display_student_info(Student stud);

// Function to insert student data into student information array
void insert_student_details_in_array(Student stud[], int size);

// Function to display student information array
void display_student_info_array(Student stud[], int);
*/

/*
// Example for structure within structure
#define STRING_SIZE 20
#define MAX_SIZE 5

struct _test_{
    float mark1, mark2, mark3;
};
typedef struct _test_ Test;

struct _student_{
    int reg_no;
    char name[STRING_SIZE];
    char course[STRING_SIZE];
    Test first_internals, second_internals;
    float cgpa;
};
typedef struct _student_ Student;

// Function to insert student data into student information array
int insert_data(Student stud[], int size);

// Function to search for given register number within student information array
int search_reg_no(Student stud[], int size, int reg_no);

// Function to search for given name within student information array
int search_by_name(Student stud[], int size, char name[]);

// Function to display student information array
void display(Student [], int size);
*/


// Example application for structure
#define MAX_SIZE 3
#define COLOR_SIZE 10

struct _point_{
    int x, y;
};
typedef struct _point_ Point;

struct _pixel_{
    int r, g, b;
    float opacity; // takes value between 0 to 1
    char pixel_color[COLOR_SIZE]; // color name;
    Point pnt;
};
typedef struct _pixel_ Pixel;

// Insert data into pixel array
int insert_data(Pixel pixel[], int size);

// Search for given R value within pixel array
int search(Pixel pixel[], int size, int r_value);

// Search for given color within pixel array
int search_pix_name(Pixel pixel[], int size, char pix_name[]);

// Display the pixel array
void display(Pixel pixel[], int size);

// Compare two pixels
int compare_pixel(Pixel pixel_1, Pixel pixel_2);
