/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hash function
*/
/*!
 * @file hash.c
 * file hash the key
 */
#include "my.h"

/*!
 * check if the number is pair or impair
 * @param num int, hashed key
 * @return return 0 is the number is pair and return 1 if the number is impair
 */
static int check_pair_impair(int num)
{
    if (num % 2 == 0)
        return 0;
    else
        return 1;
}

/*!
 * put a number that is an integer in an array
 * @param nbr int,
 * @return return the result
 */
int *int_to_array(int nbr)
{
    int number = nbr;
    int length = 1;
    int temp = number;
    int *result;

    temp = temp / 10;
    while (temp) {
        length++;
        temp = temp / 10;
    }
    result = (int *)malloc((length + 1) * sizeof(int));
    result[length] = -1;
    length--;
    while (length >= 0) {
        result[length] = number % 10;
        number /= 10;
        length--;
    }
    return result;
}

/*!
 * calculate the size of the number
 * @param tmp int,
 * @return return the size
 */
int calculate_size(int tmp)
{
    int size = 0;

    while (tmp > 0) {
        tmp /= 10;
        size++;
    }
    return size;
}

/*!
 * find the middle in the number
 * @param len int, the len of the hashtable
 * @param size size_t, size of the number
 * @param nbr const int *, the key that was hash into a number int a integer
 * @return return the number of the middle
 */
int middle_nbr(int len, size_t size, const int *nbr)
{
    int middle = 0;
    int start;
    int end;

    size = (size - 1) / 2;
    if (len <= 9)
        middle = nbr[size];
    else {
        end = calculate_size(len) - 1;
        if (len <= 100)
            start = size;
        else
            start = end / 2;
        for (int i = 0; i < end; i++)
            middle = middle * 10 + nbr[start + i];
    }
    return middle;
}

/*!
 * look if the number is pair or impair
 * @param len int, the len of the hashtable
 * @param hash_value int, the key that was hash into a number int a string
 * @param size size_t, size of the number
 * @param nbr const int *, the key that was hash into a number int a integer
 * @return return the number hash
 */
int get_index(int len, int hash_value, size_t size, const int *nbr)
{
    int tmp2;

    if (check_pair_impair(hash_value) == 1)
        tmp2 = middle_nbr(len, size, nbr);
    else {
        size = (size / 2);
        tmp2 = nbr[size];
    }
    return tmp2;
}

/*!
 * hash the key
 * @param key char *, the key that we hash
 * @param len int, the len of the hashtable
 * @return return the hashed key
 */
int hash(char *key, int len)
{
    int hash_value = 0;
    size_t size = 0;
    int tmp;
    int *nbr;
    int tmp2 = 0;

    if (key == NULL || len <= 0) {
        return 84;
    }
    for (int i = 0; key[i] != '\0'; i++)
        hash_value += (int) key[i];
    hash_value *= hash_value;
    tmp = hash_value;
    size = calculate_size(tmp);
    nbr = int_to_array(hash_value);
    tmp2 = get_index(len, hash_value, size, nbr);
    return tmp2;
}
