/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** ACoponent.cpp
*/
#include "AComponent.hpp"

/**
 * Constructs an AComponent object
 * Initializes an instance of the AComponent class
 */
nts::AComponent::AComponent() {}

/**
 * Destroys an AComponent object
 * Cleans up any resources associated with the AComponent
 */
nts::AComponent::~AComponent() {}

/**
 * Simulates the behavior of the component for the given tick
 * This function is a placeholder and doesn't perform any action in the base class
 * Derived classes should override this function to implement their specific simulation logic
 * @param tick The current simulation tick (unused in this function)
 */
void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
}

/**
 * Retrieves the linked component and pin for the specified pin
 * This function returns the component and pin associated with the given pin number
 * @param pin The pin for which to retrieve the linked component and pin
 * @return A pair consisting of the linked component and the corresponding pin number
 * @throw nts::Error if the pin does not have a link
 */
std::pair<nts::IComponent*, std::size_t> nts::AComponent::getLinks(std::size_t pin)
{
    return _links.at(pin);
}

/**
 * Sets the state of the component
 * This function sets the state of the component to the given value
 * @param state The state to set (must be either 0, 1, or U)
 */
void nts::AComponent::setState(std::size_t state)
{
    _state = static_cast<Tristate>(state);
}

/**
 * Sets a link between this component and another component
 * This function links the specified pin to another component's pin
 * If a link already exists for the given pin, an error is thrown
 * @param pin The pin of this component to link
 * @param other The other component to link to
 * @param otherPin The pin of the other component to link to
 * @throw nts::Error if the pin is already in use
 */
void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    auto [it2, success] = this->_links.emplace(pin, std::make_pair(&other, otherPin));
    if (!success) {
        throw nts::Error("The gate is already use");
    }
}
