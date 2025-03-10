#include <stdio.h>
#include <stdlib.h>
// function prototype for sum up all values of "arr" iteratively
int sum_iterative(int arr[], int size);
// function prototype for sum up all values of "arr" recursively
int sum_recursive(int arr[], int size);

int main() {
// variable for user input indicating size of array
int size; // Größe des Arrays
// user input for the size of the array
printf("Please provide the size of the array: ");
scanf("%d", &size);

//Dynamic int array 
int *arr = NULL; 

// allocate memory 
arr = (int*)malloc(size*sizeof(int)); 

// check if allocation successfull
if (arr == NULL) {
 printf("allocation failed");
 return 1; 
}

// input of the numbers 
for (int i = 0; i < size; i++) {
 scanf("%d", &arr[i]);  
}


// pass the array by refence and the size by value and print the sum
int iterative_result = sum_iterative(arr, size);
printf ("\n%d", iterative_result); 

int recursive_result = sum_recursive(arr, size); 
printf("\n%d", recursive_result); 

// free memory 
free(arr); 
// point arr to NULL to avoid dangling pointer 
arr = NULL; 

 return 0; 
}

int sum_iterative(int arr[], int size) {
 // counter 
 int sum = 0; 
 // loop throgh the arrays and add um numbers 
 for (int i = 0; i < size; i++) {
  sum += arr[i];  
 }
 return sum; 
}


int sum_recursive(int arr[], int size) {
 // Base case 
 if (size == 0) {
  return 0; 
 }
 else {
  return arr[size - 1] + sum_recursive(arr, size - 1);  // Add current element 
 }

}












