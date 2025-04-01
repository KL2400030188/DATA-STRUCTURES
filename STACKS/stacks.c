#include <stdio.h>
#define SIZE 5

int a[SIZE];
int top = -1;

void push() 
{
    int ele;
    if (top == SIZE - 1) {
        printf("Stack is full\n");
    } else {
        printf("Enter element to be inserted: ");
        scanf("%d", &ele);
        top = top + 1;
        a[top] = ele;
        printf("%d is inserted at %d\n", ele, top);
    }
}

void pop() 
{
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("%d is deleted from %d\n", a[top], top);
        top = top - 1;
    }
}

void peek() 
{
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", a[top]);
    }
}

void display() 
{
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int opt;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}

