#include <stdio.h>

int main() {
    int a[10],n, pos;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the position to delete (0-based index): ");
    scanf("%d", &pos);

    for (int i = pos-1; i < n ; i++) {
        a[i] = a[i + 1];
    }

    n--;
    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    return 0; 
}
