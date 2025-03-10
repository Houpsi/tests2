/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** FalseComponent.hpp
*/
#ifndef FALSECOMPONENT_H
    #define FALSECOMPONENT_H
    #include "../AComponent.hpp"

class FalseComponent : public nts::AComponent
{
    public:
        FalseComponent();
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //FALSECOMPONENT_H
