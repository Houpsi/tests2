/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Circuit.hpp
*/
#ifndef CIRCUIT_HPP
	#define CIRCUIT_HPP
	#include <iostream>
    #include "../Component/IComponent.hpp"
	#include "../Factory/Factory.hpp"
	#include <list>
	#include <string.h>
	#include <sstream>
	#include "../Error/error.hpp"
	#include <vector>
	#include <algorithm>

class Circuit {
	public:
    	Circuit();
        ~Circuit();
        void addComponent(std::string &type);
		void parserType(std::string& content);
		void display() const;
        std::map<std::string , std::pair<std::string, std::unique_ptr<nts::IComponent>>>& getCircuit();
		int checkNameIfExists(std::string toCheck);
		void simulateOutput ();

private:
        std::map<std::string , std::pair<std::string , std::unique_ptr<nts::IComponent>>> _circuit;
        Factory _factory;
		std::string _type;
		std::string _name;
		std::size_t _tick;
};

#endif //CIRCUIT_HPP
