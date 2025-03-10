/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hash_table
*/
/*!
 * @file hashrable.c
 * file to create hashtable
 */
#include "../hashtable/hashtable.h"

/*!
 * function which creates a hashtable, that is to say an array (
 * size given by len) of empty linked list.
 * @param hash function hash, take a number and retrun a index of this number
 * in hash_table
 * @param len size of hashtable
 * @return  hashtable = array of lineked_list
 */
hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *new = malloc(sizeof(hashtable_t));

    if (new == NULL || hash == NULL || len <= 0) {
        return NULL;
    }
    new->array = malloc(sizeof(linked_list_t) * len);
    if (new->array == NULL)
        return NULL;
    for (int i = 0; i < len; ++i) {
        new->array[i] = NULL;
    }
    new->hash = hash;
    new->len = len;
    return new;
}
