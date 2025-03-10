#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void redirect_all_stdout2(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(nanotekspice, tests_not_commands, .init = redirect_all_stdout2) {
    FILE *fp = popen("./nanotekspice tests/tests_not.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in = 0\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > tick: 0\ninput(s):\n  in: U\noutput(s):\n  out: U\n> ");
}

Test(nanotekspice, tests_not_commands_simulate, .init = redirect_all_stdout2) {
    FILE *fp = popen("./nanotekspice tests/tests_not.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in = 0\n");
    fprintf(fp, "display\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > tick: 0\ninput(s):\n  in: U\noutput(s):\n  out: U\n> > tick: 1\ninput(s):\n  in: 0\noutput(s):\n  out: 1\n> ");
}

Test(nanotekspice, tests_not_undefined_2, .init = redirect_all_stdout2) {
    FILE *fp = popen("./nanotekspice tests/tests_not.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in = 0\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > tick: 1\ninput(s):\n  in: 0\noutput(s):\n  out: 1\n> ");
}

Test(nanotekspice, tests_not_undefined_1, .init = redirect_all_stdout2) {
    FILE *fp = popen("./nanotekspice tests/tests_not.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in = U\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > tick: 1\ninput(s):\n  in: U\noutput(s):\n  out: U\n> ");
}

Test(nanotekspice, tests_not_false, .init = redirect_all_stdout2) {
    FILE *fp = popen("./nanotekspice tests/tests_not.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in = 0\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > tick: 1\ninput(s):\n  in: 0\noutput(s):\n  out: 1\n> ");
}

Test(nanotekspice, tests_not_true, .init = redirect_all_stdout2) {
    FILE *fp = popen("./nanotekspice tests/tests_not.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in = 1\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > tick: 1\ninput(s):\n  in: 1\noutput(s):\n  out: 0\n> ");
}

Test(nanotekspice, tests_not_undefined, .init = redirect_all_stdout2) {
    FILE *fp = popen("./nanotekspice tests/tests_not.nts", "w");
    if (!fp) {
        cr_assert_fail("Échec de l'exécution de nanotekspice");
    }

    fprintf(fp, "in = U\n");
    fprintf(fp, "simulate\n");
    fprintf(fp, "display\n");

    pclose(fp);

    fflush(stdout);
    cr_assert_stdout_eq_str("> > > tick: 1\ninput(s):\n  in: U\noutput(s):\n  out: U\n> ");
}
