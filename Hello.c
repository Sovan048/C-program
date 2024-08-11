#include<stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i,int* com)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
        (*com)++;
    }

    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
        (*com)++;
    }

    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);

        heapify(arr,n,largest,com);
    }
}

void heapSort(int arr[],int n,int* com)
{
    for(int i = n / 2 - 1; i >= 0;i--)
    {
        heapify(arr,n,i,com);
    }

    for(int i = n -1; i >= 0; i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0,com);
    }
}

void printfArray(int arr[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of element:\n");

    int arr[n];
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int com = 0;
    heapSort(arr,n,&com);

    printf("\nSorted array:\n");
    printfArray(arr,n);

    printf("The number of comparison is : %d",com);

    return 0;
}