/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** AndComponent.cpp
*/
/**
 * File for And Component
 * The gate :
 * in_1  -1-+---\
 *         | &  |-3- out
 *  in_2 -2-+---/
 */

#include "AndComponent.hpp"

/**
 * retrun type of AndComponent
 * @return std::string
 */
std::string AndComponent::getType()
{
    return "AndComponent";
}

/**
 * make state for an AndComponent gate
 * @param pin pin output where we want the result of the gate And (useless here bc one output)
 * @return nts::Tristate, result of pin
 */
nts::Tristate AndComponent::compute(std::size_t pin)
{
    std::pair<nts::IComponent *, std::size_t> in1 = getLinks(1);
    std::pair<nts::IComponent *, std::size_t> in2 = getLinks(2);
    nts::Tristate tmp1 = in1.first->compute(1);
    nts::Tristate tmp3 = in2.first->compute(1);

    (void)pin;
    if (tmp1 == nts::Tristate::True && tmp3 == nts::Tristate::True)
        return nts::Tristate::True;
    if (tmp1 == nts::Tristate::True && tmp3 == nts::Tristate::False)
        return nts::Tristate::False;
    if (tmp1 == nts::Tristate::False && tmp3 == nts::Tristate::True)
        return nts::Tristate::False;
    if (tmp1 == nts::Tristate::False && tmp3 == nts::Tristate::False)
        return nts::Tristate::False;
    if (tmp1 == nts::Tristate::False && tmp3 == nts::Tristate::Undefined)
        return nts::Tristate::False;
    if (tmp1 == nts::Tristate::True && tmp3 == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (tmp1 == nts::Tristate::Undefined && tmp3 == nts::Tristate::False)
        return nts::Tristate::False;
    if (tmp1 == nts::Tristate::Undefined && tmp3 == nts::Tristate::True)
        return nts::Tristate::Undefined;
    if (tmp1 == nts::Tristate::Undefined && tmp3 == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    return nts::Tristate::False;
}