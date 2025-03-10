/*
** EPITECH PROJECT, 2023
** secured
** File description:
** tests criterion
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(insert, check_display, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos","./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_dump(ht);

    cr_assert_stdout_eq_str("[0]:\n"
                            "> 4 - ./Documents/Tournament/Modules/Vision\n"
                            "[1]:\n"
                            "[2]:\n"
                            "[3]:\n"
                            "> 3 - +33 6 31 45 61 23 71\n"
                            "> 3 - ./Trash/Holidays_Pics/.secret_folder/kratos.ai\n");
}

Test(insert, return_value, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Vn", "ok");
    ht_insert(ht, "Kratos","./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");

    cr_assert_eq(ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision"), 0);
    cr_assert_eq(ht_insert(ht, "Vn", "ok"), 0);
    cr_assert_eq(ht_insert(ht, "Kratos", "./Trash/Holidays_Pics/.secret_folder/kratos.ai"), 0);
    cr_assert_eq(ht_insert(ht, "<3", "+33 6 31 45 61 23 71"), 0);
}

Test(delete, check_display, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos","./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_delete(ht, "Vision");
    ht_dump(ht);

    cr_assert_stdout_eq_str("[0]:\n"
                            "[1]:\n"
                            "[2]:\n"
                            "[3]:\n"
                            "> 3 - +33 6 31 45 61 23 71\n"
                            "> 3 - ./Trash/Holidays_Pics/.secret_folder/kratos.ai\n");
}
//
//Test(delete, return_value, .init = redirect_all_std)
//{
//    hashtable_t *ht = new_hashtable(&hash, 4);
//
//    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
//    ht_insert(ht, "Vn", "ok");
//    ht_insert(ht, "Kratos","./Trash/Holidays_Pics/.secret_folder/kratos.ai");
//    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
//    ht_delete(ht, "Vision");
//
//    cr_assert_eq(ht_delete(ht, "Vision"), 0);
//}


Test(search, check_display, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_dump(ht);
    mini_printf("Looking for %s: %s\n", "Kratos", ht_search(ht, "Kratos"));

    cr_assert_stdout_eq_str("[0]:\n"
                            "> 4 - ./Documents/Tournament/Modules/Vision\n"
                            "[1]:\n"
                            "[2]:\n"
                            "[3]:\n"
                            "> 3 - +33 6 31 45 61 23 71\n"
                            "> 3 - ./Trash/Holidays_Pics/.secret_folder/kratos.ai\n"
                            "Looking for Kratos: ./Trash/Holidays_Pics/.secret_folder/kratos.ai\n");
}

Test(search, return_value, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_dump(ht);
    printf("Looking for %s: %s\n", "Kratos", ht_search(ht, "Kratos"));

    cr_assert_eq(ht_delete(ht, "Vision"), 0);
}
