/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** OutputComponent.hpp
*/
#ifndef OUTPUTCOMPONENT_H
    #define OUTPUTCOMPONENT_H
    #include "../AComponent.hpp"

class OutputComponent : public nts::AComponent
{
    public:
        OutputComponent();
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //OUTPUTCOMPONENT_H
