#include <stdio.h> 
#include <limits.h>

// finding whether the value in order or not
int isOutOfOrder(int i, int num, int *arr, int n) {
    if(i == 0) {
        return num > arr[i+1];
    }
    if(i == n-1) {
        return num < arr[i-1];
    }
    return (num > arr[i+1] || num < arr[i-1]);
}

// function to find the minimum array to be sorted
void arrangeSubArray(int *arr, int n) {

    // min and max value of element which are out of order
    int minOutOfOrder = INT_MAX;
    int maxOutOfOrder = INT_MIN;
    for(int i=0; i<n; i++) {
        int num = arr[i];
        if(isOutOfOrder(i, num, arr, n)) {
            minOutOfOrder = (num < minOutOfOrder)? num : minOutOfOrder;
            maxOutOfOrder = (num > maxOutOfOrder)? num : maxOutOfOrder;            
        }
    }

    // if array is already sorted
    if(minOutOfOrder == INT_MAX) {
        printf("-1 -1");
        return;
    }

    // finding the postion of min and max outoforder element s
    int start = 0;
    int end = n-1;
    while(minOutOfOrder >= arr[start]) {
        start++;
    }
    while(maxOutOfOrder <= arr[end]) {
        end--;
    }

    // here index starts from 0
    printf("%d %d", start, end);
}

// driver function
int main() {

    // getting array size and its elements
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    // calling funtion to arrange array
    arrangeSubArray(arr, n);
    return 0;
}

// problem

// write a function that takes in an array of atleast two integers and that returns an array of th starting and ending indices of the smallest subarray in the input array that needs to be sorted in  place in order for the entire input array to be sorted.
// if the input array is already sorted, the function should return -1 -1.

// input:
// 13
// 1 2 4 7 10 11 7 12 6 7 16 18 19

// output:

// 3 9