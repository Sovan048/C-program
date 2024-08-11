#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++; // Increment comparison count
        if (arr[i] == x)
            return i; // Return the index if element is found
    }
    return -1; // Return -1 if element is not found
}

int main() {
    int n, x, comparisons = 0;

    // Taking array size input from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking array elements input from the user
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the element to search for from the user
    printf("Enter the element to search for: ");
    scanf("%d", &x);

    // Perform linear search
    int result = linearSearch(arr, n, x, &comparisons);

    // Print the result
    if (result != -1)
        printf("Element %d found at index %d.\n", x, result);
    else
        printf("Element %d not found in the array.\n", x);

    // Print the number of comparisons made
    printf("Number of comparisons made: %d\n", comparisons);

    return 0;
}
