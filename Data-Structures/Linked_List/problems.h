
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