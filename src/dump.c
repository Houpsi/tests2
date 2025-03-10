/*
** EPITECH PROJECT, 2023
** secured
** File description:
** dump function: display the state of the hash table
*/
/*!
 * @file dump.c
 * display the state of the hash table
 */
#include "my.h"

/*!
 * display the element in the linked list
 * @param current linked list
 */
void foo(const linked_list_t *current)
{
    if (current->values != NULL) {
        mini_printf("> %d - %s\n", current->int_hash,
            current->values);
    }
}

/*!
 * display the elements of the structure
 * @param ht structure
 */
void ht_dump(hashtable_t *ht)
{
    linked_list_t *current = NULL;

    if (ht == NULL || ht->array == NULL) {
        return;
    }
    for (int i = 0; i < ht->len; i++) {
        current = ht->array[i];
        mini_printf("[%d]:\n", i);
        while (current) {
            foo(current);
            current = current->next;
        }
    }
}
