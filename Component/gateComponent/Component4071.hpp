/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Circuit.hpp
*/
#ifndef COMPENENT4071_HPP
	#define COMPENENT4071_HPP
	#include "../AComponent.hpp"
	#include <map>

class Component4071: public nts::AComponent
{
	public:
		Component4071() = default;
		nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //COMPENENT4071_HPP
