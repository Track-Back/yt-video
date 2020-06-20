#include <stdio.h>

// Sorting function
void sortArray012(int* arr, int n) {

    // Declaring variable and counting number of 0's, 1's and 2's in an array
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) 
            count0++;
        else if(arr[i] == 1)
            count1++;
        else if(arr[i] == 2) 
            count2++;
    }

    // Updating the array with sorted values
    int i=0;

    // updating value 0's
    while(count0) {
        arr[i] = 0;
        count0--;
        i++;
    }

    // updating value 1's
    while(count1) {
        arr[i] = 1;
        count1--;
        i++;
    }

    // updating value 2's
    while(count2) {
        arr[i] = 2;
        count2--;
        i++;
    }
}

// print the array function
void print(int* arr, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

// Driver function
int main() {

    // Declaring a variable to store length of an array(n) and getting value
    int n; 
    scanf("%d", &n);

    // Declaring array and getting array elements
    int arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting array in O(n)
    sortArray012(arr, n);

    // Printing sorted array
    print(arr, n);

    return 0;
}


// Problem 
// Given an array Arr of size N containing 0s, 1s, 2s 
// you need to sort the array in ascending order

// Sample input: 
// 7 2 1 0 2 0 1 2
// Output:
// 0 0 1 1 2 2 2