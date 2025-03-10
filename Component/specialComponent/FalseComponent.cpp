/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** FalseComponent.hpp
*/
#include "FalseComponent.hpp"

/**
 * retrun type of FalseComponent
 * @return std::string
 */
std::string FalseComponent::getType()
{
    return "FalseComponent";
}

/**
 * Constructs a FalseComponent
 * The initial state is set to False
 */
FalseComponent::FalseComponent()
{
    _state = nts::Tristate::False;
}

/**
* make state for an FasleComponent gate
* @param pin - pin output where we want the result of the FalseComponent (useless here bc one output)
* @return nts::Tristate, result of pin
*/
nts::Tristate FalseComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::False;
}
