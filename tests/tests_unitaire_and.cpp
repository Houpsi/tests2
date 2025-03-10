#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Component/elementaryComponent/AndComponent.hpp"
#include "../Component/specialComponent/InputComponent.hpp"
#include "../Component/specialComponent/OutputComponent.hpp"

Test(nanotekspice, test_create_and)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::False);
	input2.setState(nts::False);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::False, "0 & 0 devrait donner 0");
}

Test(nanotekspice, test_create_and_true)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::True);
	input2.setState(nts::True);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::True, "1 & 1 devrait donner 1");
}

Test(nanotekspice, test_create_and_true_false)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::True);
	input2.setState(nts::False);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::False, "1 & 0 devrait donner 0");
}

Test(nanotekspice, test_create_and_false_true)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::False);
	input2.setState(nts::True);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::False, "0 & 1 devrait donner 0");
}

Test(nanotekspice, test_create_and_undefined)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::Undefined);
	input2.setState(nts::Undefined);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::Undefined, "U & U devrait donner U");
}

Test(nanotekspice, test_create_and_undefined_true)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::Undefined);
	input2.setState(nts::True);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::Undefined, "U & 1 devrait donner U");
}

Test(nanotekspice, test_create_and_undefined_false)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::Undefined);
	input2.setState(nts::False);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::False, "U & 0 devrait donner 0");
}

Test(nanotekspice, test_create_and_false_undefined)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::False);
	input2.setState(nts::Undefined);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::False, "0 & U devrait donner 0");
}

Test(nanotekspice, test_create_and_true_undefined)
{
	AndComponent andGate;
	InputComponent input1, input2;
	OutputComponent output;

	andGate.setLink(1, input1, 1);
	input1.setLink(1, andGate, 1);
	input2.setLink(1, andGate, 2);
	andGate.setLink(2, input2, 1);
	output.setLink(1, andGate, 3);
	andGate.setLink(3, output, 1);

	input1.setState(nts::True);
	input2.setState(nts::Undefined);
	output.simulate(1);
	cr_assert_eq(output.compute(1), nts::Undefined, "1 & U devrait donner U");
}
