#include <stdio.h>

// Function to find the largest number in an array
int findLargestNumber(int arr[], int size) {
    int largest = arr[0]; // Assume the first element is the largest

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest if a larger element is found
        }
    }

    return largest;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Call the function to find the largest number
    int largestNumber = findLargestNumber(array, size);

    printf("The largest number in the array is: %d\n", largestNumber);

    return 0;
}
