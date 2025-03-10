/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** ClockComponent.cpp
*/
#include "ClockComponent.hpp"

/**
 * retrun type of Component4011
 * @return std::string
 */
std::string ClockComponent::getType()
{
    return "ClockComponent";
}

/**
 * Constructs a ClockComponent
 * The initial state is set to Undefined, and `_isChanged` is set to false
 */
ClockComponent::ClockComponent()
{
    _state = nts::Tristate::Undefined;
    _isChanged = false;
}

/**
 * Simulates the behavior of the clock component
 * On the first call, it sets `_isChanged` to true without modifying the state
 * On subsequent calls, it toggles the state between True and False if it is not Undefined
 * @param tick The current simulation tick (unused in this implementation)
 */
void ClockComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (!_isChanged) {
        _isChanged = true;
        return;
    }
    if (_state == nts::Tristate::Undefined) {
        _state = nts::Tristate::Undefined;
        return;
    }
    if (_state == nts::Tristate::True) {
        _state = nts::Tristate::False;
        return;
    }
    if (_state == nts::Tristate::False) {
        _state = nts::Tristate::True;
        return;
    }
}

/**
 * Sets the state of the clock
 * This method allows manually setting the state of the clock. It also resets `_isChanged`
 * to false to ensure that the clock behavior is properly handled on the next simulation tick
 * @param state The new state of the clock (0 = False, 1 = True, 2 = Undefined)
 */
void ClockComponent::setState(std::size_t state)
{
    _state = static_cast<nts::Tristate>(state);
    _isChanged = false;
}

/**
 * make state for an ClocckComponent gate
 * @param pin - pin output where we want the result of the clock (useless here bc one output)
 * @return nts::Tristate, result of pin
 */
nts::Tristate ClockComponent::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}
