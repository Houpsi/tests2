/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** compare les deux chaînes s1 et s2
*/
/*!
 * @file my_strcmp.c
 *
 */
#include "my.h"

/*!
 * compare two string
 * @param s1 char const *, first string to compare
 * @param s2 char const *, second string to compare
 * @return return 0 if the two string is there equal,
 * return a negative value if s1 is less than s2 and
 * return a positive value if s1 is greater than s2
 */
int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int ii = 0;
    int result = 0;

    while (s1[i] != '\0' && s2[ii] != '\0') {
        if (s1[i] != s2[ii]) {
            result = (s1[i] - s2[ii]);
            return (result);
        }
        i = i + 1;
        ii = ii + 1;
    }
}
