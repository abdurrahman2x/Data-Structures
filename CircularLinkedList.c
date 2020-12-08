#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

//Push the first node
void push(struct node **start,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    (*start) = temp;
}

//add new node
void add(struct node *start,int data){
    struct node *temp = start;
    while (temp->next != start){
        temp = temp->next;
    }
    temp->next = (struct node*)malloc(sizeof(struct node));
    temp->next->data = data;
    temp->next->next = start;
}

//print the list from start to end
void printList(struct node *start){
    struct node *temp = start;
    printf("\n-----------------------------------------------PRINT LIST-----------------------------------");
    printf("\nData : %d",temp->data);
    temp = temp->next;
    while (temp != start){
        printf("\nData : %d",temp->data);
        temp = temp->next;
    }
}

//The main function
int main(){
    struct node *head = NULL;

    push(&head,10);

    add(head,20);
    add(head,30);
    add(head,40);
    add(head,50);

    printList(head);
}


