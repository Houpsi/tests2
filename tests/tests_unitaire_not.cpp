#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Component/elementaryComponent/NotComponent.hpp"
#include "../Component/specialComponent/InputComponent.hpp"
#include "../Component/specialComponent/OutputComponent.hpp"

Test(nanotekspice, test_create_not_false)
{
	NotComponent NotGate;
	InputComponent input1;
	OutputComponent output;

	NotGate.setLink(1, input1, 1);
	input1.setLink(1, NotGate, 1);
	output.setLink(1, NotGate, 3);
	NotGate.setLink(3, output, 1);

	input1.setState(nts::False);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::True, "0 devrait donner 0");
}

Test(nanotekspice, test_create_not_true)
{
	NotComponent NotGate;
	InputComponent input1;
	OutputComponent output;

	NotGate.setLink(1, input1, 1);
	input1.setLink(1, NotGate, 1);
	output.setLink(1, NotGate, 3);
	NotGate.setLink(3, output, 1);

	input1.setState(nts::True);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::False, "1 devrait donner 0");
}

Test(nanotekspice, test_create_not_undefined)
{
	NotComponent NotGate;
	InputComponent input1;
	OutputComponent output;

	NotGate.setLink(1, input1, 1);
	input1.setLink(1, NotGate, 1);
	output.setLink(1, NotGate, 3);
	NotGate.setLink(3, output, 1);

	input1.setState(nts::Undefined);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::Undefined, "U devrait donner U");
}
