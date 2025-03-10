/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Component4030.hpp
*/
#ifndef COMPONENT4030_H
    #define COMPONENT4030_H
    #include "../AComponent.hpp"

class Component4030  : public nts::AComponent
{
    public:
        Component4030() = default;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //COMPONENT4030_H
