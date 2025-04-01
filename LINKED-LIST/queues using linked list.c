#include <stdio.h>
#include <stdlib.h>
struct Queue 
{
    int n;
    struct Queue *next;
};
struct Queue *front = NULL, *rear = NULL;
void Enqueue() 
{
    struct Queue *newnode = (struct Queue*)malloc(sizeof(struct Queue)); 
    if (newnode == NULL) 
	{
        printf("Memory allocation failed\n");
        return;
    }  
    printf("Enter n: ");
    scanf("%d", &newnode->n);
    newnode->next = NULL;
    if (front == NULL && rear == NULL) 
	{
        front = rear = newnode;
    } else 
	{
        rear->next = newnode;
        rear = newnode;
    }
}
void Dequeue() 
{
    if (front == NULL) 
	{
        printf("Queue is empty, cannot delete\n");
        return;
    }   
    struct Queue *ptr = front;
    front = front->next;
    
    if (front == NULL) 
	{ 
        rear = NULL;
    }    
    printf("Deleted element: %d\n", ptr->n);
    free(ptr);
}
void Display() 
{
    if (front == NULL) 
	{
        printf("Queue is empty\n");
        return;
    }
    struct Queue *ptr = front;
    printf("Queue elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->n);
        ptr = ptr->next;
    }
    printf("\n");
}
int main() 
{
    int choice;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
		{
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }  
    return 0;
}
