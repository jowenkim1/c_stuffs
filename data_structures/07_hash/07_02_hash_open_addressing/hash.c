#include <assert.h>
#include <stdlib.h>
#include "hash.h"

bool hash_oa_init(HashOpenAddressing *table, size_t capacity)
{
    if (table == NULL)
    {
        return false;
    }
    table->entries = malloc(sizeof(HashOAEntry) * capacity);
    if (table->entries == NULL)
    {
        return false;
    }

    for (size_t i = 0; i < capacity; i++)
    {
        table->entries[i].state = HASH_OA_EMPTY;
    }

    table->capacity = capacity;
    table->size = 0;
    return true;
}

void hash_oa_destroy(HashOpenAddressing *table)
{
    if (table == NULL)
    {
        return;
    }
    free(table->entries);
    table->entries = NULL;
    table->capacity = 0;
    table->size = 0;
}

size_t hash_oa_size(const HashOpenAddressing *table)
{
    assert(table != NULL);
    return table->size;
}

bool hash_oa_is_empty(const HashOpenAddressing *table)
{
    assert(table != NULL);
    return table->size == 0;
}

bool hash_oa_insert(HashOpenAddressing *table,
                    hash_oa_key_t key,
                    hash_oa_value_t value)
{
    if (table == NULL || table->entries == NULL || table->capacity == 0)
    {
        return false;
    }

    size_t cap = table->capacity;
    size_t h = hash_oa_index(key, cap);

    // DELETED 슬롯을 발견하면 "최초 DELETED"를 기억해뒀다가
    // 나중에 EMPTY를 만나면 그 자리에 넣는 게 일반적(클러스터 완화)
    size_t first_deleted = (size_t)-1;

    for (size_t i = 0; i < cap; i++)
    {
        size_t idx = probe_linear(h, i, cap);
        HashOAEntry *e = &table->entries[idx];

        if (e->state == HASH_OA_OCCUPIED)
        {
            if (e->key == key)
            {
                // key 이미 존재 → update
                e->value = value;
                return true;
            }
            // 다른 키면 계속 probe
            continue;
        }

        if (e->state == HASH_OA_DELETED)
        {
            // 일단 후보로만 저장하고 계속 탐색(동일 key가 뒤에 있을 수도)
            if (first_deleted == (size_t)-1)
            {
                first_deleted = idx;
            }
            continue;
        }

        // OA_EMPTY
        // 여기서 삽입 확정: first_deleted가 있으면 거기에, 아니면 여기
        size_t target = (first_deleted != (size_t)-1) ? first_deleted : idx;
        table->entries[target].key = key;
        table->entries[target].value = value;
        table->entries[target].state = HASH_OA_OCCUPIED;
        table->size += 1;
        return true;
    }

    // cap번 probe해도 못 찾으면 full(또는 리사이즈 필요)
    return false;
}
bool hash_oa_find(const HashOpenAddressing *table,
                  hash_oa_key_t key,
                  hash_oa_value_t *out_value)
{
    if (table == NULL || table->entries == NULL || table->capacity == 0 || out_value == NULL)
    {
        return false;
    }

    size_t cap = table->capacity;
    size_t h = hash_oa_index(key, cap);

    for (size_t i = 0; i < cap; i++)
    {
        size_t idx = probe_linear(h, i, cap);
        const HashOAEntry *e = &table->entries[idx];

        if (e->state == HASH_OA_EMPTY)
        {
            // 탐색 사슬 끝: 이 뒤로는 절대 해당 key가 없다
            return false;
        }
        if (e->state == HASH_OA_OCCUPIED && e->key == key)
        {
            *out_value = e->value;
            return true;
        }
        // OA_DELETED 또는 OCCUPIED(다른 키) → 계속 탐색
    }

    return false;
}
bool hash_oa_remove(HashOpenAddressing *table,
                    hash_oa_key_t key,
                    hash_oa_value_t *out_value)
{
    if (table == NULL || table->entries == NULL || table->capacity == 0 || out_value == NULL)
    {
        return false;
    }

    size_t cap = table->capacity;
    size_t h = hash_oa_index(key, cap);

    for (size_t i = 0; i < cap; i++)
    {
        size_t idx = probe_linear(h, i, cap);
        HashOAEntry *e = &table->entries[idx];

        if (e->state == HASH_OA_EMPTY)
        {
            // 여기서 끝 (없음)
            return false;
        }
        if (e->state == HASH_OA_OCCUPIED && e->key == key)
        {
            *out_value = e->value;
            e->state = HASH_OA_DELETED; // tombstone
            table->size -= 1;
            return true;
        }
        // DELETED 또는 OCCUPIED(다른 키) → 계속
    }

    return false;
}
void hash_oa_clear(HashOpenAddressing *table)
{
    if (table == NULL || table->entries == NULL)
    {
        return;
    }

    for (size_t i = 0; i < table->capacity; i++)
    {
        table->entries[i].state = HASH_OA_EMPTY;
        // key/value는 굳이 초기화 안 해도 됨
    }

    table->size = 0;
}
