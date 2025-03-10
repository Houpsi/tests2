/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/
/*!
 * @file my.h
 * my.h
 */
#include "../hashtable/hashtable.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef TEST_H_
    #define TEST_H_

int *int_to_array(int nbr);
int calculate_size(int tmp);
int middle_nbr(int len, size_t size, const int *nbr);
int get_index(int len, int hash_value, size_t size, const int *nbr);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_uns(int nb);
int my_strlen(char const *str);
int cond3(int i, const char *format, va_list list);
int cond2(int i, const char *format, va_list list);
int cond(int i, const char *format, va_list list);
int mini_printf(const char *format, ...);
int my_strcmp(char const *s1, char const *s2);
int ge_in(hashtable_t *ht, int key_hash, linked_list_t *prev,
    linked_list_t **current);
void foo(const linked_list_t *current);
int delete(linked_list_t **current, linked_list_t *prev);
int delete2(linked_list_t **current);
void push_to_list(linked_list_t **begin, char *key, char *value, int key_hash);
char *display_s(int i, char *key, hashtable_t *ht, char **result);

#endif /* TEST_H_ */
