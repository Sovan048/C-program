#include<stdio.h>

int main()
{
    int a[20],n,i,j,temp;
    printf("Enter the array size: ");
    scanf("%d",&n);
    
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n-1;i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Sorted array:\n");
    for(i = 0; i < n; i++){
        printf("%d\t",a[i]);
    }
    return 0;
}