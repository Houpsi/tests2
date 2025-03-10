/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Circuit.cpp
*/
#include "Circuit.hpp"

/**
 * Initializes the circuit with a tick counter set to 0
 */
Circuit::Circuit()
{
    this->_tick = 0;
}

/**
 * getter of circuit
 * @return std::map<std::string, std::pair<std::string, std::unique_ptr<nts::IComponent>>> the circuit
 */
std::map<std::string, std::pair<std::string, std::unique_ptr<nts::IComponent>>> &Circuit::getCircuit() {
    return _circuit;
}

/**
 * Destroys the Circuit object
 */
Circuit::~Circuit() {}

/**
 * Parses the type and name of a component from a string
 * @param content - The string containing the component definition
 * @throws nts::Error If the definition is invalid
 */
void Circuit::parserType(std::string &content)
{
    std::size_t i = 0;
    std::size_t y = 0;

    if (".chipsets:" == content)
       throw nts::Error("Too much chipsets");
    if (content.find(' ') == std::string::npos)
        throw nts::Error("Error parsing");
    if (content[i] == ' ') {
        while (content[i] == ' ')
            i++;
        content = content.substr(i, content.size());
        i = 0;
    }
    while (i < content.size() && content[i] != ' ')
        i++;
    this->_type = content.substr(0, i);
    i ++;
    while (content[i] == ' ')
        i ++;
    y = i;
    while (i < content.size() && content[i] != ' ' && content[i] != '#')
        i++;
    this->_name = content.substr(y, i - y);
}

/**
 * Checks if a component name already exists in the circuit
 * @param toCheck - The name of the component to check
 * @return 0 if the component exists, 84 otherwise
 */
int Circuit::checkNameIfExists(std::string toCheck)
{
    for (const auto& [name, component] : _circuit)
        if (name == toCheck)
            return 0;
    return 84;
}

/**
 * Adds a component to the circuit
 * Parses the component type and name, then adds it to the circuit if it does not already exist
 * @param content - The string containing the component definition
 * @throws nts::Error If the component already exists
 */
void Circuit::addComponent(std::string &content) {
    parserType(content);
    if (checkNameIfExists(this->_name) == 0)
        throw nts::Error("The component already exist");
    _circuit.emplace(this->_name, std::make_pair(this->_type, _factory.createComponent(this->_type)));
}

/**
 * Simulates the circuit's outputs
 * Iterates through the components and simulates the outputs, clocks, and loggers
 * Increments the tick counter after simulation
 */
void Circuit::simulateOutput()
{
    for (const auto& [name, component] : _circuit) {
        if (component.first == "output") {
            component.second->simulate(this->_tick);
        }
        if (component.first == "clock") {
            component.second->simulate(this->_tick);
        }
        if (component.first == "logger") {
            component.second->simulate(this->_tick);
        }
    }
    this->_tick += 1;
}

/**
 * Displays the state of the circuit
 * Prints the current tick count and the states of input and output components
 */
void Circuit::display() const
{
    std::list<std::pair<std::string, std::pair<std::string, nts::Tristate>>> list;

    std::cout << "tick: " << this->_tick << std::endl;
    for (const auto& [name, component] : _circuit) {
        if (component.first == "input" || component.first == "output" || component.first == "clock") {
            nts::Tristate compute = component.second->compute(1);
            list.push_back(std::make_pair(component.first, std::make_pair(name, compute)));
        }
    }
    list.sort();

    std::string display_state;
    std::cout << "input(s):" <<std::endl;
    for (const auto& pair : list) {
        if (pair.first == "input" || pair.first == "clock") {
            if (pair.second.second == nts::Tristate::Undefined)
                std::cout << "  " << pair.second.first << ": " << "U" << std::endl;
            else {
                std::cout << "  " << pair.second.first << ": " << pair.second.second << std::endl;
            }

        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto pair : list) {
        if (pair.first == "output") {
            if (pair.second.second == nts::Tristate::Undefined)
                std::cout << "  " << pair.second.first << ": " << "U" << std::endl;
            else {
                std::cout << "  " << pair.second.first << ": " << pair.second.second << std::endl;
            }
        }
    }
}
