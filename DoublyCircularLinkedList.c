#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

//push the first node
void push(struct node **start,int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    (*start) = temp;
}

//To add new node
void add(struct node *start,int data){
    struct node *temp = start;
    while (temp->next != start){
        temp = temp->next;
    }
    temp->next = (struct node*)malloc(sizeof(struct node));
    temp->next->data = data;
    temp->next->prev = temp;
    temp->next->next = start;
    start->prev = temp->next;
}

//to print the list from start to end
void printStartToEnd(struct node *start){
    struct node *temp = start;
    printf("\n-----------------------------------------------PRINT LIST-----------------------------------");
    printf("\nData %d",temp->data);
    temp = temp->next;
    while (temp != start){
        printf("\nData %d",temp->data);
        temp = temp->next;
    }
}

//To print the list from end to start
void printEndToStart(struct node *start){
    struct node *temp = start;
    while (temp->next != start){
        temp = temp->next;
    }
    printf("\n-----------------------------------------------PRINT LIST-----------------------------------");
    while (temp != start){
        printf("\nData :%d",temp->data);
        temp = temp->prev;
    }
    printf("\nData :%d",temp->data);
}

//The main function
int main(){
    struct node *head = NULL;
    push(&head,10);
    add(head,20),

    printStartToEnd(head);
}

