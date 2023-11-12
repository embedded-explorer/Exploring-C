
//----------------------------------------------------------------------
// 1. Adjacency List
//----------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "adjacency_list.h"

int main(){
	
	// Array of pointers
    List *graph[MAX];
	
	int visited[MAX] = {0};

	// Test Create adjacency list
    create_adjacency_list(graph, MAX);

	// Print adjacency list
	print(graph, MAX);
	
	// Test DFS
	printf("DFS : ");
	dfs(graph, 0, visited);
	
	// Test BFS
	for(int i=0; i<MAX; i++) // Reset Visited Array
		visited[i] = 0;
	
	printf("\nBFS : ");
	bfs(graph, 0, visited);

    return 0;
}
