#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node *next;
    struct node *prev;
};
struct node *insert_begin(struct node *start) 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) 
	{
        printf("Memory allocation failed\n");
        return start;
    }

    printf("Enter number: ");
    scanf("%d", &newnode->n);

    newnode->next = start;
    newnode->prev = NULL;

    if (start != NULL) 
	{
        start->prev = newnode;
    }

    start = newnode;

    return start;
}
struct node *insert_end(struct node *start) 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    
    if (newnode == NULL) 
	{
        printf("Memory allocation failed\n");
        return start;
    }

    printf("Enter number: ");
    scanf("%d", &newnode->n);
    newnode->next = NULL;

    if (start == NULL) {
        newnode->prev = NULL;
        return newnode;
    }

    struct node *ptr = start;
    while (ptr->next != NULL) 
	{
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->prev = ptr;

    return start;
}
void display(struct node *start) {
    struct node *temp = start;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->n);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *start = NULL;
    int choice;
    while (1)
	{
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                start = insert_begin(start);
                break;
            case 2:
                start = insert_end(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } 

    return 0;
}
