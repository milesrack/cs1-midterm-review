#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int val);
int pop();
int isEmpty();
void print();

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    print();
    pop();
    pop();
    print();
    push(5);
    print();
    return 0;
}

void push(int val){
    if (isEmpty()){
        top = (Node *) malloc(sizeof(Node));
        if (top == NULL){
            printf("malloc() failed!\n");
            exit(1);
        }
        top->val = val;
        top->next = NULL;
    }
    else{
        Node *newNode = (Node *) malloc(sizeof(Node));
        if (newNode == NULL){
            printf("malloc() failed!\n");
            exit(1);
        }
        newNode->val = val;
        newNode->next = top;
        top = newNode;
    }
}

int pop(){
    Node *deletedNode = NULL;
    int retval = 0;

    if (isEmpty()){
        printf("Stack is empty!\n");
        exit(1);
    }
    
    deletedNode = top;
    retval = deletedNode->val;
    top = top->next;
    free(deletedNode);

    return retval;
}

int isEmpty(){
    if (top == NULL){
        return 1;
    }
    return 0;
}

void print(){
    Node *cur = top;

    if (!isEmpty()){
        while (cur != NULL){
            printf("%d ", cur->val);
            cur = cur->next;
        }
        printf("\n");
    }
}