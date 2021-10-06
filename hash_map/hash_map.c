#include "hash_map.h"

#include <stddef.h>
#include <stdlib.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *new = malloc(sizeof(struct hash_map));
    if (!new)
    {
        return NULL;
    }

    if (size <= 0)
    {
        return NULL;
    }
    new->size = size;

    new->data = malloc(sizeof(struct pair_list*) * size);
    if (!new->data)
    {
        return NULL;
    }
    
    for (size_t i = 0; i < size; i++)
    {
        new->data[i] = NULL;
    }

    return new;
}

void hash_map_free(struct hash_map *hash_map)
{
    for (size_t i = 0; i < hash_map->size; i++)
    {
        if (hash_map->data[i])
        {
            struct pair_list *tmp;
            struct pair_list *p_list = hash_map->data[i];
            while (p_list)
            {
                tmp = p_list->next;
                free(p_list->value);
                free(p_list);
                p_list = tmp;
            }
        }
    }

    if (hash_map->data)
    {
        free(hash_map->data);
    }
    free(hash_map);
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    *updated = false;

    struct pair_list *p_new = malloc(sizeof(struct pair_list));
    if (!p_new)
    {
        return false;
    }

    p_new->key = key;
    p_new->value = value;
    p_new->next = NULL;

    size_t hashed = hash(key) % hash_map->size;

    if (!hash_map->data[hashed])
    {
        hash_map->data[hashed] = p_new;
    }
    else
    {
        struct pair_list *p_list = hash_map->data[hashed];
        for (;p_list->next && !(*updated); p_list = p_list->next)
        {
            if (p_list->key == key)
            {
                p_list->value = value;
                *updated = true;
            }
        }
        
        if (!updated)
        {
            p_new->next = hash_map->data[hashed]->next;
            hash_map->data[hashed] = p_new;
        }
    }
    return true;
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    size_t hashed = hash(key) % hash_map->size;

    if (hash_map->data[hashed])
    {
        struct pair_list *pair = hash_map->data[hashed];
        while (pair)
        {
            if (*pair->key == *key)
            {
                return pair->value;
            }
        }
    }
    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    size_t hashed = hash(key) % hash_map->size;
    if (hash_map->data[hashed])
    {
        if (!hash_map->data[hashed]->next)
        {
            free(hash_map->data[hashed]);
            hash_map->data[hashed] = NULL;
            return true;
        }

        struct pair_list *pair = hash_map->data[hashed];

        while (pair->next)
        {
            if (*pair->key == *key)
            {
                struct pair_list *tmp = pair->next;
                if (pair->next->next)
                {
                    pair->next = pair->next->next;
                    free(tmp);
                }
                else
                {
                    free(pair->next);
                }
                return true;
            }
            pair = pair->next;
        }
    }
    return false;
}

