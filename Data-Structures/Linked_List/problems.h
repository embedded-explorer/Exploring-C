/*
//----------------------------------------------------------------------
// Problem 1. 
// Write program to store student details in a data structure. Carry out 
// transactions like insert, delete and search an student.For every 
// transaction conducted, store the log details like type_of_operation,
// transaction_time and transactions_date in a separate data structure.
// Count the number of insert and delete transactions took place.
// Deallocate all the memory allocated dynamically.
// (Solve the above problem using linked list)
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

// ------------------------ Transaction Details ------------------------
#define DATE_SIZE 11
#define TIME_SIZE 9
// Datatype for operations
typedef enum {insert, delete} Operation;

// Structure definition to store transaction
typedef struct _transaction_ Transaction;
struct _transaction_{
	Operation type_of_operation;
	char transaction_time[TIME_SIZE];
	char transaction_date[DATE_SIZE];
};

// Structure definition of transaction node
typedef struct _transaction_node_ Transaction_Node;
struct _transaction_node_{
	Transaction trans_data;
	Transaction_Node *ptr;
};

// Structure definition of transaction list
typedef struct _transaction_list_ Transaction_List;
struct _transaction_list_{
	int trans_count; // Number of transactions
	int insert_count; // Number of insertions
	int delete_count; // Number of deletions
	Transaction_Node *head;
	Transaction_Node *tail;
};
//----------------------------------------------------------------------

// -------------------------- Student Details --------------------------
#define NAME_SIZE 20
#define COURSE_SIZE 20

// Structure definition to store student details
typedef struct _student_ Student;
struct _student_{
	char name [NAME_SIZE];
	char course [COURSE_SIZE]; 
	int roll_no;
	float cgpa;
};

// Structure definition of student node
typedef struct _student_node_ Student_Node;
struct _student_node_{
    Student student_data;  // Data
    Student_Node *ptr; // Next node pointer
};

// Structure definition of list
typedef struct _student_list_ Student_List;
struct _student_list_{
	int count;  // Count of elements
    Student_Node *head; // Head
	Student_Node *tail; // Tail
	Transaction_List *trans_list; // Transaction list
};
//----------------------------------------------------------------------

// Function to create and initialize student list
Student_List *initialize_list();

// Function to insert student details at end
int insert_student(Student_List *my_list, Student student_detail);

// Function to search given student by roll no
int search_student(Student_List *my_list, int roll_no);

// Function to delete student details by roll no
int delete_student(Student_List *my_list, int roll_no);

// Function to Print student list
void print_student_list(Student_List *my_list);

// Function to print transaction log
void print_transaction_log(Student_List *my_list);

// Function to deallocate list
Student_List *deallocate_list(Student_List *my_list);
*/

/*
// --------------------------------------------------------------
// Problem 2.
// The X Institute offers a online course on MEMS Technology
// Course is offered in Beginner, Intermediate and Expert Levels
// The participant can register in either of one level of course
// Ensure that all the participants are unique. Count number of 
// registration in beginner, intermediate and expert levels.
// Deallocate all the memory before exiting the program
// --------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

#define NAME_SIZE 20

// Datatype for course level
typedef enum{Beginner, Intermediate, Expert} Level;

// Structure definition for storing participant details
typedef struct _participant_ Participant;
struct _participant_{
    char name[NAME_SIZE]; // Participant Name
    long int aadhaar_num; // Aadhaar Number
	int reg_no;           // Registration Number
	Level level;          // Level of Course
};

// Structure definition of Node
typedef struct _node_ Node;
struct _node_{
	Participant participant;
	Node *ptr;
};

// Structure definition of List
typedef struct _list_ List;
struct _list_{
	int count;
    Node *head;
    Node *tail;
};

// Function to Initialize the List
List *initialize_list();

// Function to rgister for course
int register_for_course(List *my_list, Participant participant);

// Function to print number of participants in each level
void get_no_of_participants(List *my_list);

// Function to print entire list
void print_participant_list(List *my_list);

// Function to deallocate memory
List *deallocate_memory(List *list);
*/

/*
//----------------------------------------------------------------------
// Problem 3.
// Auditorium X Allows to book the place online, the customer can book,
// the place for he whole day or till noon, or for the evening, for the
// It charges 70,000, Till noon 50,000 and for evening 30,000, ensure
// that no two customers can book the same slot on given date.
//----------------------------------------------------------------------
#define SUCCESS 1
#define FAILURE 0

#define NAME_SIZE 20
#define DATE_SIZE 10

// Datatype for slot
typedef enum {full_day, morning, evening} Slot;

// Datatype for slot price
typedef enum {full_day_price = 80000, morning_price = 50000, evening_price = 30000} Price;

// Structure definition of details
typedef struct _details_ Details;
struct _details_{
    char name[NAME_SIZE];
    long int phone_no;
    char date[DATE_SIZE];
    Slot slot;
    Price price;
};

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    Details details;
    Node *ptr;
};

// Structure definition of List
typedef struct _list_ List;
struct _list_{
    int count;
    Node *head;
    Node *tail;
};

// Function to initialize list
List *initialize_list();

// Function to book auditorium
int book_auditorium(List *my_list, Details details);

// Function to show details
void show_details(List *my_list, char *name);

// Function to deallocate list
List *deallocate_list(List *my_list);
*/

//----------------------------------------------------------------------
// Problem 4.
// Knapsack Problem
//----------------------------------------------------------------------
#define SUCCESS 1
#define FAILURE 0

// Structure definition of object
typedef struct _object_ Object;
struct _object_{
    float profit;
    float weight;
    float ratio;
    float fraction;
};

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    Object object;
    Node *ptr;
};

// Structure definition of List
typedef struct _list_ List;
struct _list_{
    float t_weight; // Capacity of bag
	float a_weight; // Available space
    Node *ptr;
};

// Function to initialize list
List *initialize_list(float capacity);

// Function to insert new object to list
int insert_object(List *my_list, float profit, float weight);

// Function to Select_objects, returns profit
float select_objects(List *my_list);

// Function to Print List
void print_list(List *my_list);
