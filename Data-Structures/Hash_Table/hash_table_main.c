/*
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
*/

/*
//----------------------------------------------------------------------
// 2.
//----------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"

int main(){
	#define TABLE_SIZE 5
    List **table;
	
	// Test initialization function
    table = initialize_ht(TABLE_SIZE);
	assert(table != NULL);

	// Test insert function
	// Index 0
	assert(insert_ht(table, 10, TABLE_SIZE));
	assert(insert_ht(table, 30, TABLE_SIZE));
	assert(insert_ht(table, 45, TABLE_SIZE));
	assert(insert_ht(table, 20, TABLE_SIZE));
    
	// Index 4
	assert(insert_ht(table, 14, TABLE_SIZE));
	assert(insert_ht(table, 34, TABLE_SIZE));
	assert(insert_ht(table, 89, TABLE_SIZE));
	assert(insert_ht(table, 24, TABLE_SIZE));
	
	// Test Print
	print(table, TABLE_SIZE);
	printf("\n");
	
	// Test Delete Function
	assert(delete_ht(table, 14, TABLE_SIZE) == SUCCESS);
	assert(delete_ht(table, 30, TABLE_SIZE) == SUCCESS);
	assert(delete_ht(table, 100, TABLE_SIZE) == FAILURE);
	print(table, TABLE_SIZE);
	printf("\n");
	
	// Test Search Function
	assert(search_ht(table, 45, TABLE_SIZE) == SUCCESS);
	assert(search_ht(table, 89, TABLE_SIZE) == SUCCESS);
	assert(search_ht(table, 60, TABLE_SIZE) == FAILURE);
	
	return 0;
}
*/

//----------------------------------------------------------------------
// 3.
//----------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"

int main(){
	#define TABLE_SIZE 26
    List **table;
	
	// Test initialization function
    table = initialize_ht(TABLE_SIZE);
	assert(table != NULL);

	// Test insert function
	// A
	assert(insert_ht(table, "Anupam", TABLE_SIZE));
	assert(insert_ht(table, "Adish", TABLE_SIZE));
	assert(insert_ht(table, "Akhil", TABLE_SIZE));
    
	// R
	assert(insert_ht(table, "raja", TABLE_SIZE));
	assert(insert_ht(table, "Ram", TABLE_SIZE));

	// Test Delete Function
	assert(delete_ht(table, "Akhil", TABLE_SIZE) == SUCCESS);
	assert(delete_ht(table, "Ramesh", TABLE_SIZE) == FAILURE);

	print(table, TABLE_SIZE);
	printf("\n");
	
	// Test Search Function
	assert(search_ht(table, "Ram", TABLE_SIZE) == SUCCESS);
	assert(search_ht(table, "Jitesh", TABLE_SIZE) == FAILURE);

	return 0;
}