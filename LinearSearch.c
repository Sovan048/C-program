#include<stdio.h>
int main(){
    int n,num[20];
    printf("How many elements you want to take input\n");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    int item;
    printf("Enter searching elements\n");
    scanf("%d",&item);
    for(int i=1;i<=n;i++){
        if(item==num[i])
        {
            printf("The no %d is found at location %d",item,i);
            break;
        }
        if(i==n+1){
            printf("item not found");
        }
    }
    return 0;
}