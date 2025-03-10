/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** ClockComponent.hpp
*/
#ifndef CLOCKCOMPONENT_H
    #define CLOCKCOMPONENT_H
    #include "../AComponent.hpp"

class ClockComponent : public nts::AComponent
{
    private:
        bool _isChanged;
    public:
        ClockComponent();
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
        void setState(std::size_t state) override;
};

#endif //CLOCKCOMPONENT_H
