/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Factory.hpp
*/
#ifndef FACTORY_H
    #define FACTORY_H
    #include "../Component/IComponent.hpp"
    #include "../Component/elementaryComponent/AndComponent.hpp"
    #include "../Component/elementaryComponent/OrComponent.hpp"
    #include "../Component/specialComponent/InputComponent.hpp"
    #include "../Component/specialComponent/OutputComponent.hpp"
    #include "../Component/specialComponent/FalseComponent.hpp"
    #include "../Component/specialComponent/TrueComponent.hpp"
    #include "../Component/elementaryComponent/XorComponent.hpp"
    #include "../Component/elementaryComponent/NotComponent.hpp"
    #include "../Component/advancedComponent/LoggerComponent.hpp"
    #include "../Component/specialComponent/ClockComponent.hpp"
    #include "../Component/gateComponent/Component4011.hpp"
    #include "../Component/gateComponent/Component4069.hpp"
    #include "../Error/error.hpp"
    #include "../Component/gateComponent/Component4001.hpp"
    #include "../Component/gateComponent/Component4081.hpp"
    #include "../Component/gateComponent/Component4071.hpp"
    #include "../Component/gateComponent/Component4030.hpp"
    #include "../Error/error.hpp"
    #include <functional>
    #include <vector>
    #include <memory>

class Factory {
	public:
        Factory() {
            return;
        };
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
        std::unique_ptr<nts::IComponent> createXor() const;
        std::unique_ptr<nts::IComponent> createInput() const;
        std::unique_ptr<nts::IComponent> createOr() const;
        std::unique_ptr<nts::IComponent> createAnd() const;
        std::unique_ptr<nts::IComponent> createOutput() const;
        std::unique_ptr<nts::IComponent> createFalse() const;
        std::unique_ptr<nts::IComponent> createTrue() const;
        std::unique_ptr<nts::IComponent> createNot() const;
        std::unique_ptr<nts::IComponent> createLogger() const;
        std::unique_ptr<nts::IComponent> createClock() const;
        std::unique_ptr<nts::IComponent> create4001() const;
        std::unique_ptr<nts::IComponent> create4081() const;
        std::unique_ptr<nts::IComponent> create4011() const;
        std::unique_ptr<nts::IComponent> create4071() const;
        std::unique_ptr<nts::IComponent> create4069() const;
        std::unique_ptr<nts::IComponent> create4030() const;

};

#endif //FACTORY_H
