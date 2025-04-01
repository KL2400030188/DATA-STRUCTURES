#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int data) 
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to find the minimum value node
struct Node* findmin(struct Node* root) 
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to find the maximum value node
struct Node* findmax(struct Node* root) 
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Function to search an element in BST
struct Node* search(struct Node* root, int key) 
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
}

// Function for inorder traversal (sorted order)
void inorder(struct Node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void freeBST(struct Node* root) 
{
    if (root != NULL) 
    {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}
// Main function
int main() 
{
    struct Node* root = NULL;
    int choice, value, key;

    while (1) {
        printf("\nBST Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Inorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Node %d found in BST.\n", key);
                else
                    printf("Node %d not found in BST.\n", key);
                break;
            case 3:
                if (root) 
                    printf("Minimum value: %d\n", findmin(root)->data);
                else
                    printf("BST is empty.\n");
                break;
            case 4:
                if (root)
                    printf("Maximum value: %d\n", findmax(root)->data);
                else
                    printf("BST is empty.\n");
                break;
            case 5:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                freeBST(root);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
