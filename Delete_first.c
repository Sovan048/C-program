#include <stdio.h>

int main() {
    int a[10], n, i, pos;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
  //  pos = 0;
    for (i = 0; i < n ; i++) {
        a[i] = a[i + 1];
    }

    n--;

    printf("Array after deleting the first element:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
