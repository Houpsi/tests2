/*
** EPITECH PROJECT, 2023
** secured
** File description:
** insert function
*/

/*!
 * @file fct_insert.c
 * all functon for insert
 */
#include "../hashtable/hashtable.h"
#include "my.h"

int compare_equal(hashtable_t *ht, int i, char *key, char *value)
{
    int key_hash = ht->hash(key, ht->len);
    linked_list_t *current = NULL;

    current = ht->array[i];
    for (; current != NULL; current = current->next) {
        if (my_strcmp(ht->array[i]->key_s, key) == 0) {
            ht->array[i]->values = value;
            ht->array[i]->int_hash = key_hash;
            return 0;
        }
    }
    return 1;
}

int search_double(hashtable_t *ht, char *key, char *value)
{
    for (int i = 0; i < ht->len; ++i) {
        if (compare_equal(ht, i, key, value) == 0)
            return 0;
    }
    return 1;
}

/*!
 *function that adds data to the start of a linked list
 * @param begin linked_list_t, the linked list in which we want to add data
 * @param key char *, key we want to add
 * @param value char *, the value we want associated with the key
 * @param key_hash int, key hash
 */
void push_to_list(linked_list_t **begin, char *key, char *value, int key_hash)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->key_s = key;
    new->int_hash = key_hash;
    new->values = value;
    new->next = *begin;
    *begin = new;
}

/*!
 * function that adds data into the hash table,
 * the key is hash then added to the index of hash_table with its value
 * @param ht hashtable_t, hash_table
 * @param key char *, the key we want to hash
 * @param value the value we want associated with the key
 * @return int, retrun 84 if there is an error or 0 if it works
 */
int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int key_hash;
    int index;

    if (key == NULL || value == NULL || ht == NULL || ht->len <= 0)
        return 84;
    key_hash = ht->hash(key, ht->len);
    index = key_hash % (ht->len);
    if (index > ht->len)
        return 84;
    if (search_double(ht, key, value) == 0)
        return 0;
    push_to_list(&(ht->array[index]), key, value, key_hash);
    return 0;
}
