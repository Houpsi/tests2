/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Component4011.cpp
*/
#include "Component4011.hpp"

/**
 * retrun type of Component4011
 * @return std::string
 */
std::string Component4011::getType()
{
    return "Component4011";
}

/**
 * make state for an 4011Component gate
 * @param pin - pin output where we want the result of the gate 4011 (useless here bc one output)
 * @return nts::Tristate, result of pin
 */
nts::Tristate Component4011::compute(std::size_t pin)
{
    std::map<int, nts::Tristate> _mapState;

    for (int i = 1; i < 14; ++i) {
        if (i == 7 || i == 14)
            continue;
        _mapState.insert({i, getLinks(i).first->compute(1)});
    }
    int inA = 0;
    int inB = 0;
    std::map<int, std::pair<int, int>> pinMapping = {
            {3, {1, 2}},
            {4, {5, 6}},
            {10, {8, 9}},
            {11, {12, 13}}
    };

    auto it = pinMapping.find(pin);
    if (it != pinMapping.end()) {
        inA = it->second.first;
        inB = it->second.second;
    }

    if (_mapState.at(inA) == nts::Tristate::True && _mapState.at(inB) == nts::Tristate::True) {
        return nts::Tristate::False;
    }
    if (_mapState.at(inA) == nts::Tristate::False && _mapState.at(inB) == nts::Tristate::False) {
        return nts::Tristate::True;
    }
    if (_mapState.at(inA) == nts::Tristate::True && _mapState.at(inB) == nts::Tristate::False) {
        return nts::Tristate::True;
    }
    if (_mapState.at(inA) == nts::Tristate::False && _mapState.at(inB) == nts::Tristate::True) {
        return nts::Tristate::True;
    }
    if (_mapState.at(inA) == nts::Tristate::Undefined  && _mapState.at(inB) == nts::Tristate::False) {
        return nts::Tristate::True;
    }
    if (_mapState.at(inA) == nts::Tristate::False  && _mapState.at(inB) == nts::Tristate::Undefined) {
        return nts::Tristate::True;
    }
    if (_mapState.at(inA) == nts::Tristate::True  && _mapState.at(inB) == nts::Tristate::Undefined) {
        return nts::Tristate::Undefined;
    }
    if (_mapState.at(inA) == nts::Tristate::Undefined  && _mapState.at(inB) == nts::Tristate::True) {
        return nts::Tristate::Undefined;
    }
    if (_mapState.at(inA) == nts::Tristate::Undefined  && _mapState.at(inB) == nts::Tristate::Undefined) {
        return nts::Tristate::Undefined;
    }
    return nts::Tristate::True;
}
