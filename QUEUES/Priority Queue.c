#include <stdio.h>

#define MAX 10

typedef struct {
    int value;
    int prior;
} element;

element pq[MAX];
int size = 0;

void enqueue(int value, int prior) {
    if (size == MAX) {
        printf("Queue is full\n");
        return;
    }
    pq[size].value = value;
    pq[size].prior = prior;
    size++;
}

void dequeue() {
    if (size == 0) {
        printf("Priority queue is empty\n");
        return;
    }
    int highestPriorityIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].prior > pq[highestPriorityIndex].prior) {
            highestPriorityIndex = i;
        }
    }
    printf("Dequeued element: %d with priority %d\n", pq[highestPriorityIndex].value, pq[highestPriorityIndex].prior);
    for (int i = highestPriorityIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    if (size == 0) {
        printf("Priority queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Priority: %d\n", pq[i].value, pq[i].prior);
    }
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    
    display();
    
    dequeue();
    display();
    
    return 0;
}
