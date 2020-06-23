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