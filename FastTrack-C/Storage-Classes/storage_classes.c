#include "storage_classes.h"

/*
// Extern Keyword Example
global_variable = 37;

int increment(void){
    return ++global_variable;
}
*/

int increment_int (void){
    int x = 0;
    return x++;
}

int increment_static_int (void){
    static int y = 0; // Static Variables get initialized only once
    return y++;
}
