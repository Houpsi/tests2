/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** TrueComponent.cpp
*/
#include "TrueComponent.hpp"

/**
 * retrun type of TrueComponent
 * @return std::string
 */
std::string TrueComponent::getType()
{
    return "TrueComponent";
}

/**
 * Constructs a TrueComponent
 * The initial state is set to True
 */
TrueComponent::TrueComponent()
{
    _state = nts::Tristate::True;
}

/**
* make state for an TrueComponent gate
* @param pin - pin output where we want the result of the FalseComponent (useless here bc one output)
* @return nts::Tristate, result of pin
*/
nts::Tristate TrueComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::True;
}
