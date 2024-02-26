#include <stdio.h>
#include <string.h>
#define MAX 100

void push(int val);
int pop();
int isEmpty();
int isFull();
int evalPostfix();
int power(int x, int y);

int stack[MAX];
char postfix[MAX];
int top = -1;

int main(){
    printf("Enter postfix expression: ");
    fgets(postfix, 99, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';
    printf("%d\n", evalPostfix());
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

int evalPostfix(){
    char symbol;
    int x,y;

    for (int i = 0; i < strlen(postfix); i++){
        symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9'){
            push(symbol - '0');
        }
        else{
            y = pop();
            x = pop();
            switch (symbol){
                case '^':
                    push(power(x,y));
                    break;
                case '*':
                    push(x*y);
                    break;
                case '/':
                    push(x/y);
                    break;
                case '+':
                    push(x+y);
                    break;
                case '-':
                    push(x-y);
                    break;
            }
        }
    }

    return pop();
}

int power(int x, int y){
    if (y == 0){
        return 1;
    }
    return x * power(x,y-1);
}