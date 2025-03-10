/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Component4081.hpp
*/
#ifndef COMPONENT4081_HPP
	#define COMPONENT4081_HPP
	#include "../AComponent.hpp"
	#include <map>

class Component4081: public nts::AComponent
{
	public:
		Component4081() = default;
		nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //COMPONENT4081_HPP
