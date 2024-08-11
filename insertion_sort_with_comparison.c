#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons) {
    int i, key, j;
    *comparisons = 0; // Initialize the comparisons counter

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*comparisons)++;
        }
        arr[j + 1] = key;

        // Account for the final comparison that breaks the while loop
        if (j >= 0) {
            (*comparisons)++;
        }
    }
}

int main() {
    int arr[50], n;
    int comparisons;

    printf("Enter how many elements: \n");
    scanf("%d",&n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }

    insertionSort(arr, n, &comparisons);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
