#include <stdio.h>

int main() {
    int a[10],n,item;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &item);

    for (int i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }

    a[0] = item;

    n++;

    printf("Array after inserting %d at the first position:\n", item);
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}
