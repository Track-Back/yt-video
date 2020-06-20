#include <stdio.h> 

// TO check whether value present in array or not
int checkDiffPresent(int* arr, int len, int val) {
    for(int i=0; i<len; i++) {

        // If value present then returns 1
        if(arr[i] == val) {
            return 1;
        }
    }

    // If value not present then returns 0
    return 0;
}

// Driver function
int main() {

    // n be the size of an array
    int n;
    scanf("%d", &n);

    // Val be the required sum and arr is to store array element
    int val, arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &val);
    int newArr[n], len=0;
    for(int i=0; i<n; i++) {
        int diff = val - arr[i];

        //checking whether diff present in newArr 
        if(checkDiffPresent(newArr, len, diff)) {

            // If diff found then printing o/p
            printf("%d %d\n", arr[i], diff);
        } else {

            // If diff not found in newArr then adding the value to newArr
            newArr[len] = arr[i];
            len++;
        }
    }
    return 0;
}

// problem:

// If any two numbers in the input array sum up to the target sum, then the values must be printed

// Input: 

// 6
// 5 7 2 8 6 3 
// 13

// Output: 

// 5 8 
// 7 6