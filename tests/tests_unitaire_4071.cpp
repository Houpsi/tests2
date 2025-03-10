#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Component/gateComponent/Component4071.hpp"
#include "../Component/specialComponent/InputComponent.hpp"
#include "../Component/specialComponent/OutputComponent.hpp"

Test(nanotekspice, test_or4071_all_gates)
{
    Component4071 or4071;
    InputComponent input1, input2, input3, input4, input5, input6, input7, input8;
    OutputComponent output1, output2, output3, output4;

    or4071.setLink(1, input1, 1);
    input1.setLink(1, or4071, 1);
    or4071.setLink(2, input2, 1);
    input2.setLink(1, or4071, 2);
    output1.setLink(1, or4071, 3);
    or4071.setLink(3, output1, 1);

    or4071.setLink(5, input3, 1);
    input3.setLink(1, or4071, 5);
    or4071.setLink(6, input4, 1);
    input4.setLink(1, or4071, 6);
    output2.setLink(1, or4071, 4);
    or4071.setLink(4, output2, 1);

    or4071.setLink(8, input5, 1);
    input5.setLink(1, or4071, 8);
    or4071.setLink(9, input6, 1);
    input6.setLink(1, or4071, 9);
    output3.setLink(1, or4071, 10);
    or4071.setLink(10, output3, 1);

    or4071.setLink(12, input7, 1);
    input7.setLink(1, or4071, 12);
    or4071.setLink(13, input8, 1);
    input8.setLink(1, or4071, 13);
    output4.setLink(1, or4071, 11);
    or4071.setLink(11, output4, 1);

    input1.setState(nts::False); input2.setState(nts::False);
    input3.setState(nts::False); input4.setState(nts::False);
    input5.setState(nts::False); input6.setState(nts::False);
    input7.setState(nts::False); input8.setState(nts::False);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::False, "Gate 1: 0 OR 0 devrait donner 0");
    cr_assert_eq(output2.compute(1), nts::False, "Gate 2: 0 OR 0 devrait donner 0");
    cr_assert_eq(output3.compute(1), nts::False, "Gate 3: 0 OR 0 devrait donner 0");
    cr_assert_eq(output4.compute(1), nts::False, "Gate 4: 0 OR 0 devrait donner 0");

    input1.setState(nts::True);
    input3.setState(nts::True);
    input5.setState(nts::True);
    input7.setState(nts::True);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::True, "Gate 1: 1 OR 0 devrait donner 1");
    cr_assert_eq(output2.compute(1), nts::True, "Gate 2: 1 OR 0 devrait donner 1");
    cr_assert_eq(output3.compute(1), nts::True, "Gate 3: 1 OR 0 devrait donner 1");
    cr_assert_eq(output4.compute(1), nts::True, "Gate 4: 1 OR 0 devrait donner 1");

    input1.setState(nts::False);
    input3.setState(nts::False);
    input5.setState(nts::False);
    input7.setState(nts::False);
    input2.setState(nts::True);
    input4.setState(nts::True);
    input6.setState(nts::True);
    input8.setState(nts::True);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::True, "Gate 1: 0 OR 1 devrait donner 1");
    cr_assert_eq(output2.compute(1), nts::True, "Gate 2: 0 OR 1 devrait donner 1");
    cr_assert_eq(output3.compute(1), nts::True, "Gate 3: 0 OR 1 devrait donner 1");
    cr_assert_eq(output4.compute(1), nts::True, "Gate 4: 0 OR 1 devrait donner 1");

    input1.setState(nts::True); input2.setState(nts::True);
    input3.setState(nts::True); input4.setState(nts::True);
    input5.setState(nts::True); input6.setState(nts::True);
    input7.setState(nts::True); input8.setState(nts::True);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::True, "Gate 1: 1 OR 1 devrait donner 1");
    cr_assert_eq(output2.compute(1), nts::True, "Gate 2: 1 OR 1 devrait donner 1");
    cr_assert_eq(output3.compute(1), nts::True, "Gate 3: 1 OR 1 devrait donner 1");
    cr_assert_eq(output4.compute(1), nts::True, "Gate 4: 1 OR 1 devrait donner 1");

    input1.setState(nts::Undefined); input2.setState(nts::False);
    input3.setState(nts::Undefined); input4.setState(nts::False);
    input5.setState(nts::Undefined); input6.setState(nts::False);
    input7.setState(nts::Undefined); input8.setState(nts::False);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::Undefined, "Gate 1: U OR 0 devrait donner U");
    cr_assert_eq(output2.compute(1), nts::Undefined, "Gate 2: U OR 0 devrait donner U");
    cr_assert_eq(output3.compute(1), nts::Undefined, "Gate 3: U OR 0 devrait donner U");
    cr_assert_eq(output4.compute(1), nts::Undefined, "Gate 4: U OR 0 devrait donner U");

    input2.setState(nts::Undefined);
    input4.setState(nts::Undefined);
    input6.setState(nts::Undefined);
    input8.setState(nts::Undefined);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::Undefined, "Gate 1: U OR U devrait donner U");
    cr_assert_eq(output2.compute(1), nts::Undefined, "Gate 2: U OR U devrait donner U");
    cr_assert_eq(output3.compute(1), nts::Undefined, "Gate 3: U OR U devrait donner U");
    cr_assert_eq(output4.compute(1), nts::Undefined, "Gate 4: U OR U devrait donner U");
}
