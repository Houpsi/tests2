#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void redirect_all_stdout4(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(nanotekspice, tests_4001_commands, .init = redirect_all_stdout4) {
    FILE *fp = popen("./nanotekspice tests/tests_4001_nor.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_01 = 0\n");
    fprintf(fp, "in_02 = 1\n");
    fprintf(fp, "in_05 = 1\n");
    fprintf(fp, "in_06 = 1\n");
    fprintf(fp, "in_08 = 1\n");
    fprintf(fp, "in_09 = 1\n");
    fprintf(fp, "in_12 = 1\n");
    fprintf(fp, "in_13 = 1\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > > > > > > tick: 0\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> ");
}

//Test(nanotekspice, tests_4011_commands_simulate, .init = redirect_all_stdout4) {
//    FILE *fp = popen("./nanotekspice tests/tests_401_nor.nts", "w");
//    if (!fp) {
//        cr_assert_fail("Échec de l'exécution de nanotekspice");
//    }
//
//    fprintf(fp, "in_01 = 1\n");
//    fprintf(fp, "in_02 = 1\n");
//    fprintf(fp, "in_05 = 1\n");
//    fprintf(fp, "in_06 = 1\n");
//    fprintf(fp, "in_08 = 1\n");
//    fprintf(fp, "in_09 = 1\n");
//    fprintf(fp, "in_12 = 1\n");
//    fprintf(fp, "in_13 = 1\n");
//    fprintf(fp, "display\n");
//    fprintf(fp, "simulate\n");
//    fprintf(fp, "display\n");
//
//    pclose(fp);
//
//    fflush(stdout);
//    cr_assert_stdout_eq_str("> > > > > > > > > > tick: 0\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> > tick: 1\ninput(s):\n  in_01: 1\n  in_02: 1\n  in_05: 1\n  in_06: 1\n  in_08: 1\n  in_09: 1\n  in_12: 1\n  in_13: 1\noutput(s):\n  out_03: 0\n  out_04: 0\n  out_10: 0\n  out_11: 0\n> ");
//}

Test(nanotekspice, tests_4001_undefined_2, .init = redirect_all_stdout4) {
    FILE *fp = popen("./nanotekspice tests/tests_4001_nor.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_01 = 0\n");
    fprintf(fp, "in_02 = 1\n");
    fprintf(fp, "in_05 = 1\n");
    fprintf(fp, "in_06 = 1\n");
    fprintf(fp, "in_08 = 1\n");
    fprintf(fp, "in_09 = 1\n");
    fprintf(fp, "in_12 = 1\n");
    fprintf(fp, "in_13 = 1\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > > > > > > > tick: 1\ninput(s):\n  in_01: 0\n  in_02: 1\n  in_05: 1\n  in_06: 1\n  in_08: 1\n  in_09: 1\n  in_12: 1\n  in_13: 1\noutput(s):\n  out_03: 0\n  out_04: 0\n  out_10: 0\n  out_11: 0\n> ");
}

Test(nanotekspice, tests_4001_undefined_1, .init = redirect_all_stdout4) {
    FILE *fp = popen("./nanotekspice tests/tests_4001_nor.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_01 = U\n");
    fprintf(fp, "in_02 = U\n");
    fprintf(fp, "in_05 = U\n");
    fprintf(fp, "in_06 = U\n");
    fprintf(fp, "in_08 = U\n");
    fprintf(fp, "in_09 = U\n");
    fprintf(fp, "in_12 = U\n");
    fprintf(fp, "in_13 = U\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > > > > > > > tick: 1\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> ");
}

Test(nanotekspice, tests_4001_true, .init = redirect_all_stdout4) {
    FILE *fp = popen("./nanotekspice tests/tests_4001_nor.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_01 = 1\n");
    fprintf(fp, "in_02 = 1\n");
    fprintf(fp, "in_05 = 1\n");
    fprintf(fp, "in_06 = 1\n");
    fprintf(fp, "in_08 = 1\n");
    fprintf(fp, "in_09 = 1\n");
    fprintf(fp, "in_12 = 1\n");
    fprintf(fp, "in_13 = 1\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > > > > > > > tick: 1\ninput(s):\n  in_01: 1\n  in_02: 1\n  in_05: 1\n  in_06: 1\n  in_08: 1\n  in_09: 1\n  in_12: 1\n  in_13: 1\noutput(s):\n  out_03: 0\n  out_04: 0\n  out_10: 0\n  out_11: 0\n> ");
}

Test(nanotekspice, tests_4001_false, .init = redirect_all_stdout4) {
    FILE *fp = popen("./nanotekspice tests/tests_4001_nor.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_01 = 0\n");
    fprintf(fp, "in_02 = 0\n");
    fprintf(fp, "in_05 = 0\n");
    fprintf(fp, "in_06 = 0\n");
    fprintf(fp, "in_08 = 0\n");
    fprintf(fp, "in_09 = 0\n");
    fprintf(fp, "in_12 = 0\n");
    fprintf(fp, "in_13 = 0\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > > > > > > > tick: 1\ninput(s):\n  in_01: 0\n  in_02: 0\n  in_05: 0\n  in_06: 0\n  in_08: 0\n  in_09: 0\n  in_12: 0\n  in_13: 0\noutput(s):\n  out_03: 1\n  out_04: 1\n  out_10: 1\n  out_11: 1\n> ");
}

Test(nanotekspice, tests_4001_undefined, .init = redirect_all_stdout4) {
    FILE *fp = popen("./nanotekspice tests/tests_4001_nor.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_01 = U\n");
    fprintf(fp, "in_02 = U\n");
    fprintf(fp, "in_05 = U\n");
    fprintf(fp, "in_06 = U\n");
    fprintf(fp, "in_08 = U\n");
    fprintf(fp, "in_09 = U\n");
    fprintf(fp, "in_12 = U\n");
    fprintf(fp, "in_13 = U\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > > > > > > > tick: 1\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> ");
}
