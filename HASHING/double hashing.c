#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
#define prime 7 // nearest primeno. smaller than table size
int hash[TABLE_SIZE]; 
void initialize()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash[i] = -1; 
    }
}
int h1(int key)
{
	return key%TABLE_SIZE;
}
int h2(int key)
{
	return prime-(key%prime);
}
void insert()
{
    int key,i, hkey1,hkey2, index;
    printf("\nEnter key element: ");
    scanf("%d", &key);
    hkey1 = h1(key);
    hkey2 = h2(key);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey1+i*hkey2)%TABLE_SIZE;
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
