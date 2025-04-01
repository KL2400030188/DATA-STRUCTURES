#include <stdio.h>
#include <stdlib.h>

#define TableSize 15

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* hashTable[TableSize] = {NULL};  // Initialize hash table with NULL

int hashFunction(int key) {
    return key % TableSize;
}

void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
    printf("%d inserted at index %d\n", key, index);
}

int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            return 1;  // Key found
        }
        temp = temp->next;
    }
    return 0;  // Key not found
}

void printTable() {
    for (int i = 0; i < TableSize; i++) {
        printf("%d: ", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;

    while (1) {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Print Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(key))
                    printf("%d found in the hash table.\n", key);
                else
                    printf("%d not found in the hash table.\n", key);
                break;
            case 3:
                printTable();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

