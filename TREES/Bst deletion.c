//Bst deletion all cases

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Find the minimum value node in a subtree
struct Node* findMinNode(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    // Traverse the tree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node to be deleted found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node* temp = findMinNode(root->right); // Inorder successor
        root->data = temp->data;                      // Replace with successor
        root->right = deleteNode(root->right, temp->data); // Delete successor
    }
    return root;
}

// Main driver
int main() {
    struct Node* root = NULL;
    int n, value, del;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nBST Inorder before deletion: ");
    inorder(root);
    printf("\n");

    printf("Enter value to delete: ");
    scanf("%d", &del);
    root = deleteNode(root, del);

    printf("\nBST Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
