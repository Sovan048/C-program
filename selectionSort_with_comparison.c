#include <stdio.h>

// Function to perform selection sort and count comparisons
void selectionSort(int arr[], int n, int *comparisonCount) {
    int i, j, minIndex, temp;
    *comparisonCount = 0; // Initialize comparison count to 0

    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            (*comparisonCount)++; // Increment comparison count
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i, comparisonCount;
    
    // Taking input for array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Taking input for array elements
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Perform selection sort and count comparisons
    selectionSort(arr, n, &comparisonCount);
    
    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);
    
    // Print the number of comparisons
    printf("Number of comparisons: %d\n", comparisonCount);

    return 0;
}
