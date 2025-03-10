/*
** EPITECH PROJECT, 2023
** secured.c
** File description:
** delete function
*/
/*!
 * @file delete.c
 *  file who delete the key of the linked list
 */
#include "my.h"

/*!
 * delete the element
 * @param current linked list, browsed the linked list
 * @param prev linked list, just before the current
 * @return return 0 if we delete an element in the middle and
 * return 1 if the element delete is the first one
 */
int delete(linked_list_t **current, linked_list_t *prev)
{
    linked_list_t *tmp = *current;

    if (prev == NULL) {
        if (tmp->next == NULL) {
            free(tmp);
            *current = NULL;
            return 1;
        }
        *current = (*current)->next;
        free(tmp);
        return 1;
    }
    prev->next = tmp->next;
    free(tmp);
    return 0;
}

/*!
 * put the current a the right place for delete the key
 * @param ht linked list
 * @param key_hash int, key_hash
 * @param prev linked list, just before the current
 * @param current linked list, browsed the linked list
 * @return return 0
 */
int ge_in(hashtable_t *ht, int key_hash, linked_list_t *prev,
    linked_list_t **current)
{
    if (delete(current, prev) == 1)
        ht->array[key_hash] = (*current);
    return 0;
}

/*!
 * browsed the linked list for find the key that we wanted to delete
 * @param ht linked list
 * @param key char *, key we wanted to delete
 * @return return 84 in case of error otherwise return 0
 */
int ht_delete(hashtable_t *ht, char *key)
{
    linked_list_t *prev = NULL;
    linked_list_t *current = NULL;
    int key_hash;

    if (key == NULL || ht == NULL || ht->len <= 0) {
        return 84;
    }
    key_hash = ht->hash(key, ht->len) % ht->len;
    current = ht->array[key_hash];
    while (current) {
        if (my_strcmp(current->key_s, key) == 0) {
            return ge_in(ht, key_hash, prev, &current);
        }
        prev = current;
        current = current->next;
    }
    return 84;
}
