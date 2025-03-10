/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Component4069.cpp
*/
#include "Component4069.hpp"

/**
 * retrun type of Component4069
 * @return std::string
 */
std::string Component4069::getType() {
    return "Component4069";
}

/**
 * make state for an 4069Component gate
 * @param pin - pin output where we want the result of the gate 4069 (useless here bc one output)
 * @return nts::Tristate, result of pin
 */
nts::Tristate Component4069::compute(std::size_t pin)
{
	std::map<int, nts::Tristate> _mapState;

    for (int i = 1; i < 14; ++i) {
        if (i == 7 || i == 14)
            continue;
        _mapState.insert({i, getLinks(i).first->compute(1)});
    }

    int inA = 0;


	std::map<int, int> pinMapping = {
		{2, 1},
		{4, 3},
		{6, 5},
		{8, 9},
		{10, 11},
		{12, 13}
	};
	auto it = pinMapping.find(pin);
	if (it != pinMapping.end()) {
		inA = it->second;
	}

	if (_mapState.at(inA) == nts::Tristate::True) {
		return nts::Tristate::False;
	}
	if (_mapState.at(inA) == nts::Tristate::False) {
		return nts::Tristate::True;
	}
	if (_mapState.at(inA) == nts::Tristate::Undefined) {
		return nts::Tristate::Undefined;
	}
	return nts::Tristate::True;
}
