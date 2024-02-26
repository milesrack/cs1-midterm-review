#include <stdio.h>
#include <stdlib.h>

void enqueue(int val);
int dequeue();
int empty();
void print();

typedef struct Node{
    int val;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

int main(){
    for (int i = 0; i < 10; i++){
        enqueue(i);
        print();
    }
    for (int i = 0; i < 10; i++){
        dequeue();
        print();
    }
    return 0;
}

void enqueue(int val){
    Node *new = NULL;

    if (empty()){
        front = (Node *) malloc(sizeof(Node));
        front->val = val;
        front->next = NULL;
        rear = front;
        return;
    }
    rear->next = (Node *) malloc(sizeof(Node));
    new = rear->next;
    new->val = val;
    new->next = NULL;
    rear = new;
}

int dequeue(){
    int val;

    if (empty()){
        printf("Queue is empty!\n");
        return -1;
    }

    val = front->val;
    front = front->next;

    return val;
}

int empty(){
    if (front == NULL){
        return 1;
    }
    return 0;
}

void print(){
    Node *cur = front;

    if (empty()){
        printf("Queue is empty!\n");
        return;
    }

    while (cur != NULL){
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}