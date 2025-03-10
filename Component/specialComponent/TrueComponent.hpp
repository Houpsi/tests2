/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** TrueComponent.cpp
*/
#ifndef TRUECOMPONENT_H
	#define TRUECOMPONENT_H
	#include "../AComponent.hpp"

class TrueComponent : public nts::AComponent
{
    public:
        TrueComponent();
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //TRUECOMPONENT_H
