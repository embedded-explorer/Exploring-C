#include <stdio.h>

int check(int num);

int main()
{
    int var;
    scanf("%d", &var);
    printf("%d", check(var));
    return 0;
}

int check(int num){
    if(num == 7)
        return 0;
    else if(num > 7)
        return 1;
    else if(num < 7)
        return -1;
    // Else part is missing will work fine
}
