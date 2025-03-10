/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** XorComponent.cpp
*/
/*
 * in_1  -1-+---\
 *         |xor |-3- out
 * in_2  -2-+---/
*/
#include "XorComponent.hpp"


/**
 * retrun type of XorComponent
 * @return std::string
 */
std::string XorComponent::getType()
{
    return "XorComponent";
}

/**
 * make state for an XorComponent gate
 * @param pin - pin output where we want the result of the gate xor (useless here bc one output)
 * @return nts::Tristate, result of pin
 */
nts::Tristate XorComponent::compute(std::size_t pin)
{
    std::pair<nts::IComponent *, std::size_t> in1 = getLinks(1);
    std::pair<nts::IComponent *, std::size_t> in2 = getLinks(2);
    nts::Tristate tmp1 = in1.first->compute(1);
    nts::Tristate tmp3 = in2.first->compute(1);

    (void)pin;
    if (tmp1 == nts::Tristate::True && tmp3 == nts::Tristate::True)
        return nts::Tristate::False;
    if (tmp1 == nts::Tristate::True && tmp3 == nts::Tristate::False)
        return nts::Tristate::True;
    if (tmp1 == nts::Tristate::False && tmp3 == nts::Tristate::True)
        return nts::Tristate::True;
    if (tmp1 == nts::Tristate::False && tmp3 == nts::Tristate::False)
        return nts::Tristate::False;

    if (tmp1 == nts::Tristate::False && tmp3 == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (tmp1 == nts::Tristate::True && tmp3 == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (tmp1 == nts::Tristate::Undefined && tmp3 == nts::Tristate::False)
        return nts::Tristate::Undefined;
    if (tmp1 == nts::Tristate::Undefined && tmp3 == nts::Tristate::True)
        return nts::Tristate::Undefined;
    if (tmp1 == nts::Tristate::Undefined && tmp3 == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    return nts::Tristate::False;
}
