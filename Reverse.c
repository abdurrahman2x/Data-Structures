#include <stdio.h>
#include <stdlib.h>

//struct of list
struct node{
    int x;
    struct node *next;
    struct node *prev;
};

//Function to push node
void push(struct node **start,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->x = data;
    temp->next = NULL;
    temp->prev = NULL;
    (*start) = temp;
}
//Function to add new node
void add(struct node *start,int data){
    struct node *temp = start;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = (struct node*)malloc(sizeof(struct node));
    temp->next->x = data;
    temp->next->prev = temp;
    temp->next->next = NULL;
}

//Function to reverse the list
void reverse(struct node **start){
    struct node *temp1 = (*start);
    struct node *temp2;
    int nodeNumber = 0;
   while (temp1 != NULL){
       temp2 = temp1->prev;
       temp1->prev = temp1->next;
       temp1->next = temp2;
       temp1 = temp1->prev;
       if (temp1->next == NULL) {
           temp1->next = temp1->prev;
           temp1->prev = NULL;
           (*start) = temp1;
           break;
       }
   }


}

//Print them
void printList(struct node *start){
    struct node *temp = start;
    while (temp != NULL){
        printf("\nData : %d",temp->x);
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL;

    push(&head,10);
    add(head,20);
    add(head,30);
    add(head,40);
    add(head,50);

    printf("Before Reverse");
    printList(head);
    reverse(&head);
    printf("\nAfter Reverse");
    printList(head);

}

