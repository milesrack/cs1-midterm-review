#include <stdio.h>
#define MAX 10

void enqueue(int val);
int dequeue();
int empty();
int full();
void print();

int queue[MAX];
int front = -1;
int rear = -1;

int main(){
    for (int i = 0; i < MAX; i++){
        enqueue(i);
        print();
    }
    enqueue(MAX);
    for (int i = 0; i < MAX; i++){
        dequeue();
    }
    dequeue();
    return 0;
}

void enqueue(int val){
    if (full()){
        printf("Queue is full!\n");
        return;
    }
    if (empty()){
        front = 0;
    }
    queue[++rear] = val;
}

int dequeue(){
    if (empty() || front > rear){
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front++];
}

int empty(){
    if (front == -1){
        return 1;
    }
    return 0;
}

int full(){
    if (rear == MAX - 1){
        return 1;
    }
    return 0;
}

void print(){
    if (empty()){
        printf("Queue is empty!\n");
        return;
    }
    for (int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}