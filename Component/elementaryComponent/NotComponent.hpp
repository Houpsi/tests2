/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** NotComponent.cpp
*/
#ifndef NOT_HPP
    #define NOT_HPP
    #include "../AComponent.hpp"

class NotComponent : public nts::AComponent
{
    public:
        NotComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //NOT_HPP
