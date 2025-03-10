/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** InputComponent.hpp
*/
#include "InputComponent.hpp"

/**
 * retrun type of InoutComponent
 * @return std::string
 */
std::string InputComponent::getType()
{
    return "InputComponent";
}

/**
 * Constructs a InputComponent
 * The initial state is set to Undefinde
 */
InputComponent::InputComponent()
{
    _state = nts::Tristate::Undefined;
}

/**
* make state for an InoutComponent gate
* @param pin - pin output where we want the result of the InoutComponent (useless here bc one output)
* @return nts::Tristate, result of pin
*/
nts::Tristate InputComponent::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}
