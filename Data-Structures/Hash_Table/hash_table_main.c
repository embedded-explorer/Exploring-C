
//----------------------------------------------------------------------
// 1.
//----------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"

int main(){
	
    Hash_Table *table;
    
	// Test initialization function
    table = initialize_table();
	assert(table != NULL);
	for(int i=0; i<TABLE_SIZE; i++)
		assert(table->table[i] == NULL);
    
	// Test insert function
	assert(insert_value(table, 10));
	assert(insert_value(table, 20));
	assert(insert_value(table, 30));
	assert(insert_value(table, 11));
	assert(insert_value(table, 21));
	assert(insert_value(table, 12));
	assert(insert_value(table, 22));
	
	// Test search function
	assert(search_value(table, 10) == SUCCESS);
	assert(search_value(table, 20) == SUCCESS);
	assert(search_value(table, 30) == SUCCESS);
	assert(search_value(table, 40) == FAILURE);
	assert(search_value(table, 12) == SUCCESS);
	
	// Test print function
	print_table(table);
	
	// Test delete function
	assert(delete_value(table, 35) == FAILURE);
	assert(delete_value(table, 10) == SUCCESS);
	assert(delete_value(table, 21) == SUCCESS);
	assert(delete_value(table, 11) == SUCCESS);
	print_table(table);
	
    return 0;
}