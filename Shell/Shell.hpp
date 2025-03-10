/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Shell.hpp
*/
#ifndef SHELL_HPP
	#define SHELL_HPP
	#include "../Component/AComponent.hpp"
	#include "../Circuit/Circuit.hpp"
	#include <cstddef>
	#include <iostream>
	#include <signal.h>
	#include <atomic>
	#include <boost/algorithm/string.hpp>

class Shell {
    private:
        std::map<std::string , std::string> _pendingInputs;
	public:
        Shell();
        ~Shell();
		void loop(Circuit& circuit);
		void checkCommande(Circuit& circuit, const std::string& data);
		void display(Circuit& circuit);
		void infLoop(Circuit& circuit);
		static void catchSignal(int sig);
		void changeValue(Circuit& circuit, std::string data);
		std::string trim(const std::string& str);
		std::string addSpace(std::string data);
        void setValue(Circuit& circuit);
};

#endif //SHELL_HPP
