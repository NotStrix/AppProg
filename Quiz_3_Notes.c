/*Exam will be on chapters 5-7 of zybooks
Topics to study:
- functions and pointers 
    - passed by value 
    - passed by address
    - return values

- pointers
    - & gets address of variable
    - * gets value at address
    - declaration of pointer variables
    
int f2(int *p1, int *p2) {
*p1 = *p1 + 2;
*p2 = *p2 – 3;
return *p1 + *p2;
}
int main() {
int a = 10;
int b = 20;
int c = f2(&a, &b);
}

- 1D Arays 
    - x[10] declares an array of 10 integers [0-9]
    - can define with value list: int arr[] = {10, 30, 2160, -1};
    - if size not specified, size is determined by number of values in list
    - if size > number of values in list, remaining values initialized to 0

- 2D Arrays
    - similar declaration: int arr[5][2]; 5 rows, 2 columns
    - typically used in nested loops to access elements

- Passing arrays to functions
    - dont need to specify size in parameter list

- Strings
    - null character '\0' at end of string
    - initialize with char str[] = "hello"; or char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    - use %s in printf to print strings
    - read string with fgets()
    - fgets() reads until newline or specified size - 1, adds null terminator
    - strlen() to get length of string (excluding null terminator)


*/