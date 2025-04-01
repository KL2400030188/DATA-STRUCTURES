#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
int hash[TABLE_SIZE]; 
void initialize()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash[i] = -1; 
    }
}
void insert()
{
    int key, hkey, index;
    printf("\nEnter key element: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE; 
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i) % TABLE_SIZE; 
        if (hash[index] == -1) 
        {
            hash[index] = key;
            printf("%d inserted at index %d\n", key, index);
            return;
        }
    }
    printf("Hash table is full, cannot insert %d\n", key);
}
void display()
{
    printf("\nHASHTABLE:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash[i] != -1)
        {
            printf("At index %d: key = %d\n", i, hash[i]);
        }
        else
        {
            printf("Index %d: is empty\n", i);
        }
    }
}
int main()
{
    initialize();
    int choice;
    while (1)
    {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
