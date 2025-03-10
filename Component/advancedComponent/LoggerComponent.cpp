/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** LoggerComponent.cpp
*/
#include "LoggerComponent.hpp"
#include <cmath>
#include <fstream>

/**
 * Constructs a LoggerComponent
 * The initial state is set to False
 */
LoggerComponent::LoggerComponent()
{
    _prevClock = nts::Tristate::False;
}

/**
 * retrun type of LoggerComponent
 * @return std::string
 */
std::string LoggerComponent::getType()
{
    return "LoggerComponent";
}

/**
 * Sets the previous clock state
 * This method stores the state of the clock signal at pin 9 to detect falling edges
 * @param state The state of the clock signal (0 = False, 1 = True, 2 = Undefined)
 */
void LoggerComponent::setPrevClock(nts::Tristate state)
{
    _prevClock = state;
}

/**
* Simulates the LoggerComponent behavior
* The component reads binary values from its first 8 pins (1-8) and detects changes on pin 9
* If a falling edge (True -> False) occurs on pin 9, it converts the binary value to an ASCII character
* and appends it to the file "log.bin"
* @param tick The current simulation tick (unused in this implementation)
*/
void LoggerComponent::simulate(std::size_t tick)
{
    std::map<int, nts::Tristate> _mapState;
    std::string binaryNumber;
    std::string charToCopy;
    char byte = 0;

    (void)tick;
    for (int i = 1; i < 11; ++i) {
        _mapState.insert({i, getLinks(i).first->compute(1)});
    }
    if ((_prevClock == nts::Tristate::True && _mapState.at(9) == nts::Tristate::False) || (_prevClock == nts::Tristate::True && _mapState.at(9) == nts::Tristate::True) || _mapState.at(10) == nts::Tristate::True) {
        setPrevClock(_mapState.at(9));
        return ;
    }
    setPrevClock(_mapState.at(9));
    for (int i = 8; i >= 1 ; --i) {
        if (_mapState.at(i) == nts::Tristate::False) {
            binaryNumber.push_back('0');
        }
        else if (_mapState.at(i) == nts::Tristate::True) {
            binaryNumber.push_back('1');
        } else {
            return;
        }
    }
    for (int i = 0; i < 8; ++i) {
        if (binaryNumber[i] == '1')
            byte += std::pow(2, 7 - i);
    }
    charToCopy += byte;
    std::ofstream file("./log.bin", std::ios::app | std::ios::out | std::ios::binary);
    if (file.is_open()) {
        file.write(charToCopy.c_str(), 1);
    }
    file.close();
}

/**
* make state for an LoggerComponent gate
* @param pin - pin output where we want the result of the LoggerComponent (useless here bc one output)
* @return nts::Tristate, result of pin
*/
nts::Tristate LoggerComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::Undefined;
}
