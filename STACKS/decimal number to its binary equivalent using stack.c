#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define maximum stack size

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Function to convert decimal to binary using stack
void decimalToBinary(int num) {
    Stack s;
    initStack(&s);

    if (num == 0) {
        printf("0");
        return;
    }

    // Push remainder of division by 2 onto stack
    while (num > 0) {
        push(&s, num % 2);
        num /= 2;
    }

    // Pop and print elements to get binary representation
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
}

int main() {
    int num;

    // Read decimal input
    printf("Input a decimal number: ");
    scanf("%d", &num);

    // Convert and print binary equivalent
    printf("The binary equivalent is: ");
    decimalToBinary(num);
    printf("\n");

    return 0;
}
