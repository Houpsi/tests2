/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Shell.cpp
*/
#include "Shell.hpp"

std::atomic<int> _running;

Shell::Shell() {}

Shell::~Shell() {}

/**
 * This function display the circuit
 * Calls the `display` function of the given Circuit
 * @param circuit - the circuit to display
 */
void Shell::display(Circuit& circuit)
{
	circuit.display();
}

/**
 * This function is a signal handler for SIGINT
 * Catches the interrupt signal (Ctrl+C) and stops the infinite loop
 * @param sig - The signal received
 */
void Shell::catchSignal(int sig)
{
	(void)sig;
	_running = 0;
}

/**
 * This function Runs an infinite loop to simulate and display the circuit state
 * The loop continues until interrupted by SIGINT (Ctrl+C)
 * @param circuit - The circuit to simulate
 */
void Shell::infLoop(Circuit& circuit)
{
	_running = 1;
	signal(SIGINT, catchSignal);

	while (_running) {
		circuit.simulateOutput();
		circuit.display();
	}
}

/**
 * This function sets the values of pending input components in the circuit
 * @param circuit - The circuit to update
 */
void Shell::setValue(Circuit& circuit)
{
    for (auto& x:_pendingInputs) {
        circuit.getCircuit().at(x.first).second->setState(std::stoi(x.second));
    }
    _pendingInputs.clear();
}

/**
 * this function processes a user command and executes the corresponding action
 * @param circuit - The circuit to operate on
 * @param data - The user command
 */
void Shell::checkCommande(Circuit& circuit, const std::string& data)
{
	if (data.compare("simulate") == 0) {
        setValue(circuit);
		circuit.simulateOutput();
		return;
	}
	if (data.compare("display") == 0) {
		display(circuit);
	}
}

/**
 * This function adds spaces around the '=' character in a string if not present
 * @param data - The input string
 * @return The formatted string with spaces around '='
 */
std::string Shell::addSpace(std::string data)
{
	if (data.find(' ') != std::string::npos)
		return data;
	const int index = data.find('=') + 1;

	data.insert(index - 1, " ");
	data.insert(index + 1, " ");
	return data;
}

/**
 * This function changes the value of a circuit component
 * @param circuit - The circuit to modify
 * @param data - The input string containing the component name and value
 */
void Shell::changeValue(Circuit& circuit, std::string data)
{
	data = addSpace(data);
	std::istringstream stream(data);
	std::string variable;
	char equal;
	std::string value;

	stream >> variable >> equal >> value;
	if (value != "0" && value != "1" && value != "U") {
		std::cout << "Unknown value " << value << std::endl;
		return;
	}
	if (circuit.checkNameIfExists(variable) != 0) {
        std::cout << "Unknown component " << variable << std::endl;
        return;
    }
    if (value == "U")
        value = "-1";
    _pendingInputs.insert({variable, value});
}

/**
 * This function trims whitespace from the beginning and end of a string
 * @param str - The string to trim
 * @return the string without space at the start and the enf
 */
std::string Shell::trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t\r\n");
	size_t end = str.find_last_not_of(" \t\r\n");

	return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

/**
 * This function is the main interactive loop for user input
 * @param circuit - The circuit to interact with
 */
void Shell::loop(Circuit& circuit)
{
	std::string data;

	std::cout << "> ";
	while (std::getline (std::cin, data)) {
		data = trim(data);
		if (data == "exit") {
			return;
		}
		if (data == "loop") {
			infLoop(circuit);
		}
		if (data.find('=') != std::string::npos) {
			changeValue(circuit, data);
		}
		checkCommande(circuit, data);
		std::cout << "> ";
	}
}
