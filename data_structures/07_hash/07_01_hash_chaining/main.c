#include <stdio.h>

#include "hash.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  HashChaining table;
  CHECK(hash_chaining_init(&table, 8), "init");

  hash_chaining_value_t value = 0;
  CHECK(!hash_chaining_find(&table, 1, &value), "find empty");
  CHECK(!hash_chaining_remove(&table, 1, &value), "remove empty");

  CHECK(hash_chaining_insert(&table, 1, 100), "insert 1");
  CHECK(hash_chaining_insert(&table, 9, 900), "insert 9");
  CHECK(hash_chaining_insert(&table, 1, 111), "update 1");

  CHECK(hash_chaining_find(&table, 1, &value) && value == 111, "find updated");

  CHECK(hash_chaining_remove(&table, 1, &value) && value == 111, "remove 1");
  CHECK(hash_chaining_size(&table) == 1, "size after remove");

  hash_chaining_clear(&table);
  CHECK(hash_chaining_is_empty(&table) == true, "clear empty");

  hash_chaining_destroy(&table);
  printf("hash_chaining ok\n");
  return 0;
}
