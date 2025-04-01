#include <stdio.h>

#define MAX 100  // Define the maximum stack size

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

// Function to calculate the average value of stack elements
double calculateAverage(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, average cannot be calculated.\n");
        return 0;
    }
    
    int sum = 0;
    for (int i = 0; i <= s->top; i++) {
        sum += s->arr[i];
    }
    
    return (double)sum / (s->top + 1);
}

// Driver code
int main() {
    Stack s;
    initStack(&s);

    // Pushing elements into the stack
    push(&s, 6);
    push(&s, 4);
    push(&s, 2);
    push(&s, 5);
    push(&s, 3);
    push(&s, 1);

    // Calculating and printing the average
    printf("Elements of the stack: 6 4 2 5 3 1\n");
    printf("Average of the said stack values: %.2f\n", calculateAverage(&s));

    return 0;
}
