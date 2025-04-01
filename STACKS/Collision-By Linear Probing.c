#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum possible size of hash table

int main() {
    int N, K;
    scanf("%d", &N);  // Read number of keys
    scanf("%d", &K);  // Read hash table size

    int hashTable[MAX];  // Hash table to store key assignments
    for (int i = 0; i < K; i++) hashTable[i] = -1;  // Initialize hash table (-1 means empty)

    int key;
    for (int i = 0; i < N; i++) {
        scanf("%d", &key);
        int hashIndex = key % K;

        // Linear probing: Find the next available slot
        while (hashTable[hashIndex] != -1) {
            hashIndex = (hashIndex + 1) % K;
        }

        // Store key in the hash table
        hashTable[hashIndex] = key;
        
        // Print the key and resolved hash index
        printf("%d->%d\n", key, hashIndex);
    }

    return 0;
}

