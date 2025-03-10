/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Component4011.hpp
*/
#ifndef COMPONENT4011_H
    #define COMPONENT4011_H
    #include "../AComponent.hpp"

class Component4011  : public nts::AComponent
{
    public:
        Component4011() = default;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //COMPONENT4011_H
