#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char val;
    struct Node *next;
} Node;

Node *top = NULL;

int isBalanced(char expression[]);
void push(char val);
char pop();
int isEmpty();
void freeStack();

int main(){
    char expr1[] = "{([])}(())[[]]";
    char expr2[] = "{([])[}(()))[[]]";
    char expr3[] = "))))";
    char expr4[] = "{{[(()()[][]{}{})]}}";
    printf("%d\n", isBalanced(expr1));
    freeStack();
    printf("%d\n", isBalanced(expr2));
    freeStack();
    printf("%d\n", isBalanced(expr3));
    freeStack();
    printf("%d\n", isBalanced(expr4));
    freeStack();
    return 0;
}

int isBalanced(char expression[]){
    for (int i = 0; i < strlen(expression); i++){
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{'){
            push(c);
        }
        else if (c == ')' && pop() != '('){
            return 0;
        }
        else if (c == ']' && pop() != '['){
            return 0;
        }
        else if (c == '}' && pop() != '{'){
            return 0;
        }
    }
    return isEmpty();
}

void push(char val){
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

char pop(){
    Node *deletedNode = NULL;
    char retval;

    if (isEmpty()){
        return -1;
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

void freeStack(){
    Node *last;
    Node *cur = top;
    while (cur != NULL){
        last = cur;
        cur = cur->next;
        free(last);
    }
    top = NULL;
}