#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void redirect_all_stdoutt(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(nanotekspice, tests_or_commands, .init = redirect_all_stdoutt) {
    FILE *fp = popen("./nanotekspice tests/tests_or.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_1 = 0\n");
    fprintf(fp, "in_2 = 1\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > tick: 0\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n> ");
}

Test(nanotekspice, tests_or_commands_simulate, .init = redirect_all_stdoutt) {
    FILE *fp = popen("./nanotekspice tests/tests_or.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_1 = 0\n");
    fprintf(fp, "in_2 = 1\n");
    fprintf(fp, "display\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > tick: 0\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n> > tick: 1\ninput(s):\n  in_1: 0\n  in_2: 1\noutput(s):\n  out: 1\n> ");
}

Test(nanotekspice, tests_or_undefined_2, .init = redirect_all_stdoutt) {
    FILE *fp = popen("./nanotekspice tests/tests_or.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_1 = 0\n");
    fprintf(fp, "in_2 = U\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > tick: 1\ninput(s):\n  in_1: 0\n  in_2: U\noutput(s):\n  out: U\n> ");
}

Test(nanotekspice, tests_commands_undefined_1, .init = redirect_all_stdoutt) {
    FILE *fp = popen("./nanotekspice tests/tests_or.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_1 = U\n");
    fprintf(fp, "in_2 = 0\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > tick: 1\ninput(s):\n  in_1: U\n  in_2: 0\noutput(s):\n  out: U\n> ");
}

Test(nanotekspice, tests_commands_false, .init = redirect_all_stdoutt) {
    FILE *fp = popen("./nanotekspice tests/tests_or.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_1 = 0\n");
    fprintf(fp, "in_2 = 0\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > tick: 1\ninput(s):\n  in_1: 0\n  in_2: 0\noutput(s):\n  out: 0\n> ");
}

Test(nanotekspice, tests_commands_true, .init = redirect_all_stdoutt) {
    FILE *fp = popen("./nanotekspice tests/tests_or.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_1 = 1\n");
    fprintf(fp, "in_2 = 1\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > tick: 1\ninput(s):\n  in_1: 1\n  in_2: 1\noutput(s):\n  out: 1\n> ");
}

Test(nanotekspice, tests_commands_undefined, .init = redirect_all_stdoutt) {
    FILE *fp = popen("./nanotekspice tests/tests_or.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in_1 = U\n");
    fprintf(fp, "in_2 = U\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > tick: 1\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n> ");
}
