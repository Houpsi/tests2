#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Component/gateComponent/Component4069.hpp"
#include "../Component/specialComponent/InputComponent.hpp"
#include "../Component/specialComponent/OutputComponent.hpp"

Test(nanotekspice, test_not4069_all_gates)
{
    Component4069 not4069;
    InputComponent input1, input2, input3, input4, input5, input6;
    OutputComponent output1, output2, output3, output4, output5, output6;

    not4069.setLink(1, input1, 1);
    input1.setLink(1, not4069, 1);
    output1.setLink(1, not4069, 2);
    not4069.setLink(2, output1, 1);

    not4069.setLink(3, input2, 1);
    input2.setLink(1, not4069, 3);
    output2.setLink(1, not4069, 4);
    not4069.setLink(4, output2, 1);

    not4069.setLink(5, input3, 1);
    input3.setLink(1, not4069, 5);
    output3.setLink(1, not4069, 6);
    not4069.setLink(6, output3, 1);

    not4069.setLink(9, input4, 1);
    input4.setLink(1, not4069, 9);
    output4.setLink(1, not4069, 8);
    not4069.setLink(8, output4, 1);

    not4069.setLink(11, input5, 1);
    input5.setLink(1, not4069, 11);
    output5.setLink(1, not4069, 10);
    not4069.setLink(10, output5, 1);

    not4069.setLink(13, input6, 1);
    input6.setLink(1, not4069, 13);
    output6.setLink(1, not4069, 12);
    not4069.setLink(12, output6, 1);

    input1.setState(nts::False); input2.setState(nts::False);
    input3.setState(nts::False); input4.setState(nts::False);
    input5.setState(nts::False); input6.setState(nts::False);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);
    output5.simulate(1); output6.simulate(1);

    cr_assert_eq(output1.compute(1), nts::True, "Gate 1: NOT 0 devrait donner 1");
    cr_assert_eq(output2.compute(1), nts::True, "Gate 2: NOT 0 devrait donner 1");
    cr_assert_eq(output3.compute(1), nts::True, "Gate 3: NOT 0 devrait donner 1");
    cr_assert_eq(output4.compute(1), nts::True, "Gate 4: NOT 0 devrait donner 1");
    cr_assert_eq(output5.compute(1), nts::True, "Gate 5: NOT 0 devrait donner 1");
    cr_assert_eq(output6.compute(1), nts::True, "Gate 6: NOT 0 devrait donner 1");

    input1.setState(nts::True); input2.setState(nts::True);
    input3.setState(nts::True); input4.setState(nts::True);
    input5.setState(nts::True); input6.setState(nts::True);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);
    output5.simulate(1); output6.simulate(1);

    cr_assert_eq(output1.compute(1), nts::False, "Gate 1: NOT 1 devrait donner 0");
    cr_assert_eq(output2.compute(1), nts::False, "Gate 2: NOT 1 devrait donner 0");
    cr_assert_eq(output3.compute(1), nts::False, "Gate 3: NOT 1 devrait donner 0");
    cr_assert_eq(output4.compute(1), nts::False, "Gate 4: NOT 1 devrait donner 0");
    cr_assert_eq(output5.compute(1), nts::False, "Gate 5: NOT 1 devrait donner 0");
    cr_assert_eq(output6.compute(1), nts::False, "Gate 6: NOT 1 devrait donner 0");

    input1.setState(nts::Undefined); input2.setState(nts::Undefined);
    input3.setState(nts::Undefined); input4.setState(nts::Undefined);
    input5.setState(nts::Undefined); input6.setState(nts::Undefined);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);
    output5.simulate(1); output6.simulate(1);

    cr_assert_eq(output1.compute(1), nts::Undefined, "Gate 1: NOT U devrait donner U");
    cr_assert_eq(output2.compute(1), nts::Undefined, "Gate 2: NOT U devrait donner U");
    cr_assert_eq(output3.compute(1), nts::Undefined, "Gate 3: NOT U devrait donner U");
    cr_assert_eq(output4.compute(1), nts::Undefined, "Gate 4: NOT U devrait donner U");
    cr_assert_eq(output5.compute(1), nts::Undefined, "Gate 5: NOT U devrait donner U");
    cr_assert_eq(output6.compute(1), nts::Undefined, "Gate 6: NOT U devrait donner U");
}

