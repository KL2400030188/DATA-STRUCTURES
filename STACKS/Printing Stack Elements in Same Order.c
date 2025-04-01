#include <stdio.h>
#define MAX 100  

typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// Function to print stack elements in the order they were inserted
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    Stack s;
    initStack(&s);

    // Pushing elements into stack
    push(&s, 5);
    push(&s, 2);
    push(&s, 1);
    push(&s, 6);
    push(&s, 8);

    // Printing stack elements in insertion order
    printf("Current stack elements:\n");
    printStack(&s);

    return 0;
}
