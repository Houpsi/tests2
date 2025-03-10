/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** main.cpp
*/
#include <iostream>
#include "Component/IComponent.hpp"
#include "Circuit/Circuit.hpp"
#include "Parse/Parser.hpp"
#include "Shell/Shell.hpp"
#include "Error/error.hpp"

void optionHelp()
{
	std::cout << "Usage: ./nanotekspice <input_file>" << std::endl;
	std::cout << std::endl << "NanoTekSpice - A digital circuit simulator" << std::endl;
	std::cout << std::endl << "Commands:" << std::endl;
	std::cout << "exit             Exit the simulator." << std::endl;
	std::cout << "display          Show the current tick and the value of all inputs and outputs." << std::endl;
	std::cout << "input=value      Set an input value (0, 1, or U for undefined)." << std::endl;
	std::cout << "simulate         Simulate one tick of the circuit." << std::endl;
	std::cout << "loop             Continuously simulate the circuit until interrupted (Ctrl+C)." << std::endl;
	std::cout << std::endl <<"File Format:" << std::endl;
	std::cout << "\t- The circuit description must be provided in a .nts file." << std::endl;
	std::cout << "\t- Components are declared in a \".chipsets:\" section." << std::endl;
	std::cout << "\t- Connections between components are declared in a \".links:\" section." << std::endl;
	std::cout << "\t- Lines starting with '#' are comments." << std::endl;
}

int main(int ac, char **av) {
	if (ac != 2) {
       std::cout << "Usage: ./nanotekspice <input_file>" << std::endl;
        return 84;
	}
	if (std::strcmp(av[1], "-h") == 0 || std::strcmp(av[1], "--help") == 0) {
		optionHelp();
		return 0;
	}
    Circuit circuit;
	Shell shell;

	try {
		Parse parse(av[1], circuit);
		shell.loop(circuit);
	} catch (const nts::Error &e) {
		std::cerr << "Caught error: " << e.throwError() << std::endl;
		return 84;
	}
    return 0;
}
