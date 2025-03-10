/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** InputComponent.hpp
*/
#ifndef INPUTCOMPONENT_H
    #define INPUTCOMPONENT_H
    #include "../IComponent.hpp"
    #include "../AComponent.hpp"

class InputComponent : public nts::AComponent
{
    public:
        InputComponent();
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //INPUTCOMPONENT_H
