#include <stdio.h>
#include <string.h>
#define MAX 100

void push(char val);
char pop();
int isEmpty();
int isFull();
void infixToPostfix();
int precedence(char symbol);

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1;

int main(){
    printf("Enter infix expression: ");
    fgets(infix, 99, stdin);
    infix[strlen(infix)-1] = '\0';
    infixToPostfix();
    printf("%s\n", postfix);
    return 0;
}

void push(char val){
    if (isFull()){
        printf("Stack is full!\n");
        return;
    }
    stack[++top] = val;
}

char pop(){
    if (isEmpty()){
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top--];
}

char peek(){
    if (isEmpty()){
        return -1;
    }
    return stack[top];
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

void infixToPostfix(){
    int j = 0;
    char symbol, c;

    for (int i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        switch (symbol){
            case ' ':
            case '\t':
                break;
            case '(':
                push(symbol);
                break;
            case ')':
                while ((c=pop()) != '('){
                    postfix[j++] = c;
                }
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while (precedence(peek()) >= precedence(symbol)){
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
    }
    
    while (!isEmpty()){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int precedence(char symbol){
    switch (symbol){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}