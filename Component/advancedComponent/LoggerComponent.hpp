/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** LoggerComponent.cpp
*/
#ifndef LOGGERCOMPONENT_H
    #define LOGGERCOMPONENT_H
    #include "../AComponent.hpp"

class LoggerComponent : public nts::AComponent
{
    private:
        nts::Tristate _prevClock;
    public:
        LoggerComponent();
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override;
        void setPrevClock(nts::Tristate state);
};

#endif //LOGGERCOMPONENT_H
