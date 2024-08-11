#include<stdio.h>
int main(){
    int a[10],n,pos,i,item;
    printf("Enter how many elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the position: ");
    scanf("%d",&pos);
    printf("Enter the elements: ");
    scanf("%d",&item);
    for(i=n-1;i>=pos-1;i--){
        a[i+1]=a[i];
    }
    a[pos-1]=item;
    for(i=0;i<=n;i++){
        printf("%d\t",a[i]);
    }
}