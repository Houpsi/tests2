#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Parse/Parser.hpp"
#include "../Circuit/Circuit.hpp"

Test(Parser, open_valid_file)
{
	Circuit circuit;
	Parse parser("tests/tests_and.nts", circuit);

	cr_expect_no_throw(parser.checkLinksComponent("Component4030", "InputComponent"),
	   std::exception, "Une porte logique peut être reliée à une entrée.");
}

Test(Parser, open_invalid_file)
{
	Circuit circuit;

	cr_expect_throw(Parse parser("invalid_file.nts", circuit),
        nts::Error, "Un fichier inexistant devrait lever une exception.");
}

Test(Parser, open_empty_file)
{
	Circuit circuit;

	cr_expect_throw(Parse parser("tests/empty_file.nts", circuit),
        nts::Error, "Un fichier vide devrait lever une exception.");
}

Test(Parser, trim)
{
	Circuit circuit;
	Parse parser("tests/tests_and.nts", circuit);

	cr_expect(eq(str, parser.trim("  hello  "), "hello"), "Le trim ne fonctionne pas correctement.");
	cr_expect(eq(str, parser.trim("\t\tfoo\t"), "foo"), "Le trim ne supprime pas correctement les tabulations.");
}

Test(Parser, check_comment)
{
	Circuit circuit;
	Parse parser("tests/tests_and.nts", circuit);

	cr_expect(parser.checkComment(""), "Une ligne vide est un commentaire.");
	cr_expect(parser.checkComment("# This is a comment"), "Une ligne commençant par '#' est un commentaire.");
	cr_expect_not(parser.checkComment("foo # comment"), "Une ligne avec un '#' après du texte n'est pas un commentaire.");
}

Test(Parser, clean_string)
{
	Circuit circuit;
	Parse parser("tests/tests_and.nts", circuit);

	std::string str = "   foo   bar   ";
	parser.cleanString(str);
	cr_expect(eq(str, str, "foo bar"), "La fonction cleanString ne normalise pas les espaces correctement.");
}

Test(Parser, check_links_component)
{
    Circuit circuit;
	Parse parser("tests/tests_and.nts", circuit);

	cr_expect_throw(parser.checkLinksComponent("Component4030", "Component4011"),
        nts::Error, "Caught error: The component already exist");
}
