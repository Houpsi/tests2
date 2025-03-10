/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** AndComponent.hpp
*/
#include "../AComponent.hpp"

class AndComponent : public nts::AComponent
{
    public:
        AndComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};