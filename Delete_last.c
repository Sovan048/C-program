#include <stdio.h>

int main() {
    int a[10], n, i, pos;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    n--;

    printf("Array after deleting the first element:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}
