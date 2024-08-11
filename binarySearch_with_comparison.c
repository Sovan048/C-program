#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target, int *comparisonCount) {
    int left = 0;
    int right = size - 1;
    *comparisonCount = 0; // Initialize comparison count to 0

    while (left <= right) {
        (*comparisonCount)++; // Increment comparison count
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // Target is not present in array
    return -1;
}

int main() {
    int size, target, comparisonCount;

    // Taking user input for the array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Taking user input for the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking user input for the target value to search for
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Sort the array using quicksort
    quicksort(arr, 0, size - 1);

    // Perform binary search
    int result = binarySearch(arr, size, target, &comparisonCount);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    // Print the number of comparisons made
    printf("Number of comparisons made: %d\n", comparisonCount);

    return 0;
}
