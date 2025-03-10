/*
** EPITECH PROJECT, 2023
** secured
** File description:
** search
*/

/*!
 * @file search.c
 * all function for ht_search
 */
#include "../hashtable/hashtable.h"
#include "my.h"
#include <string.h>

/*!
 *function which compares if it is the correct key and if yes it returns
 * the correct associated value, otherwise it returns NULL
 * @param current linked_list_t, linked list in which to search
 * @param key  key we want to search and compare
 * @return retrun char * if it is good key, else NULL
 */
char *display_s(int i, char *key, hashtable_t *ht, char **result)
{
    linked_list_t *current = NULL;

    current = ht->array[i];
    while (current) {
        if (my_strcmp(current->key_s, key) == 0) {
            *result = current->values;
        }
        current = current->next;
    }
    return *result;
}

/*!
 * function that searches for the given key in the hash table and retrun value
 * @param ht hashtable_t, hash_table
 * @param key char *, key we want to search
 * @return char *, the value which is associated with the searched key
 */
char *ht_search(hashtable_t *ht, char *key)
{
    char *result = NULL;

    if (ht == NULL || key == NULL) {
        return NULL;
    }
    for (int i = 0; i < ht->len; ++i) {
        if (display_s(i, key, ht, &result) != NULL) {
            return result;
        }
    }
    return NULL;
}
