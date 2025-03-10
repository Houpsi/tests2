/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** OrCOmponent.cpp
*/
#ifndef OR_HPP
    #define OR_HPP
    #include "../../Factory/Factory.hpp"
    #include "../AComponent.hpp"
    #include <fstream>

class OrComponent : public nts::AComponent
{
    public:
        OrComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //OR_HPP