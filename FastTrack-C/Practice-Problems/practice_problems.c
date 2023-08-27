#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "practice_problems.h"

// 1.
char upper_to_lower(char ch){
    if(ch >= 'A' && ch <= 'Z')
        return ch + 32; // A = 65, a = 97
    else
        return '!'; // Invalid input received
}

// 2.
float area_of_circle(float radius){
    return 3.14 * radius * radius; // Pi * r^2
}

// 3.
int char_between_char(char ch_1, char ch_2){
    if(ch_1 > ch_2)
        return ch_1 - ch_2 - 1;
    else
        return ch_2 - ch_1 - 1;
}

// 4.
float celsius_to_fahrenheit(float temperature){
    return temperature * 1.8 + 32; // Multiply by 1.8 (or 9/5) and add 32
}

// 5.
unsigned int odd_or_even(int num){
    return num % 2; // Return 1 if odd, 0 if even
}

// 6.
int check_leap_year(int year){
    // Must be exactly divisible by 4
    // Century years must also be divisible by 400
    // Return 1 if its leap year else return 0
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

// 7.
int pow_of_2(int raise){
    return 1 << raise;
}

// 8.
int char_or_int(char ch){
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return 0;
    else if(ch >= '0' && ch <= '9')
        return 1;
    else
        return -1;
}

// 9.
unsigned int add_rand(unsigned int x, unsigned int y){
    return x + y;
}

// 10.
unsigned int sum_of_digits(unsigned int num){
    unsigned int sum = 0;

    while(num > 0){
        sum += num % 10; // 5, 4, 3, 2, 1
        num = num / 10; // 1234, 123, 12, 1
    }

    return sum;
}

// 11.
unsigned int reverse_of_num(unsigned int num){
    unsigned int rev = 0;

    while(num > 0){
        rev = (rev * 10) + (num % 10);
        num = num / 10;
    }

    return rev;
}

// 12.
unsigned int count_digit(unsigned int num, unsigned int digit){
    unsigned int rem = 0;
    unsigned int count = 0;

    while(num > 0){
        rem = num % 10;
        num = num / 10;
        if(digit == rem){
            count++;
        }
    }

    return count;
}

// 13.
unsigned int check_palindrome(unsigned int num){
    unsigned int rev = 0;
    unsigned int temp = num;

    while(temp > 0){
        rev = (rev * 10) + (temp % 10);
        temp = temp / 10;
    }

    return rev == num; // Return 1 if palindrome, 0 if not a palindrome
}

// 14.
// Function to check if given number is prime or not
// Return 1 if number is prime else return 0
unsigned int is_prime(unsigned int num){
    if(num < 2){
        return 0;
    }

    for(int k=2; k<= num/2; k++){
        if(num % k == 0){
        // i is completely divisible by k
            return 0;
        }
    }

    return 1;
}

// 15.
unsigned int sum_of_series(unsigned int num){
    unsigned int count = 1, sum = 0;

    for(int i=1; i<=num; i++){
        printf("%d ", count);
        if(i < num){
            printf("+ ");
        }
        sum = sum + count; // Calculate sum
        count = (count*10)+1; // 1, 11, 111, 1111
    }
    printf("= %d", sum);
    return 0;
}

// 16.
unsigned int check_if_armstrong(unsigned int num){
    unsigned long int sum_of_cubes = 0;
    unsigned int rem, temp = num;

    while(temp > 0){
        rem = temp % 10;
        temp = temp / 10;
        sum_of_cubes += rem * rem * rem;
    }

    // Return 1 if number is Armstrong number
    return (num == sum_of_cubes);
}

// 17.
unsigned int check_if_amicable(unsigned int num_1, unsigned int num_2){
    unsigned int sum_1 = 0, sum_2 = 0;

    for(int i=1; i<= num_1/2; i++){
        if(num_1%i == 0){
            sum_1 = sum_1 + i;
        }
    }

    for(int j=1; j<= num_2/2; j++){
        if(num_2%j == 0){
            sum_2 = sum_2 + j;
        }
    }

    if((num_1 == sum_2) && (num_2 == sum_1)){
        return 1;
    }
    else{
        return 0;
    }
}

// 18.
unsigned int menu_driven_calculator(unsigned int num_1, unsigned int num_2, char operation){
    switch(operation){
    case '+':
        return num_1 + num_2;
        break;
    case '-':
        return num_1 - num_2;
        break;
    case '*':
        return num_1 * num_2;
        break;
    default :
        return -1;
        break;
    }
}

// 19.
float volume_of_cube(float length){
    return length * length * length;
}

float volume_of_cuboid(float length, float breadth, float height){
    return length * breadth * height;
}

float volume_of_sphere(float radius){
    return 4.188* radius * radius * radius; // 4/3 * Pi * r^3
}

float volume_of_cylinder(float radius, float height){
    return 3.14 * radius * radius * height;
}

float volume_of_cone(float radius, float height){
    return (3.14 * radius * radius * height)/3;
}

void main_menu(void){
    unsigned int shape;
    float dimension_1, dimension_2, dimension_3;

    printf("Select the Shape\n");
    printf("1 : Cube\n");
    printf("2 : Cuboid\n");
    printf("3 : Sphere\n");
    printf("4 : Cylinder\n");
    printf("5 : Cone\n");
    scanf("%d", &shape);

    switch(shape){
    case 1:
        printf("Enter the Length: ");
        scanf("%f", &dimension_1);
        printf("Volume of Cube: %f", volume_of_cube(dimension_1));
        break;
    case 2:
        printf("Enter the Length: ");
        scanf("%f", &dimension_1);
        printf("Enter the Breadth: ");
        scanf("%f", &dimension_2);
        printf("Enter the Height: ");
        scanf("%f", &dimension_3);
        printf("Volume of Cuboid: %f", volume_of_cuboid(dimension_1, dimension_2, dimension_3));
        break;
    case 3:
        printf("Enter the Radius: ");
        scanf("%f", &dimension_1);
        printf("Volume of Sphere: %f", volume_of_sphere(dimension_1));
        break;
    case 4:
        printf("Enter the Radius: ");
        scanf("%f", &dimension_1);
        printf("Enter the Height: ");
        scanf("%f", &dimension_2);
        printf("Volume of Cylinder: %f", volume_of_cylinder(dimension_1, dimension_2));
        break;
    case 5:
        printf("Enter the Radius: ");
        scanf("%f", &dimension_1);
        printf("Enter the Height: ");
        scanf("%f", &dimension_2);
        printf("Volume of Cone: %f", volume_of_cone(dimension_1, dimension_2));
        break;
    default:
        printf("\nInvalid Option Selected");
    }
}

// 20.
float electricity_bill(float units_consumed){
    float rem, amount = 0;

    if(units_consumed > 300){
        rem = units_consumed - 300;
        units_consumed = 300;
        amount += rem * 10;
    }
    if(units_consumed > 200){
        rem = units_consumed - 200;
        units_consumed = 200;
        amount += rem * 7;
    }
    if(units_consumed >= 0){
        amount += units_consumed * 5;
    }

    return amount;
}

// 21.
unsigned int bin_2_dec(unsigned long int num){
    unsigned int rem, dec = 0, pow = 1; // 2^0 = 1

    while(num > 0){
        rem = num % 10; // Get the LSB Digit
        num = num/10;   // Neglect the LSB Digit
        dec += rem * pow;
        pow = pow * 2;  // 2^1 = 2, 2^2 = 4, 2^3 = 8 ...
    }

    return dec;
}

unsigned long int dec_2_bin(unsigned int num){
    unsigned int rem, bin = 0;
    while(num > 0){
        rem = num % 2;
        num = num / 2;
        bin = bin*10 + rem;
    }

    // Actual Binary number is reverse of the result
    return reverse_of_num(bin);
}

// 22.
int generate_series(int arr[], int size){
    for(int i=0; i<size-3; i++){
        arr[i+3] = arr[i+0] + arr[i+1] + arr[i+2];
    }
    return 1; // Operation Success
}

// 23.
void print_pattern_1(int n){
    for(int i=0; i<n; i++){
        for(int j=n; j>i; j--){
            printf("*");
        }
        printf("\n");
    }
}

// 24.
void print_pattern_2(int n){
    int count=0;

    for(int i=0; i<n; ){

        if(count <= i){
            printf("*");
            count++;
        }

        if(count > i){
            printf("\n");
            count = 0;
            i++;
        }
    }
}

// 25.
void generate_series_2(void){
    for(int i=1; i<9; i++){
        printf("%d%d ", i, 9-i);
    }
}

// 26.
int power(int base, int exponent){
    if(exponent == 1)
        return base;
    else
        return base * power(base, (exponent-1));
}

// 27.
int factorial(int num){
    if(num == 1)
        return 1;
    else
        return num * factorial(num-1);
}

// 28. F(x) = x + x3/3! + x5/5! + x7/7!+ …
float series_evaluation(int x, int n){
    if(n == 1){
        return x;
    }

    else{
        return ((((float)power (x, ((2*n)-1))) / (float)factorial((2*n)-1)) + series_evaluation(x, n-1));
    }
}

// 29.
// Macro defined in .h file

// 30.
// Macro defined in .h file

// 31.
// Using Functions from math.h
/*
void main_menu_math_operations(void){
    int operation;
    float x, n;

    printf("Select the Required Operation\n");
    printf("1 : Natural Log(x)\n");
    printf("2 : Log10(x)\n");
    printf("3 : Power(x, n)\n");
    printf("4 : Sin(x)\n");
    printf("5 : Cos(x)\n");
    scanf("%d", &operation);

    switch(operation){
    case 1:
        printf("Enter x: ");
        scanf("%f", &x);
        printf("Natural Log(%f) = %f", x, log(x));
        break;
    case 2:
        printf("Enter x: ");
        scanf("%f", &x);
        printf("Log10(%f) = %f", x, log10(x));
        break;
    case 3:
        printf("Enter x: ");
        scanf("%f", &x);
        printf("Enter n: ");
        scanf("%f", &n);
        printf("(%f)^(%f) = %f", x, n, pow(x, n));
        break;
    case 4:
        printf("Enter x: ");
        scanf("%f", &x);
        printf("Sin(%f) = %f", x, sin(x));
        break;
    case 5:
        printf("Enter x: ");
        scanf("%f", &x);
        printf("Cos(%f) = %f", x, cos(x));
        break;
    default:
        printf("\nInvalid Option Selected");
    }
}
*/

// 32.
// Function to print integer array
int print_int_array(int arr[], int arr_size){
    for(int i=0; i<arr_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 1; // Operation Successful
}

int ascending_sort(int arr[], int arr_size){
    int temp;

    for(int i=0; i<arr_size; i++){
        for(int j=i+1; j<arr_size; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 1; // Return Success
}

int descending_sort(int arr[], int arr_size){
    int temp;

    for(int i=0; i<arr_size; i++){
        for(int j=i+1; j<arr_size; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 1; // Return Success
}

// 33.
void swap_by_ref(int *ptr_1, int *ptr_2){
    int temp = *ptr_1;
    *ptr_1 = *ptr_2;
    *ptr_2 = temp;
}

// 34.
int min_max_array(int arr[], int arr_size, int *min, int *max){
    if(arr_size == 0){
        return -1; // Invalid Array Size
    }

    *min = *max = arr[0];

    for(int i=1; i<arr_size; i++){
        if(*min > arr[i]){
            *min = arr[i];
        }
        if(*max < arr[i]){
            *max = arr[i];
        }
    }
    return 1; // Return Success
}

// 35.
// I. A union B (Write function set_union())
int set_union(int arr_a[], int size_a, int arr_b[], int size_b, int arr_c[], int size_c){
    int already_added=0;
    int count = 0;

    // Add Elements of array A to union array without repetition
    for(int i=0; i<size_a; i++){
        already_added = 0;
        for(int j=0; j<count; j++){
            if(arr_a[i] == arr_c[j]){
                already_added = 1;
                break;
            }
        }
        if(!already_added){
            arr_c[count++] = arr_a[i];
        }
    }

    // Add Elements of array B to union array without repetition
    for(int i=0; i<size_b; i++){
        already_added = 0;
        for(int j=0; j<count; j++){
            if(arr_b[i] == arr_c[j]){
                already_added = 1;
                break;
            }
        }
        if(!already_added){
            arr_c[count++] = arr_b[i];
        }
    }

    return count; // Return number of elements in array C
}

// II. A intersection B (Write function set_intersection())
int set_intersection(int arr_a[], int size_a, int arr_b[], int size_b, int arr_c[], int size_c){
    int already_added=0;
    int count = 0;

    for(int i=0; i<size_a; i++){
    // For element of array A
        for(int j=0; j<size_b; j++){
        // Check against each element of array B
            if(arr_a[i] == arr_b[j]){
            // If element is present in both array A and array B
                already_added = 0;
                for(int k=0; k<count; k++){
                // Check if element is already added to array C
                    if(arr_a[i] == arr_c[k]){
                        already_added = 1;
                        break;
                    }
                }
                if(!already_added){
                    arr_c[count++] = arr_a[i];
                }
            }
        }
    }
    return count; // Return number of elements in array C
}

// III. A-B and B-A (Write function set_difference())
int set_difference(int arr_a[], int size_a, int arr_b[], int size_b, int arr_c[], int size_c){
    int is_present = 0;
    int count = 0;

    for(int i=0; i<size_a; i++){
    // For each element of array B
        for(int j=0; j<size_b; j++){
        // Check if that element is present in array A
            is_present = 0;
            if(arr_a[i] == arr_b[j]){
                is_present = 1;
                break;
            }
        }
        if(!is_present){
            arr_c[count++] = arr_a[i];
        }
    }
    return count;
}

// 36.
int remove_duplicate_in_array(int arr[], int arr_size){
    int count = arr_size;
    int is_repeated = 0;
    int i, j, k;
    for(i=0; i<count-1; i++){
        for(j=i+1; j<count; j++){
            is_repeated = 0;
            if(arr[i] == arr[j]){
                is_repeated = 1;
                break;
            }
        }
        if(is_repeated){
            for(k=j; k<=count-1; k++){
                arr[k] = arr[k+1];
            }
            count--;
            i--;
        }
    }

    return count;
}

// 37.
int linear_search(int arr[], int arr_size, int element){
    for(int i=0; i<arr_size; i++){
        if(arr[i] == element){
            return i; // Return Element Index
        }
    }
    return -1; // Return Element not Found
}

// 38.
// Assumption input array is sorted in ascending order
int binary_search(int arr[], int arr_size, int element){
	int mid, low = 0, high = arr_size;

	while(low <= high){

		mid = low + ((high - low) / 2);

		// Return index if element is found in middle
		if(arr[mid] == element)
			return mid;

		// If element is greater ignore lower part
		if(arr[mid] < element)
			low = mid + 1;

		// If element is smaller ignore heigher part
		if(arr[mid] > element)
			high = mid - 1;
	}

	return -1; // Element not found
}

// 39.
int sum_of_product(int arr[], int arr_size){
    int sop = 0;

    for(int i=0; i<arr_size-1; i++){
        sop += arr[i] * arr[i+1];
    }

    return sop;
}

// 40.
int find_string_length(char str[]){
    int length = 0;

    while(str[length] != '\0'){
        length++;
    }

    return length;
}

// 41.
void worded_date(int day, int month, int year, char str[]){
    
	char year_str[5];
	
	sprintf(str, "%d", day);
	sprintf(year_str, "%d", year);
	
    switch(day){
    case 1:
    case 21:
    case 31:
        strcat(str, "st");
        break;
    case 2:
    case 22:
        strcat(str, "nd");
        break;
    case 3:
    case 23:
        strcat(str, "rd");
        break;
    default:
        strcat(str, "th");
        break;
    }

    switch(month){
    case 1:
        strcat(str, " January ");
        break;
    case 2:
	    strcat(str, " February ");
        break;
    case 3:
	    strcat(str, " March ");
        break;
    case 4:
	    strcat(str, " April ");
        break;
    case 5:
	    strcat(str, " May ");
        break;
    case 6:
	    strcat(str, " June ");
        break;
    case 7:
	    strcat(str, " July ");
        break;
    case 8:
	    strcat(str, " August ");
        break;
    case 9:
	    strcat(str, " September ");
        break;
    case 10:
	    strcat(str, " October ");
        break;
    case 11:
	    strcat(str, " November ");
        break;
    case 12:
	    strcat(str, " December ");
        break;
    default:
        break;
    }
	
	strcat(str, year_str);
	
}

// 42.
void lower_to_upper(char str[]){
    int i=0;

    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
        i++;
    }
}

// 43.
void reverse_string(char str[]){
    int str_len = find_string_length(str)-1;
    int len = str_len/2;
    char temp;

    for(int i=0; i<=len; i++){
        temp = str[i];
        str[i] = str[str_len - i];
        str[str_len - i] = temp;
    }
}

// 44.
int string_palindrome(char *str){
    int str_len = find_string_length(str)-1;
    int i = 0;

    while(i <= str_len){
    // Using != in while loop will not work for even length palindrome
        if(str[i] != str[str_len]){
            return 0; // Not a palindrome
        }
        i++;
        str_len--;
    }
    return 1; // palindrome
}

// 45.
void string_concat(char *str_1, char *str_2){
	int len_1 = 0, len_2 = 0;
	
	// Move to end of string 1
	while(str_1[len_1] != '\0'){
		len_1++;
	}
	
	// Copy string 2 to string 1
	while(str_2[len_2] != '\0'){
		str_1[len_1++] = str_2[len_2++];
	}
	
	// Add null terminator to concatenated string
	str_1[len_1] = '\0';
}

// 46.
// Create 2D matrix using double pointers
int **create_2d_matrix(int rows, int columns){
	int **matrix_ptr;
	int i;
	
	// Allocate memory for an array of row pointers
	matrix_ptr = (int **)malloc(sizeof(int *) * rows);
	
	// Allocate memory for each row
	for(i = 0; i<rows; i++){
		*(matrix_ptr + i) = (int *)malloc(sizeof(int) * columns);
	}
	
	// Return the double pointer to the matrix
	return matrix_ptr;
}

// Initialize 2D matrix
int initialize_2d_matrix(int **my_matrix, int rows, int columns){
	int i, j;
	
	// Check if double pointer has valid address
	if(my_matrix == NULL)
		return -1; // Return Failure
	
	// Check if each row pointers have valid address
	for(i=0; i<rows; i++){
		if(*(my_matrix + i) == NULL)
			return -1;
	}
	
	// Insert elements
	for(i=0; i<rows; i++){
		for(j=0; j<columns; j++)
			*(*(my_matrix + i)+j) = rand() % 40;
	}
	
	return 1; // Return Success
}

// Print 2D matrix
int print_2d_matrix(int **my_matrix, int rows, int columns){
	int i, j;
	
	// Check if double pointer has valid address
	if(my_matrix == NULL)
		return -1; // Return Failure
	
	// Check if each row pointers have valid address
	for(i=0; i<rows; i++){
		if(*(my_matrix + i) == NULL)
			return -1;
	}
	
	// Print elements
	for(i=0; i<rows; i++){
		for(j=0; j<columns; j++){
			printf("%02d ", *(*(my_matrix + i)+j));
		}
		printf("\n");
	}
	
	return 1; // Return Success
}

// 47.
// Assumption works for square matrix
int transpose_2d_matrix(int **my_matrix, int rows, int columns){
	int temp, i, j;
	
	// Check if double pointer has valid address
	if(my_matrix == NULL)
		return -1; // Return Failure
	
	// Check if each row pointers have valid address
	for(i=0; i<rows; i++){
		if(*(my_matrix + i) == NULL)
			return -1;
	}
	
	// Run swapping for upper traingular matrix
	for(i=0; i<rows; i++){
		for(j=i+1; j<columns; j++){
			if(i != j){
			    temp = *(*(my_matrix + i)+j);
			    *(*(my_matrix + i)+j) = *(*(my_matrix + j)+i);
			    *(*(my_matrix + j)+i) = temp;
			}
		}
	}
	
	return 1; // Return Success
}

// 48.
int print_column_sum(int **my_matrix, int rows, int columns){
	int col_sum, i, j;
	
	// Check if double pointer has valid address
	if(my_matrix == NULL)
		return -1; // Return Failure
	
	// Check if each row pointers have valid address
	for(i=0; i<rows; i++){
		if(*(my_matrix + i) == NULL)
			return -1;
	}
	
	for(j=0; j<columns; j++){
		col_sum = 0;
		for(i=0; i<rows; i++){
			col_sum += *(*(my_matrix + i)+j);
		}
		printf("%03d ", col_sum);
	}
	
	return 1; // Return Success
}

// 49.
int check_if_sparse(int rows, int columns, int my_matrix[rows][columns]){
	int i, j, count = 0;
	int valid = (rows * columns)/2;
	
	// Check if double pointer has valid address
	if(my_matrix == NULL)
		return -1; // Return Failure
	
	for(i=0; i<rows; i++){
		for(j=0; j<columns; j++){
			if(my_matrix[i][j] == 0)
				count++;
		}
	}

	return count > valid;
}

/*
// 50.
// Function to Initialize Array
Student_Array initialize_array(int size){
    Student_Array my_arr;
    my_arr.c_size = 0;
    my_arr.t_size = (size > 0 && size <= MAX_SIZE) ? size : MAX_SIZE;
    return my_arr;
}

// Function to store data in to array
Student_Array store_data(Student_Array std_arr, Student std_data){
	if(std_arr.c_size == std_arr.t_size)
		return std_arr; // Return Failure
	
	std_arr.std[std_arr.c_size++] = std_data;
	
	return std_arr; // Return Success
}

// Function to print student array
void print_data(Student_Array std_arr){
	Student std;
	for(int i=0; i<std_arr.c_size; i++){
		std = std_arr.std[i];
	    printf("Roll No.: %d\n", std.roll_no);
		printf("Name    : %s\n", std.name);
		printf("Age     : %d\n", std.age);
		printf("Marks   : %f\n\n", std.marks);
	}
}
*/

// 51.
Complex_Num add_complex(Complex_Num a, Complex_Num b){
	Complex_Num res;
	
	res.real = a.real + b.real;
	res.img = a.img + b.img;
	
	return res;
}

Complex_Num sub_complex(Complex_Num a, Complex_Num b){
	Complex_Num res;
	
	res.real = a.real - b.real;
	res.img = a.img - b.img;
	
	return res;
}

// (a+bi)(c+di)=(ac-bd)+(ad+bc)i
Complex_Num mul_complex(Complex_Num a, Complex_Num b){
	Complex_Num res;
	
	res.real = (a.real*b.real) - (a.img*b.img);
	res.img = (a.real*b.img) + (a.img*b.real);
	
	return res;
}

// 57.
int disp_file_content(FILE *ptr){
	
	char ch;
	if(ptr == NULL)
		return -1; // Return Failure
	
	do{
		ch = fgetc(ptr);
		printf("%c", ch);
	}while(ch != EOF);
		
	return 1; // Return Success
}

// 58.
int copy_file_content(FILE *dest, FILE *src){
	
	char ch;
	if(dest == NULL)
		return -1; // Return Failure
	
	if(src == NULL)
		return -1; // Return Failure
	
	// https://stackoverflow.com/questions/31630072/extra-character-at-end-while-copying
	while(1){
		ch = fgetc(src);
		if(ch == EOF)
			break;
		fputc(ch, dest);
	}
		
	return 1; // Return Success
}

// 59.
int char_count_in_file(FILE *fptr){
	char ch;
	int char_count = 0;
	int line_count = 0;
	int tab_count = 0;
	int space_count = 0;

	if(fptr == NULL)
		return -1; // Return Failure
	
	do{
		ch = fgetc(fptr);
		if(ch == '\n')
			line_count++;
		else if(ch == '\t')
			tab_count++;
		else if(ch == ' ')
			space_count++;
		else
			char_count++;
	}while(ch != EOF);
	
	printf("Character Count: %d\n", char_count);
	printf("Space Count    : %d\n", space_count);
	printf("Tab Count      : %d\n", tab_count);
	printf("Line Count     : %d\n", line_count);
	
	return 1; // Return Success
}

// 60.
int odd_even_sorting(FILE *num_ptr, FILE *evn_ptr, FILE *odd_ptr){
	
	char ch;
	int num = 0;
	
	if(num_ptr == NULL || evn_ptr == NULL || odd_ptr == NULL)
		return -1; // Return Failure

	do{
		num = 0;
		while(1){
			ch = fgetc(num_ptr);
			// Break if end of line or end of file
			if(ch == '\n' || ch == EOF)
				break;
			// Convert to integer from character
			num = (num * 10) + ((int)ch - '0');
		}
		
		if(num%2)
			fprintf(odd_ptr, "%d\n", num);
		else
			fprintf(evn_ptr, "%d\n", num);
		
	}while(ch != EOF);
	
	return 1; // Return Success
}
