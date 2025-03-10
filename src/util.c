/*
** EPITECH PROJECT, 2023
** util
** File description:
** fonction
*/
/*!
 * @util.c
 * useful function for mini printf
 */
#include "my.h"

/*!
 * function to display one charracter
 * @param c char
 */
void my_putchar(char c)
{
    write(1, &c, 1);
}

/*!
 * function to display string
 * @param str char *, string
 * @return
 */
int my_putstr(char const *str)
{
    char h = 0;

    while (str[h] != '\0') {
        my_putchar(str[h]);
        h++;
    }
}

/*!
 * function to display a number
 * @param nb, int
 * @return 0
 */
int my_put_nbr(int nb)
{
    int h = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}

/*!
 * function to display a unsigned int
 * @param nb, int
 * @return c + 1
 */
int my_put_nbr_uns(int nb)
{
    int c = 0;

    if (nb < 0) {
        nb *= -1;
    }
    if (nb >= 10) {
        my_put_nbr_uns(nb / 10);
        c ++;
    }
    my_putchar(nb % 10 + 48);
    return c + 1;
}

/*!
 * function to count the size of a string
 * @param str char *
 * @return number of characters
 */
int my_strlen(char const *str)
{
    char h = 0;

    while (str[h] != '\0') {
        h ++;
    }
    return h;
}
