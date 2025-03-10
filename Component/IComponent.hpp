/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** ICoponent.hpp
*/
#ifndef ICOMPONENT_H
	#define ICOMPONENT_H
	#include <cstddef>
	#include <iostream>
    #include <vector>
	#include <memory>
	#include <map>

namespace nts
{
	enum Tristate {
		Undefined = (-true),
		True = true,
		False = false
		};
	class IComponent
	{
    protected:
        nts::Tristate _state;
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setState(std::size_t state) = 0;
        virtual std::string getType() = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) = 0;
	};
}


#endif //ICOMPONENT_H
