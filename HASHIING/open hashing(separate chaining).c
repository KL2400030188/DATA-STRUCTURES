#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE]; 

int hashFunction(int key) 
{
    return key % TABLE_SIZE;
}

void insert() 
{
    int key, index;
    printf("\nEnter key to insert: ");
    scanf("%d", &key);
    index = hashFunction(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = NULL;
    if (hashTable[index] == NULL) 
    {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    printf("%d inserted at index %d\n", key, index);
}

void display() 
{
    printf("\nHASHTABLE:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void search() 
{
    int key, index;
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    index = hashFunction(key);

    Node* temp = hashTable[index];
    while (temp) {
        if (temp->data == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in the hash table\n", key);
}

// Function to free memory before exiting
void freeMemory() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
}

int main() 
{
    int choice;
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        hashTable[i] = NULL;
    }

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                freeMemory();
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
