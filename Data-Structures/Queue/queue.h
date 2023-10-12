//----------------------------------------------------------------------
// Queue - Array Implementation (Dynamic Array)
//----------------------------------------------------------------------
#define SUCCESS 1
#define FAILURE 0

// Structure definition of Queue
typedef struct _queue_ Queue;
struct _queue_{
    int count;  // Occupancy Count
	int size;   // Queue Size
	int head;   // Removing End
	int tail;   // Adding End
    int *data;  // Array
};

// Queue initialization function
Queue *queue_initialize(int size);

// Insert Function, returns status
int enqueue(Queue *my_queue, int data);

// Remove Function, returns data
int dequeue(Queue *my_queue);

// Deallocate Function, returns NULL pointer
Queue *queue_deallocate(Queue *my_queue);
