#include <stdbool.h>

#define MAX_HASH_SIZE                                                          \
  2003 // 해쉬테이블의 크기는 실제 자료(문제 기준 500)의 2~4배로 설정하는
       // 것이 충돌회피에 유리함. 그리고 소수로 설정해야 인덱스에 뭉치는 경우가
       // 줄어듦.

// define hash table type
typedef struct {
  int keys[MAX_HASH_SIZE];
  bool used[MAX_HASH_SIZE];
} HashTable;

// 1. calculate hash
int getHash(int key) {
  int hash = key % MAX_HASH_SIZE;
  if (hash < 0) {
    hash += MAX_HASH_SIZE;
  }

  return hash;
}

// 2. add a key to the hash table.
void add(HashTable *hashTable, int key) {
  int hash = getHash(key);

  while (hashTable->used[hash]) {
    if (hashTable->keys[hash] == key) { // already exist
      return;
    }

    hash = (hash + 1) %
           MAX_HASH_SIZE; // it can cause an infinite loop, when the input size
                          // is larger than the maximum hash size.
  }

  hashTable->keys[hash] = key;
  hashTable->used[hash] = true;
}

// 3. check whether the hash table contains a key.
bool hasKey(HashTable *hashTable, int key) {
  int hash = getHash(key);

  while (hashTable->used[hash]) {
    if (hashTable->keys[hash] == key) {
      return true;
    }

    hash = (hash + 1) % MAX_HASH_SIZE;
  }

  return false;
}