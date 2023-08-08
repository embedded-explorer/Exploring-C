#include <stdio.h>
#include <assert.h>
#include "strings.h"

int main(){

    char str[STRING_SIZE] = "India";
    char tgt[STRING_SIZE];

    assert(get_string_len(str) == 5);

    assert(str_cpy(str, tgt));

    printf("Target String is \"%s\"", tgt);


    return 0;
}
