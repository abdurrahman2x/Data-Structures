#include <stdio.h>
#include <stdlib.h>


//Create new struct
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

//to push first node
void push(struct node **start,int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    (*start) = temp;
}

//To add new node
void add(struct node *start,int data){
    struct node *newNode,*temp;
    temp = start;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

//print the list strating the first node to end
void printStartToEnd(struct node *start){
    struct node *temp = start;
    printf("\n------------------------------Print List Start To End------------------------------");
    while (temp != NULL){
        printf("\nData %d",temp->data);
        temp = temp->next;
    }

}

//print the list starting from end to first
void printEndToStart(struct node *start){
    struct node *temp = start;
    printf("\n------------------------------Print List End To Start------------------------------");
    while (temp->next != NULL){
        temp = temp->next;
    }
    while (temp != NULL){
        printf("\nData :%d",temp->data);
        temp = temp->prev;
    }
}

//delete the node wich its data is deletedData
void delete(struct node **start,int deletedData) {
    struct node *temp = (*start);
    struct node *delete;
    if (temp->data == deletedData) {
        delete = temp;
        temp->next->prev = NULL;
        (*start) = temp->next;
    } else {
        while (temp != NULL) {
            if (temp->data == deletedData) {
                if (temp->next != NULL) {
                    delete = temp;
                    temp->prev = temp->next->prev;
                    temp->prev->next = temp->next;
                    free(delete);
                    break;
                } else {
                    delete = temp;
                    temp->prev->next = NULL;
                    free(temp);
                    break;
                }
            }
            temp = temp->next;
        }
    }
}

//the main function
int main() {
    struct node *start = NULL;

    push(&start,10);

    add(start,20);
    add(start,30);
    add(start,40);
    add(start,50);


    printStartToEnd(start);

    printEndToStart(start);

    delete(&start,50);

    printStartToEnd(start);

    delete(&start,10);


    printEndToStart(start);

    delete(&start,40);

    printEndToStart(start);

    printStartToEnd(start);

    printEndToStart(start);

    printStartToEnd(start);






    return 0;
}

