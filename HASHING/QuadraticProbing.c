#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {0}; // Initialize all elements to 0

void insert() {
    int key, index, i, hkey;
    printf("\nEnter a value to insert into the hash table: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i * i) % TABLE_SIZE; // Quadratic probing
        if (h[index] == 0) 
{ 
            h[index] = key;
            break;
        }
    }
    if (i == TABLE_SIZE)
        printf("\nElement cannot be inserted\n");
}

void display() {
    int i;
    printf("\nElements in the hash table are:\n");
    for (i = 0; i < TABLE_SIZE; i++)
        printf("At index %d: Value = %d\n", i, h[i]);
}

int main() {
    int opt;
    while (1) {
        printf("\nPress 1. Insert\t 2. Display \t3. Exit\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}
