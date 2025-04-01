#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) 
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct node* findMin(struct node* root) 
{
    while (root->left != NULL) 
    {
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root, int data) 
{
    if (root == NULL)
        return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Case 1: Node with no children
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            return NULL;
        }
        // Case 2: Node with one child (right child only)
        else if (root->left == NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        // Case 3: Node with one child (left child only)
        else if (root->right == NULL) 
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 4: Node with two children
        else {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Function to print inorder traversal of the BST
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 17);
    root = insert(root, 6);
    root = insert(root, 19);
    root = insert(root, 43);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 37);
    root = insert(root, 49);

    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 6);

    printf("Inorder traversal after deleting 6: ");
    inorder(root);
    printf("\n");

    return 0;
}
