#include <stdio.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push(int val);
int pop();
int isEmpty();
int isFull();
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
    if (isFull()){
        printf("Stack is full!\n");
        return;
    }
    stack[++top] = val;
}

int pop(){
    if (isEmpty()){
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty(){
    if (top == -1){
        return 1;
    }
    return 0;
}

int isFull(){
    if (top == MAX - 1){
        return 1;
    }
    return 0;
}

void print(){
    if (isEmpty()){
        printf("Stack is empty!\n");
        return;
    }
    for (int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}