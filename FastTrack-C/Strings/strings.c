// Function to find string length
unsigned int get_string_len(const char str[]){
    unsigned int len = 0;

    while(str[len++] != '\0');

    return len-1;
}

// Function to copy the string
int str_cpy(char src[], char tgt[]){
    int index = 0;

    while(src[index] != '\0'){
        tgt[index] = src[index];
        index++;
    }
    tgt[index] = '\0';

    return 1; // Return Success
}
