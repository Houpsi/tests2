#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include "../Factory/Factory.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


Test(Factory, CreateValidComponents) {
	Factory factory;

	cr_expect_no_throw({
		auto comp = factory.createComponent("input");
		cr_expect(comp != nullptr, "L'objet InputComponent n'a pas été créé.");
	}, std::exception, "Factory::createComponent ne devrait pas lever d'exception pour 'input'.");

	cr_expect_no_throw({
		auto comp = factory.createComponent("and");
		cr_expect(comp != nullptr, "L'objet AndComponent n'a pas été créé.");
	}, std::exception, "Factory::createComponent ne devrait pas lever d'exception pour 'and'.");
}
