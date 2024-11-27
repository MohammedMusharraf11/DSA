#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 10

// Define the structure for each hash table entry (node)
typedef struct hashNode {
    int data; // Stores the key value
    int flag; // 0: empty, 1: occupied
} HASH_NODE;

// Define the structure for the hash table
typedef struct hashTable {
    int size;         // Size of the hash table
    HASH_NODE *table; // Array of hash nodes
} HASH_TABLE;

// Global variable to track the number of inserted elements
int elementCount = 0;

// Function to create a new hash table
HASH_TABLE *createHashTable(int size) {
    HASH_TABLE *hashTable = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
    if (!hashTable) {
        printf("Memory allocation error for hash table\n");
        exit(1);
    }

    hashTable->size = size;
    hashTable->table = (HASH_NODE *)malloc(size * sizeof(HASH_NODE));
    if (!hashTable->table) {
        printf("Memory allocation error for hash nodes\n");
        exit(1);
    }

    // Initialize all nodes as empty
    for (int i = 0; i < size; i++) {
        hashTable->table[i].flag = 0; // Mark all slots as empty
    }

    return hashTable;
}

// Function to destroy the hash table and free memory
void destroyHashTable(HASH_TABLE *hashTable) {
    free(hashTable->table);
    free(hashTable);
}

// Function to rehash when the load factor exceeds 0.75
void rehash(int key, HASH_TABLE **oldHashTable) {
    int newSize = (*oldHashTable)->size * 2; // Double the size
    HASH_TABLE *newHashTable = createHashTable(newSize);

    // Reinsert existing keys into the new hash table
    for (int i = 0; i < (*oldHashTable)->size; i++) {
        if ((*oldHashTable)->table[i].flag == 1) {
            int hash, j = 0;
            hash = ((*oldHashTable)->table[i].data % newSize + j) % newSize;
            while (newHashTable->table[hash].flag != 0) {
                j++;
                hash = ((*oldHashTable)->table[i].data % newSize + j) % newSize;
            }
            newHashTable->table[hash].data = (*oldHashTable)->table[i].data;
            newHashTable->table[hash].flag = 1;
        }
    }

    // Free memory of the old hash table
    destroyHashTable(*oldHashTable);

    // Update the pointer to the new hash table
    *oldHashTable = newHashTable;
}

// Function to insert a key into the hash table
void insertKey(int key, HASH_TABLE *hashTable) {
    elementCount++;

    // Check if rehashing is needed (load factor > 0.75)
    if (elementCount > (float)(0.75 * hashTable->size)) {
        rehash(key, &hashTable);
    } else {
        int hash, i = 0;
        hash = (key % hashTable->size + i) % hashTable->size;

        // Find the first empty slot
        while (hashTable->table[hash].flag != 0) {
            i++;
            hash = (key % hashTable->size + i) % hashTable->size;
        }

        // Insert the key
        hashTable->table[hash].data = key;
        hashTable->table[hash].flag = 1;

        printf("Inserted key %d at index %d\n", key, hash);
    }
}

// Function to display the contents of the hash table
void displayHashTable(HASH_TABLE *hashTable) {
    printf("\nHash Table:\n");
    for (int i = 0; i < hashTable->size; i++) {
        if (hashTable->table[i].flag == 1) {
            printf("Index %d: %d\n", i, hashTable->table[i].data);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
    printf("\n");
}

// Function to search for a key in the hash table
void searchKey(int key, HASH_TABLE *hashTable) {
    int hash, i = 0;
    hash = (key % hashTable->size + i) % hashTable->size;

    // Search through the table
    while (i < hashTable->size) {
        if (hashTable->table[hash].data == key && hashTable->table[hash].flag == 1) {
            printf("\nKey %d found at index %d\n", key, hash);
            return;
        }
        i++;
        hash = (key % hashTable->size + i) % hashTable->size;
    }

    printf("\nKey %d not found\n", key);
}

int main() {
    // Create a hash table with initial size
    HASH_TABLE *hashTable = createHashTable(HASH_TABLE_SIZE);

    // Insert keys into the hash table
    insertKey(5, hashTable);
    insertKey(15, hashTable);
    insertKey(25, hashTable);
    insertKey(35, hashTable);

    // Display the hash table
    displayHashTable(hashTable);

    // Search for keys in the hash table
    searchKey(15, hashTable); // Key found
    searchKey(35, hashTable); // Key found
    searchKey(45, hashTable); // Key not found

    // Free the hash table memory
    destroyHashTable(hashTable);

    return 0;
}
