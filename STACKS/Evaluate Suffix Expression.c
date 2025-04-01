#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack with a given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1;
}

// Function to perform the evaluation of a suffix expression
int evaluateSuffixExpression(char* suffix) {
    struct Stack* stack = createStack(strlen(suffix));
    int i, operand1, operand2, result;

    for (i = 0; suffix[i]; ++i) {
        if (isdigit(suffix[i])) {
            push(stack, suffix[i] - '0'); // Convert char to int
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (suffix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
                case '^':
                    result = (int)pow(operand1, operand2);
                    break;
                default:
                    return -1;
            }

            push(stack, result);
        }
    }

    return pop(stack);
}

int main() {
    int n;
    scanf("%d", &n);
    char suffix[n];
    scanf("%s", suffix);
    int result = evaluateSuffixExpression(suffix);

    printf("%d\n", result);

    return 0;
}

