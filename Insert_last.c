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

    a[n] =item;
    n++;

    printf("Updated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    return 0;
}
