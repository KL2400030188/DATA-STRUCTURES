#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void enqueue();
void dequeue();
void display();
int a[SIZE];
int rear = -1;
int front = -1;

int main() {
    int opt;
    while (1) {
        printf("\n1: enqueue");
        printf("\n2: dequeue");
        printf("\n3: display");
        printf("\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid opt");
        }
    }
}

void enqueue() {
    int ele;
    if (rear == SIZE - 1)
        printf("\nQueue is full");
    else {
        if (front == -1) {
            front = 0;
        }
        printf("Enter element to be inserted: ");
        scanf("%d", &ele);
        rear = rear + 1;
        a[rear] = ele;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("\nQueue is empty");
    else {
        printf("Element deleted from queue is %d\n", a[front]);
        front = front + 1;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty");
    } else {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", a[i]);
        }
    }
}
