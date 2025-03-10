/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** NotComponent.cpp
*/
/**
 * NotComponent
 * the gate :
 * in -1-|>o-2- out
 */
#include "NotComponent.hpp"

/**
 * getter of type
 * @return std::string
 */
std::string NotComponent::getType() {
    return "NotComponent";
}

/**
 * make state for an NotComponent gate
 * @param pin pin output where we want the result of the gate Not (useless here bc one output)
 * @return nts::Tristate, result of pin
 */
nts::Tristate NotComponent::compute(std::size_t pin)
{
    std::pair<nts::IComponent *, std::size_t> in1 = getLinks(1);
    nts::Tristate tmp1 = in1.first->compute(1);

    (void)pin;
    if (tmp1 == nts::Tristate::True)
        return nts::Tristate::False;
    if (tmp1 == nts::Tristate::False)
        return nts::Tristate::True;
    if (tmp1 == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    return nts::Tristate::False;
}