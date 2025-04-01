#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the end of the linked list
void append(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to check if the linked list is a palindrome using a stack
int isPalindrome(Node* head) {
    if (!head) return 1;  // Empty list is a palindrome

    Node* slow = head, *fast = head;
    Node* stack[1000];  // Stack to store first half
    int top = -1;

    // Push first half of elements onto the stack
    while (fast && fast->next) {
        stack[++top] = slow;  // Push node onto the stack
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the linked list has an odd number of elements, skip the middle element
    if (fast) {
        slow = slow->next;
    }

    // Compare second half of the list with stack
    while (slow) {
        if (stack[top--]->data != slow->data) {
            return 0;  // Not a palindrome
        }
        slow = slow->next;
    }

    return 1;  // Palindrome
}

// Driver code
int main() {
    int n, value;
    Node* head = NULL;

    // Read input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    // Check and print result
    if (isPalindrome(head)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
