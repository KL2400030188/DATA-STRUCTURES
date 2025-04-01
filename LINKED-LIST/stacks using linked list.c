#include <stdio.h>
#include <stdlib.h>
struct stack {
    int n;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *top) 
{
    struct stack *newnode = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter number: ");
    scanf("%d", &newnode->n);
    
    if (top == NULL) {
        top = newnode;
        newnode->next = NULL;
    } else {
        newnode->next = top;
        top = newnode;
    }
    return top;
}
struct stack *pop(struct stack *top) 
{
    if (top == NULL) {
        printf("Stack is empty. Cannot delete.\n");
    } else {
        struct stack *ptr = top;
        top = top->next;
        free(ptr);
    }
    return top;
}
void display(struct stack *top) 
{
    struct stack *ptr = top;
    if (ptr == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->n);
        ptr = ptr->next;
    }
    printf("\n");
}
int main() 
{
    int choice;
    while (1) 
	{
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
