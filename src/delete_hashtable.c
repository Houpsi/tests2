/*
** EPITECH PROJECT, 2023
** secured
** File description:
** delete hashtable
*/

/*!
 * @file delete_hashtable.c
 * file with all function to delete hashtable
 */
#include "../hashtable/hashtable.h"

/*!
 * delete a linked list
 * @param current linked_list
 * @return retrun 0 if linked_list_t is NULL, else 1
 */
int delete2(linked_list_t **current)
{
    linked_list_t *tmp = *current;

    if (tmp->next == NULL) {
        free(tmp);
        *current = NULL;
        return 0;
    }
    *current = (*current)->next;
    free(tmp);
    return 1;
}

/*!
 * function which is placed in all boxes and gives the linked_list
 * in this box to the delete function and delete ht->array and ht
 * @param ht hashtable,
 */
void delete_hashtable(hashtable_t *ht)
{
    linked_list_t *current = NULL;
    int len;

    if (ht == NULL)
        return;
    len = ht->len;
    for (int i = 0; i < len; i++) {
        ht->array[i] = (current);
        current = ht->array[i];
        while (current) {
            delete2(&current);
            current = current->next;
        }
    }
    ht->array = NULL;
    ht->len = 0;
    free(ht->array);
    ht = NULL;
    free(ht);
}
