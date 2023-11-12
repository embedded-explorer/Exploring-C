
//----------------------------------------------------------------------
// 1. Adjacency List
//----------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "adjacency_list.h"

//--------------------------------------------------
// Function to create and initialize list
// @return : List pointer
//--------------------------------------------------
List *initialize_list(){

    List *my_list;

	// Allocate memory for list
	my_list = (List *)malloc(sizeof(List));

	if(my_list == NULL)
		return NULL; // Memory allocation failed

    my_list->head = NULL;
	my_list->tail = NULL;
	my_list->count = 0;

    return my_list; // Return array list pointer
}

//--------------------------------------------------
// Function to create node
// @param  : int node_id
// @return : Node pointer
//--------------------------------------------------
Node *create_node(int node_id){

	Node *new_node; // Pointer for new node

	// Allocate memory for node
	new_node = (Node *)malloc(sizeof(Node));

	if(new_node == NULL)
		return NULL; // Memory allocation failed

	new_node->node_id  = node_id;
	new_node->node_ptr = NULL;

	return new_node;
}

//--------------------------------------------------
// Function to insert data at end
// @param  : List pointer
// @param  : int node_id
// @return : int status
//--------------------------------------------------
int insert_at_end(List *my_list, int node_id){

	Node *new_node; // Pointer for new node

	new_node = create_node(node_id);

	if(new_node == NULL)
		return FAILURE; // Insertion Failed

	// If list is empty
	if(my_list->count == 0){
	// Both head and tail poit to same node
		my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
		my_list->tail->node_ptr = new_node; // Pointer of node at tail points to new node
		my_list->tail = new_node; // node at tail is updated
	}

	my_list->count++;

	return SUCCESS;
}

//--------------------------------------------------
// Function to create adjacency list
// @param  : Graph (Array of List)
// @param  : int Graph Size
//--------------------------------------------------
void create_adjacency_list(List* graph[], int size){
	int i;
	int node_id;

	// Initialize the graph
	for(i=0; i<size; i++){
		graph[i] = initialize_list();
	}

	// Create the adjacent list
	for(i=0; i<size; i++){
		assert(insert_at_end(graph[i], i)); // Insert vertex

		printf("Enter Adjacent Node of %d : ", i);
		scanf("%d", &node_id);

		// Insert adjacent vertex
		while(node_id != 999){
			assert(insert_at_end(graph[i], node_id)); // Insert vertex
			printf("Enter Adjacent Node of %d : ", i);
		    scanf("%d", &node_id);
		}

	}
}

//--------------------------------------------------
// Function to print adjacency list
// @param  : Graph (Array of List)
// @param  : int Graph Size
//--------------------------------------------------
void print(List* graph[], int size){
	int i;
	Node *temp;

	for(i = 0; i<size; i++){
		printf("Vertex[%d]: ", i);

		temp = graph[i]->head;
		while(temp != NULL){
			printf("%d -> ", temp->node_id);
			temp = temp->node_ptr;
		}
		printf("NULL\n");
	}
}

//--------------------------------------------------
// Function to traverse graph using DFS
// @param  : Graph (Array of List)
// @param  : int first vertex
// @param  : int array of visited vertices
//--------------------------------------------------
void dfs(List* graph[], int vertex, int visited[]){
	Node *temp;
	
	// Print current vertex
	visited[vertex] = 1;
	printf("%d ", vertex);
	
	// Vist the next vertex
	for(temp = graph[vertex]->head; 
	    temp != NULL; 
		temp = temp->node_ptr){
		if(!visited[temp->node_id]){
		// If vertex is not visited
		    dfs(graph, temp->node_id, visited);
		}
	}
}

//----------------------------------------------------------------------------
// Queue Implementation for BFS
//----------------------------------------------------------------------------
// Queue initialization function
Queue *queue_initialize(){
	Queue *my_queue;

	// Allocate memory for queue
	my_queue = (Queue *)malloc(sizeof(Queue));

	if(my_queue == NULL)
		return NULL; // Memory allocation failed

	// Initialize
	my_queue->head = NULL;
	my_queue->tail = NULL;

	return my_queue;
}

// Insert Function, returns status
int enqueue(Queue *my_queue, int node_id){
	Node *new_node;
    new_node = create_node(node_id);
	
	if(new_node == NULL)
		return FAILURE;

	// Insert at end
	if(my_queue->tail == NULL){
    // Inserting first node
		my_queue->tail = new_node;
		my_queue->head = new_node;
	}
	else{
		my_queue->tail->node_ptr = new_node;
	    my_queue->tail = new_node;
	}

	return SUCCESS;
}

// Remove Function, returns data
int dequeue(Queue *my_queue){
	Node *temp;
    int node_id;
	
	// Remove data only if queue is not empty
	if(my_queue->head == NULL)
		return FAILURE;

	// Remove from beginning
	temp = my_queue->head;
	my_queue->head = temp->node_ptr;
	node_id = temp->node_id;
	free(temp);
	
	if(my_queue->head == NULL){
		my_queue->tail = NULL;
	}
	
	return node_id;
}

// Deallocate Function, returns NULL pointer
Queue *queue_deallocate(Queue *my_queue){
	Node *temp;

	while(my_queue->head != NULL){
		temp = my_queue->head;
		my_queue->head = temp->node_ptr;
		free(temp);
	}

	free(my_queue);

	return NULL;
}
//----------------------------------------------------------------------------

//--------------------------------------------------
// Function to traverse graph using BFS
// @param  : Graph (Array of List)
// @param  : int first vertex
// @param  : int array of visited vertices
//--------------------------------------------------
void bfs(List* graph[], int vertex, int visited[]){
	Queue *q;
	Node *temp;
	
	// Initialize Queue
	q = queue_initialize();
	
	// Print current vertex
	visited[vertex] = 1;
	printf("%d ", vertex);
	enqueue(q, vertex);

	while(q->head != NULL){
		vertex = dequeue(q);
        
		// Print all neighbouring vertices of current vertex
		for(temp = graph[vertex]->head; 
		    temp != NULL;
			temp = temp->node_ptr){
			
			if(!visited[temp->node_id]){
			// If vertex is not visited
				printf("%d ", temp->node_id);		
				visited[temp->node_id] = 1;
				enqueue(q, temp->node_id);
			}
		}
	}

}