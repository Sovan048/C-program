#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);
int randomPartition(int arr[], int low, int high);

// Global variable to count comparisons
int comparisonCount = 0;

int main() {
    int n;

    // Taking input for the array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking input for the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize random number generator
    srand(time(NULL));

    // Perform quicksort
    quickSort(arr, 0, n - 1);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the number of comparisons
    printf("Number of comparisons: %d\n", comparisonCount);

    return 0;
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = randomPartition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function with random pivot
int randomPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]);
    return partition(arr, low, high);
}

// Standard partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        // Count comparisons
        comparisonCount++;
        
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Swap function
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
