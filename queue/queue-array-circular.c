#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int size = 0;

void enqueue(int val);
int dequeue();
int empty();
int full();
void print();

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
    for (int i = 0; i < MAX; i++){
        enqueue(i);
        print();
    }
    enqueue(MAX);
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
    
    queue[(front + size) % MAX] = val;
    size++;
}

int dequeue(){
    int val;

    if (empty()){
        printf("Queue is empty!\n");
        return -1;
    }

    val = queue[front];
    front = (front + 1) % MAX;
    size--;
    
    return val;
}

int empty(){
    if (size == 0){
        return 1;
    }
    return 0;
}

int full(){
    if (size == MAX){
        return 1;
    }
    return 0;
}

void print(){
    if (empty()){
        printf("Queue is empty!\n");
        return;
    }
    for (int i = 0; i < size; i++){
        printf("%d ", queue[(front + i) % MAX]);
    }
    printf("\n");
}