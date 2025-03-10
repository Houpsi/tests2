/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Component4069.hpp
*/
#ifndef COMPONENT4069_HPP
	#define COMPONENT4069_HPP
	#include "../AComponent.hpp"
	#include <map>

class Component4069: public nts::AComponent
{
    public:
		Component4069() = default;
		nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //COMPONENT4069_HPP
