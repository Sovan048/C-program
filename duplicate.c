#include <stdio.h>

// Function to count the total number of duplicate elements in the array
int countDuplicates(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break; // To avoid counting the same element multiple times
            }
        }
    }

    return count;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check if the array size is valid
    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int totalDuplicates = countDuplicates(arr, size);

    printf("Total number of duplicate elements in the array: %d\n", totalDuplicates);

    return 0;
}
