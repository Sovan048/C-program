#include<stdio.h>

int partition(int a[],int start,int end)
{
    int pivot = a[end];
    int i = (start -1);

    for(int j = start; j <= end; j++)
    {
        if(a[j] < pivot)
        {
            i++;

            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    int t = a[i+1];
    a[i+1] = a[end];
    a[end] = t;

    return (i+1);
}

void quickSort(int a[],int start,int end)
{
    if(start < end)
    {
        int p =partition(a,start,end);

        quickSort(a,start,p-1);
        quickSort(a,p+1,end);
    }
}

void printArray(int a[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    printf("%d ",a[i]);
}

int main()
{
    int a[] = {34,54,76,24,97,07,23,48};
    int n = sizeof(a)/sizeof(a[0]);

    printf("Given array\n");
    printArray(a,n);

    quickSort(a,0,n-1);

    printf("After sorting\n");
    printArray(a,n);

    return 0;
}