/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** XorComponent.hpp
*/
#ifndef XOR_HPP
    #define XR_HPP
    #include "../AComponent.hpp"

class XorComponent : public nts::AComponent
{
    public:
        XorComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
};

#endif //XOR_HPP


