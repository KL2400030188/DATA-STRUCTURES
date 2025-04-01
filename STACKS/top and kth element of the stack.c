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

// Function to get the top element of the stack
int getTop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function to get the kth element from the top
int getKthElement(Stack *s, int k) {
    if (k > s->top + 1 || k <= 0) {
        printf("Invalid value of k\n");
        return -1;
    }
    return s->arr[s->top - k + 1];
}

// Driver code
int main() {
    Stack s;
    initStack(&s);

    int n, value, k;
    
    // Read number of elements
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&s, value);
    }

    // Read k value
    printf("Enter the value of k to find the kth element from top: ");
    scanf("%d", &k);

    // Display results
    printf("Top element: %d\n", getTop(&s));
    printf("%dth element from top: %d\n", k, getKthElement(&s, k));

    return 0;
}
