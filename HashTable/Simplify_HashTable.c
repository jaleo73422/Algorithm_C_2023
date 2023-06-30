#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// modify: put into function
#define INITIAL_CAPACITY 16

typedef struct {
    const char* key;
    void* value;
} ht_entry;

typedef struct {
    ht_entry* entries;
    size_t capacity;
    size_t length;
} ht;

ht* ht_create() {
    ht* table = (ht*) malloc(sizeof(ht));
    table -> length = 0;
    table -> capacity = INITIAL_CAPACITY;
    table -> entries = calloc(table -> capacity, sizeof(ht_entry));
    return table;
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Hash function
static uint64_t hash_key(const char* key) {
    uint64_t hash = FNV_OFFSET;
    const char* p = key;
    hash ^= (uint64_t) (unsigned char) (*p);
    hash *= FNV_PRIME;
    return hash;
}

void* ht_get(ht* table, const char* key) {
    uint64_t hash = hash_key(key);
    size_t index = (size_t) (hash & (uint64_t)(table -> capacity - 1));

    while(table -> entries[index].key != NULL) {
        if(strcmp(key, table -> entries[index].key) == 0)
            return table -> entries[index].value;

        index++;
        if(index >= table -> capacity)
            index = 0;
    }
    return NULL;
}

static const char* ht_set_entry(ht_entry* entries, size_t capacity, const char* key, void* value, size_t* plength) {
    uint64_t hash = hash_key(key);
    size_t index = (size_t) (hash & (uint64_t)(capacity - 1));

    while(entries[index].key != NULL) {
        if(strcmp(key, entries[index].key) == 0) {
            entries[index].value = value;
            return entries[index].key;
        }
        index++;
        if(index >= capacity)
            index = 0;
    }

    if(plength != NULL) {
        key = strdup(key);
        (*plength)++;
    }
    entries[index].key = (char*) key;
    entries[index].value = value;
    return key;
}

static bool ht_expand(ht* table) {
    size_t new_capacity = table -> capacity * 2;

    ht_entry* new_entries = calloc(new_capacity, sizeof(ht_entry));

    for(size_t i = 0; i < table -> capacity; i++) {
        ht_entry entry = table -> entries[i];
        if(entry.key != NULL)
            ht_set_entry(new_entries, new_capacity, entry.key, entry.value, NULL);
    }

    free(table -> entries);
    table -> entries = new_entries;
    table -> capacity = new_capacity;
    return true;
}

const char* ht_set(ht* table, const char* key, void* value) {
    if(table -> length >= table -> capacity / 2)
        if(!ht_expand(table))  return NULL;

    return ht_set_entry(table -> entries, table -> capacity, key, value, &table -> length);
}

void main() {
    ht* table = ht_create();
    char* key = malloc(sizeof(int));
    sprintf(key, "%d", 1);
    int* value = malloc(sizeof(int));
    *value = 2;
    int tem_key;

    ht_set(table, key, value);
    *value = *value + 1;
    ht_set(table, key, value);

    // // printf("%d ", *(int*) ht_get(table, key));
    // // printf("== ");
    printf("%d \n", (int) table -> length);
    printf("%d \n", (int) table -> capacity);
    
    
    printf("== \n");
    
    // *key = (*key) + 1;
    // key = "2";
    tem_key = 2;
    sprintf(key, "%d", tem_key);
    // printf("--%s--/\n", key);
    *value = *value + 1;
    ht_set(table, key, value);

    tem_key++;
    sprintf(key, "%d", tem_key);
    // *key = (*key) + 1;
    *value = *value + 1;
    ht_set(table, key, value);

    tem_key++;
    sprintf(key, "%d", tem_key);
    // *key = (*key) + 1;
    *value = *value + 1;
    ht_set(table, key, value);

    tem_key++;
    sprintf(key, "%d", tem_key);
    // *key = (*key) + 1;
    *value = *value + 1;
    ht_set(table, key, value);

    tem_key++;
    sprintf(key, "%d", tem_key);
    // *key = (*key) + 1;
    *value = *value + 1;
    ht_set(table, key, value);

    tem_key++;
    sprintf(key, "%d", tem_key);
    // *key = (*key) + 1;
    *value = *value + 1;
    ht_set(table, key, value);

    tem_key++;
    sprintf(key, "%d", tem_key);
    // *key = (*key) + 1;
    *value = *value + 1;
    ht_set(table, key, value);

    tem_key++;
    sprintf(key, "%d", tem_key);
    // *key = (*key) + 1;
    *value = *value + 1;
    ht_set(table, key, value);

    printf("%d \n", (int) table -> length);
    printf("%d \n", (int) table -> capacity);
}