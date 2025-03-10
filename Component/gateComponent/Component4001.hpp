/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Circuit.hpp
*/
#ifndef COMPONENT4001_HPP
	#define COMPONENT4001_HPP
	#include "../AComponent.hpp"
	#include <map>

class Component4001: public nts::AComponent
{
	public:
        Component4001() = default;
		nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //COMPONENT4001_HPP
