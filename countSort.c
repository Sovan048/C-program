#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size, int max) {
    int *count = (int *)malloc((max + 1) * sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));

    // Initialize count array with all zeros
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; ++i) {
        count[array[i]]++;
    }

    // Store the cumulative count
    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    // Find the index of each element in the original array in the count array
    // and place them in the output array
    for (int i = size - 1; i >= 0; --i) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < size; ++i) {
        array[i] = output[i];
    }

    // Free dynamically allocated memory
    free(count);
    free(output);
}

int main() {
    int n, max = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
        if (array[i] > max) {
            max = array[i];
        }
    }

    countingSort(array, n, max);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
