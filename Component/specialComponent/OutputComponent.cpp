/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** OutputComponent.cpp
*/
#include "OutputComponent.hpp"

/**
 * Initializes the component state to Undefined
 */
OutputComponent::OutputComponent()
{
    _state = nts::Tristate::Undefined;
}

/**
 * retrun type of OutputComponent
 * @return std::string
*/
std::string OutputComponent::getType() {
    return "OutputComponent";
}

/**
 * Simulates the output component for the given tick
 * This function updates the state of the output component based on the linked component's state
 * If there are no links, the state remains unchanged
 * @param tick The current simulation tick (unused in this function)
 */
void OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (_links.find(1) == _links.end()) {
        return;
    }
    _state = _links.at(1).first->compute(_links.at(1).second);
}

/**
 * Computes the current state of the output component
 * @param pin The pin to compute (unused in this function)
 * @return The current state of the output component
 */
nts::Tristate OutputComponent::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}
