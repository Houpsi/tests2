/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Factory.cpp
*/
#include "Factory.hpp"

/**
 * Creates a component based on the specified type
 * This method uses a map to find the correct creation function for the given type
 * and returns a unique pointer to the corresponding component
 * @param type The type of the component to create
 * @return A unique pointer to the created component
 * @throw nts::Error if the specified component type does not exist
 */
std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type) {
    std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> factoryMap = {
            {"input", [this] { return createInput(); }},
            {"or", [this] { return createOr(); }},
            {"and", [this] { return createAnd(); }},
            {"output", [this] { return createOutput(); }},
            {"true", [this] { return createTrue(); }},
            {"false", [this] { return createFalse(); }},
            {"xor", [this] { return createXor(); }},
            {"not", [this] { return createNot(); }},
            {"logger", [this] { return createLogger(); }},
            {"clock", [this] { return createClock(); }},
            {"4001", [this] { return create4001(); }},
            {"4011", [this] { return create4011(); }},
            {"4071", [this] { return create4071(); }},
            {"4069", [this] { return create4069(); }},
            {"4081", [this] { return create4081(); }},
            {"4030", [this] { return create4030(); }}
    };
    auto it = factoryMap.find(type);
    if (it != factoryMap.end()) {
        return it->second();
    }
    throw nts::Error("The Component doesn't exist");
}

/**
 * Creates an OR component
 * @return A unique pointer to an OR component
*/
std::unique_ptr<nts::IComponent> Factory::createOr() const {
    return std::make_unique<OrComponent>();
}

/**
 * Creates an INPUT component
 * @return A unique pointer to an INPUT component
*/
std::unique_ptr<nts::IComponent> Factory::createInput() const {
    return std::make_unique<InputComponent>();
}

/**
 * Creates an AND component
 * @return A unique pointer to an AND component
*/
std::unique_ptr<nts::IComponent> Factory::createAnd() const {
    return std::make_unique<AndComponent>();
}

/**
 * Creates an OUTPUT component
 * @return A unique pointer to an OUTPUT component
*/
std::unique_ptr<nts::IComponent> Factory::createOutput() const {
    return std::make_unique<OutputComponent>();
}

/**
 * Creates an FALSE component
 * @return A unique pointer to an FALSE component
*/
std::unique_ptr<nts::IComponent> Factory::createFalse() const {
    return std::make_unique<FalseComponent>();
}

/**
 * Creates an TRUE component
 * @return A unique pointer to an TRUE component
*/
std::unique_ptr<nts::IComponent> Factory::createTrue() const {
    return std::make_unique<TrueComponent>();
}

/**
 * Creates an XOR component
 * @return A unique pointer to an XOR component
*/
std::unique_ptr<nts::IComponent> Factory::createXor() const {
    return std::make_unique<XorComponent>();
}

/**
 * Creates an NOT component
 * @return A unique pointer to an NOT component
*/
std::unique_ptr<nts::IComponent> Factory::createNot() const {
    return std::make_unique<NotComponent>();
}

/**
 * Creates an CLOCK component
 * @return A unique pointer to an CLOCK component
*/
std::unique_ptr<nts::IComponent> Factory::createClock() const {
    return std::make_unique<ClockComponent>();
}

/**
 * Creates an LOGGER component
 * @return A unique pointer to an LOGGER component
*/
std::unique_ptr<nts::IComponent> Factory::createLogger() const {
    return std::make_unique<LoggerComponent>();
}

/**
 * Creates an 4001 component
 * @return A unique pointer to an 4001 component
*/
std::unique_ptr<nts::IComponent> Factory::create4001() const {
    return std::make_unique<Component4001>();
}

/**
 * Creates an 4081 component
 * @return A unique pointer to an 4081 component
*/
std::unique_ptr<nts::IComponent> Factory::create4081() const {
    return std::make_unique<Component4081>();
}

/**
 * Creates an 4011 component
 * @return A unique pointer to an 4011 component
*/
std::unique_ptr<nts::IComponent> Factory::create4011() const {
    return std::make_unique<Component4011>();
}

/**
 * Creates an 4071 component
 * @return A unique pointer to an INPUT component
*/
std::unique_ptr<nts::IComponent> Factory::create4071() const {
    return std::make_unique<Component4071>();
}

/**
 * Creates an 4069 component
 * @return A unique pointer to an 4069 component
*/
std::unique_ptr<nts::IComponent> Factory::create4069() const {
    return std::make_unique<Component4069>();
}

/**
 * Creates an 4030 component
 * @return A unique pointer to an 4030 component
*/
std::unique_ptr<nts::IComponent> Factory::create4030() const {
    return std::make_unique<Component4030>();
}
