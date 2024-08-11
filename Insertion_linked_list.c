#include<stdio.h>
#include<stdlib.h>
void beginsert(int);
struct node{
    int data;
    struct node *next;
};
struct node *head;
void main()
{
    int choice,item;
    do
    {
        printf("Which item do you take as input\n");
        scanf("%d",&item);
        beginsert(item);
        printf("\nPress 0 to insert more\n");
        scanf("%d",&choice);
    } while(choice == 0);
}
void beginsert(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL){
        printf("\nOVERFLOW\n");
    }
    else
    {
        ptr->data = item;
        ptr->next = head;
        ptr = head;
        printf("\nNode inserted\n");
    }
}