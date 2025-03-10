/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** ACoponent.hpp
*/
#ifndef ACOMPONENT_H
	#define ACOMPONENT_H
	#include "IComponent.hpp"
    #include "../Error/error.hpp"

namespace nts {
    class AComponent : public nts::IComponent {
        protected:
            std::map <std::size_t, std::pair<nts::IComponent *, std::size_t>> _links;
            std::size_t _maxPin;

        public:
            AComponent();
            ~AComponent();
            void simulate(std::size_t tick);
            std::pair<nts::IComponent *, std::size_t> getLinks(std::size_t pin);
            void setState(std::size_t state) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    };
}

#endif //ACOMPONENT_H
