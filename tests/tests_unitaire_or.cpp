#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Component/elementaryComponent/OrComponent.hpp"
#include "../Component/specialComponent/InputComponent.hpp"
#include "../Component/specialComponent/OutputComponent.hpp"

Test(nanotekspice, test_create_or)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::False);
	input2.setState(nts::False);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::False, "0 & 0 devrait donner 0");
}

Test(nanotekspice, test_create_or_true)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::True);
	input2.setState(nts::True);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::True, "1 & 1 devrait donner 1");
}

Test(nanotekspice, test_create_or_true_false)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::True);
	input2.setState(nts::False);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::True, "1 & 0 devrait donner 1");
}

Test(nanotekspice, test_create_or_false_true)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::False);
	input2.setState(nts::True);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::True, "0 & 1 devrait donner 1");
}

Test(nanotekspice, test_create_or_undefined)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::Undefined);
	input2.setState(nts::Undefined);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::Undefined, "U & U devrait donner U");
}

Test(nanotekspice, test_create_or_undefined_true)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::Undefined);
	input2.setState(nts::True);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::True, "U & 1 devrait donner 1");
}

Test(nanotekspice, test_create_or_undefined_false)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::Undefined);
	input2.setState(nts::False);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::Undefined, "U & 0 devrait donner U");
}

Test(nanotekspice, test_create_or_false_undefined)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::False);
	input2.setState(nts::Undefined);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::Undefined, "0 & U devrait donner U");
}

Test(nanotekspice, test_create_or_true_undefined)
{
	OrComponent orGate;
	InputComponent input1, input2;
	OutputComponent output;

	orGate.setLink(1, input1, 1);
	input1.setLink(1, orGate, 1);
	input2.setLink(1, orGate, 2);
	orGate.setLink(2, input2, 1);
	output.setLink(1, orGate, 3);
	orGate.setLink(3, output, 1);

	input1.setState(nts::True);
	input2.setState(nts::Undefined);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::True, "1 & U devrait donner 1");
}
