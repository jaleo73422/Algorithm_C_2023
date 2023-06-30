#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 16  // must not be zero

// Hash table entry (slot may be filled or empty).
typedef struct {
    const char* key;  // key is NULL if this slot is empty
    void* value;
} ht_entry;

// Hash table structure: create with ht_create, free with ht_destroy.
typedef struct {
    ht_entry* entries;  // hash slots
    size_t capacity;    // size of _entries array
    size_t length;      // number of items in hash table
} ht;

// Hash table iterator: create with ht_iterator, iterate with ht_next.
typedef struct {
    const char* key;  // current key
    void* value;      // current value

    // Don't use these fields directly.
    ht* _table;       // reference to hash table being iterated
    size_t _index;    // current index into ht._entries
} hti;

// Create hash table and return pointer to it, or NULL if out of memory.
ht* ht_create() {
    // Allocate space for hash table struct.
    ht* table = (ht*) malloc(sizeof(ht));
    // if (table == NULL)  return NULL;
    table -> length = 0;
    table -> capacity = INITIAL_CAPACITY;

    // Allocate (zero'd) space for entry buckets.
    table -> entries = calloc(table -> capacity, sizeof(ht_entry));
    if(table -> entries == NULL) {
        free(table); // error, free table before we return!
        return NULL;
    }
    return table;
}

// Free memory allocated for the hash table, including allocated keys.
void ht_destroy(ht* table) {
    // First free allocated keys.
    for(size_t i = 0; i < table -> capacity; i++)
        free((void*) table -> entries[i].key);

    // Then free entries array and table itself.
    free(table -> entries);
    free(table);
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-terminated).
// See description:
// https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
// Hash function
static uint64_t hash_key(const char* key) {
    uint64_t hash = FNV_OFFSET;
    for(const char* p = key; *p; p++) {
        hash ^= (uint64_t) (unsigned char) (*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

// Get item with given key (NUL-terminated) from hash table.
// Return value (which was set with ht_set), or NULL if key not found.
void* ht_get(ht* table, const char* key) {
    // AND hash with capacity-1 to ensure it's within the entries array.
    uint64_t hash = hash_key(key);
    size_t index = (size_t) (hash & (uint64_t)(table -> capacity - 1));

    // Loop till we find an empty entry.
    while(table -> entries[index].key != NULL) {
        if(strcmp(key, table -> entries[index].key) == 0)
            // Found key, return value.
            return table -> entries[index].value;

        // Key wasn't in this slot, move to next (linear probing).
        index++;
        if(index >= table -> capacity)
            // At the end of the entries array, wrap around.
            index = 0;
    }
    return NULL;
}

// Internal function to set an entry (without expanding table).
static const char* ht_set_entry(ht_entry* entries, size_t capacity, const char* key, void* value, size_t* plength) {
    // AND hash with capacity-1 to ensure it's within the entries array.
    uint64_t hash = hash_key(key);
    size_t index = (size_t) (hash & (uint64_t)(capacity - 1));

    // Loop till we find an empty entry.
    while(entries[index].key != NULL) {
        if(strcmp(key, entries[index].key) == 0) {
            // Found key (it already exists), update value.
            entries[index].value = value;
            return entries[index].key;
        }
        // Key wasn't in this slot, move to next (linear probing).
        index++;
        if(index >= capacity)
            // At the end of the entries array, wrap around.
            index = 0;
    }

    // Didn't find the key, allocate+copy if needed, then insert it.
    if(plength != NULL) {
        key = strdup(key);
        if(key == NULL)  return NULL;
        (*plength)++;
    }
    entries[index].key = (char*) key;
    entries[index].value = value;
    return key;
}

// Expand the hash table to twice its current size.
// Return true on success, false if out of memory.
static bool ht_expand(ht* table) {
    // Allocate new entries array.
    size_t new_capacity = table -> capacity * 2;
    if(new_capacity < table -> capacity)
        return false;  // overflow (capacity would be too big)

    ht_entry* new_entries = calloc(new_capacity, sizeof(ht_entry));
    if(new_entries == NULL)
        return false;

    // Iterate entries, move all non-empty ones to new table's entries.
    for(size_t i = 0; i < table -> capacity; i++) {
        ht_entry entry = table -> entries[i];
        if(entry.key != NULL)
            ht_set_entry(new_entries, new_capacity, entry.key, entry.value, NULL);
    }

    // Free old entries array and update this table's details.
    free(table -> entries);
    table -> entries = new_entries;
    table -> capacity = new_capacity;
    return true;
}

const char* ht_set(ht* table, const char* key, void* value) {
    assert(value != NULL);
    if(value == NULL)  return NULL;

    // If length exceeds half of the current capacity, expand it.
    if(table -> length >= table -> capacity / 2)
        if(!ht_expand(table))  return NULL;

    // Set entry and update length.
    return ht_set_entry(table -> entries, table -> capacity, key, value, &table -> length);
}

size_t ht_length(ht* table) {
    return table -> length;
}

// Return new hash table iterator (for use with ht_next).
hti ht_iterator(ht* table) {
    hti it;
    it._table = table;
    it._index = 0;
    return it;
}

// Move iterator to next item in hash table,
// update the iterator's key and value to the current item, and return true.
// If there are no more items, return false.
// Don't call ht_set during iteration.
bool ht_next(hti* it) {
    // Loop till we've hit the end of entries array.
    ht* table = it -> _table;
    while(it -> _index < table -> capacity) {
        size_t i = it -> _index;
        it -> _index++;
        if(table -> entries[i].key != NULL) {
            // Find the next non-empty item, update the iterator key and value.
            ht_entry entry = table -> entries[i];
            it -> key = entry.key;
            it -> value = entry.value;
            return true;
        }
    }
    return false;
}

void exit_nomem(void) {
    fprintf(stderr, "out of memory\n");
    exit(1);
}

void main() {
    ht* counts = ht_create();
    if(counts == NULL)  exit_nomem();

    // Read the next word from stdin (at most 100 chars long).
    char word[101];
    while(scanf("%100s", word) != EOF) {
        // Look up words.
        void* value = ht_get(counts, word);
        if(value != NULL) {
            // Already exists, increment int that value points to.
            int* pcount = (int*) value;
            (*pcount)++;
            continue;
        }

        // Word not found, allocate space for new int and set to 1.
        int* pcount = malloc(sizeof(int));
        if(pcount == NULL)  exit_nomem();
        *pcount = 1;
        if(ht_set(counts, word, pcount) == NULL)  exit_nomem();
    }

    // Print out words and frequencies, freeing values as we go.
    hti it = ht_iterator(counts);
    while(ht_next(&it)) {
        printf("%s %d\n", it.key, *(int*) it.value);
        free(it.value);
    }

    // Show the number of unique words.
    printf("%d\n", (int) ht_length(counts));

    ht_destroy(counts);
}