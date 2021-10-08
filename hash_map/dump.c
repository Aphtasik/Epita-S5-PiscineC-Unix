#include <stddef.h>
#include <stdio.h>

#include "hash_map.h"

void hash_map_dump(struct hash_map *hash_map)
{
    if (hash_map)
    {
        for (size_t i = 0; i < hash_map->size; i++)
        {
            struct pair_list *pair = hash_map->data[i];
            if (!pair)
            {
                continue;
            }
            printf("%s: %s", pair->key, pair->value);
            while (pair->next)
            {
                pair = pair->next;
                printf("%s: %s", pair->key, pair->value);
            }
            printf("\n");
        }
    }
}
