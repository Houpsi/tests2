#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Component/gateComponent/Component4030.hpp"
#include "../Component/specialComponent/InputComponent.hpp"
#include "../Component/specialComponent/OutputComponent.hpp"

Test(nanotekspice, test_xor4030_all_gates)
{
    Component4030 xor4030;
    InputComponent input1, input2, input3, input4, input5, input6, input7, input8;
    OutputComponent output1, output2, output3, output4;

    xor4030.setLink(1, input1, 1);
    input1.setLink(1, xor4030, 1);
    xor4030.setLink(2, input2, 1);
    input2.setLink(1, xor4030, 2);
    output1.setLink(1, xor4030, 3);
    xor4030.setLink(3, output1, 1);

    xor4030.setLink(5, input3, 1);
    input3.setLink(1, xor4030, 5);
    xor4030.setLink(6, input4, 1);
    input4.setLink(1, xor4030, 6);
    output2.setLink(1, xor4030, 4);
    xor4030.setLink(4, output2, 1);

    xor4030.setLink(8, input5, 1);
    input5.setLink(1, xor4030, 8);
    xor4030.setLink(9, input6, 1);
    input6.setLink(1, xor4030, 9);
    output3.setLink(1, xor4030, 10);
    xor4030.setLink(10, output3, 1);

    xor4030.setLink(12, input7, 1);
    input7.setLink(1, xor4030, 12);
    xor4030.setLink(13, input8, 1);
    input8.setLink(1, xor4030, 13);
    output4.setLink(1, xor4030, 11);
    xor4030.setLink(11, output4, 1);

    input1.setState(nts::False); input2.setState(nts::False);
    input3.setState(nts::False); input4.setState(nts::False);
    input5.setState(nts::False); input6.setState(nts::False);
    input7.setState(nts::False); input8.setState(nts::False);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::False, "Gate 1: 0 XOR 0 devrait donner 0");
    cr_assert_eq(output2.compute(1), nts::False, "Gate 2: 0 XOR 0 devrait donner 0");
    cr_assert_eq(output3.compute(1), nts::False, "Gate 3: 0 XOR 0 devrait donner 0");
    cr_assert_eq(output4.compute(1), nts::False, "Gate 4: 0 XOR 0 devrait donner 0");

    input1.setState(nts::True);
    input3.setState(nts::True);
    input5.setState(nts::True);
    input7.setState(nts::True);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::True, "Gate 1: 1 XOR 0 devrait donner 1");
    cr_assert_eq(output2.compute(1), nts::True, "Gate 2: 1 XOR 0 devrait donner 1");
    cr_assert_eq(output3.compute(1), nts::True, "Gate 3: 1 XOR 0 devrait donner 1");
    cr_assert_eq(output4.compute(1), nts::True, "Gate 4: 1 XOR 0 devrait donner 1");

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

    cr_assert_eq(output1.compute(1), nts::True, "Gate 1: 0 XOR 1 devrait donner 1");
    cr_assert_eq(output2.compute(1), nts::True, "Gate 2: 0 XOR 1 devrait donner 1");
    cr_assert_eq(output3.compute(1), nts::True, "Gate 3: 0 XOR 1 devrait donner 1");
    cr_assert_eq(output4.compute(1), nts::True, "Gate 4: 0 XOR 1 devrait donner 1");

    input1.setState(nts::True); input2.setState(nts::True);
    input3.setState(nts::True); input4.setState(nts::True);
    input5.setState(nts::True); input6.setState(nts::True);
    input7.setState(nts::True); input8.setState(nts::True);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::False, "Gate 1: 1 XOR 1 devrait donner 0");
    cr_assert_eq(output2.compute(1), nts::False, "Gate 2: 1 XOR 1 devrait donner 0");
    cr_assert_eq(output3.compute(1), nts::False, "Gate 3: 1 XOR 1 devrait donner 0");
    cr_assert_eq(output4.compute(1), nts::False, "Gate 4: 1 XOR 1 devrait donner 0");

    input1.setState(nts::Undefined); input2.setState(nts::False);
    input3.setState(nts::Undefined); input4.setState(nts::False);
    input5.setState(nts::Undefined); input6.setState(nts::False);
    input7.setState(nts::Undefined); input8.setState(nts::False);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::Undefined, "Gate 1: U XOR 0 devrait donner U");
    cr_assert_eq(output2.compute(1), nts::Undefined, "Gate 2: U XOR 0 devrait donner U");
    cr_assert_eq(output3.compute(1), nts::Undefined, "Gate 3: U XOR 0 devrait donner U");
    cr_assert_eq(output4.compute(1), nts::Undefined, "Gate 4: U XOR 0 devrait donner U");

    input2.setState(nts::Undefined);
    input4.setState(nts::Undefined);
    input6.setState(nts::Undefined);
    input8.setState(nts::Undefined);
    output1.simulate(1); output2.simulate(1);
    output3.simulate(1); output4.simulate(1);

    cr_assert_eq(output1.compute(1), nts::Undefined, "Gate 1: U XOR U devrait donner U");
    cr_assert_eq(output2.compute(1), nts::Undefined, "Gate 2: U XOR U devrait donner U");
    cr_assert_eq(output3.compute(1), nts::Undefined, "Gate 3: U XOR U devrait donner U");
    cr_assert_eq(output4.compute(1), nts::Undefined, "Gate 4: U XOR U devrait donner U");
}
