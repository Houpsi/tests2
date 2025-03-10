/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Parse.cpp
*/
#include "Parser.hpp"

/**
 * This constructor initialize the parser by opening and reading the given file,
 * then closing after parsing
 * @param filename - The name of the file to parse
 * @param circuit - The circuit object to populate with parsed data
 */
Parse::Parse(std::string filename, Circuit& circuit)
{
    this->openFile(filename);
    this->readFile(circuit);
    this->closeFile();
}

/**
 * This function set the state of the chipset at the given value
 * @param chipset - Boolean value indicating whether the chipset section is active
 */
void Parse::setChipset(bool chipset)
{
    this->_chipset = chipset;
}

/**
 * This function attempts to open file given file and update internal state variable
 * If the file cannot be opened, it throws an exception
 * @param fileName - The name of the file to open
 * @throw nts::Error If the file cannot be opened
 */
void Parse::openFile(std::string fileName)
{
    setChipset(false);
    this->_links = false;
    std::ifstream file (fileName);

    if (!file) {
        throw nts::Error("Could not open file");
    }
    this->_openFile.open(fileName);
    if (!this->_openFile) {
        throw nts::Error("Could not open file");
    }
}

/**
 * This function trims whitespace from the beginning and end of a string
 * @param str - The string to trim
 * @return the string without space at the start and the enf
 */
std::string Parse::trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");

    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

/**
 * This function removes comments from a string
 * If a '#' character is found, everything after it is removed
 * @param content - The string to process
 */
void Parse::removeComment(std::string& content)
{
    if (content.find('#') == std::string::npos)
        return;
    const int index = content.find('#');

    content.erase(index, content.length());
    content = trim(content);
}

/**
 * This function checks if a string is a comment
 * A string is considered a comment if it starts with '#' or is empty
 * @param content - The string to check
 * @return True if the string is a comment, false otherwise
 */
bool Parse::checkComment(std::string content)
{
    if (content.size() == 0)
        return true;
    for (char c : content) {
        if (c == ' ')
            continue;
        return c == '#';
    }
    return false;
}

/**
 * This function check if the section chipset start
 * If the content matches ".chipsets:", the chipset state is set to true
 * @param content - The string to check
 */
void Parse::checkChipset(std::string content)
{
    if (".chipsets:" == content)
        setChipset(true);
}

/**
 * This function check if the section links start
 * If the content matches ".links:", it updates internal states
 * Throws an exception if no chipset section was defined before links
 * @param content - The string to check
 * @param chipsetExists - Boolean indicating whether a chipset section was previously defined
 * @return True if the links section starts, false otherwise
 * @throw nts::Error If no chipset section was found before the links section
 */
bool Parse::checkLinks(std::string content, bool chipsetExists)
{
    if (".links:" == content) {
        if (!this->_chipset || !chipsetExists)
            throw nts::Error("No chipset");
        this->_links = true;
        this->_chipset = false;
        return true;
    }
    return false;
}

/**
 * This function cleans a string by removing extra spaces and tabs
 * Converts multiple spaces/tabs into a single space and trims leading/trailing spaces
 * @param str - The string to clean
 */
void Parse::cleanString(std::string& str)
{
    std::replace(str.begin(), str.end(), '\t', ' ');
    std::string cleaned;
    bool wasSpace = false;

    for (char c : str) {
        if (std::isspace(c)) {
            if (!wasSpace) cleaned += ' ';
            wasSpace = true;
        } else {
            cleaned += c;
            wasSpace = false;
        }
    }

    size_t start = cleaned.find_first_not_of(' ');
    size_t end = cleaned.find_last_not_of(' ');
    str = (start == std::string::npos) ? "" : cleaned.substr(start, end - start + 1);
}

/**
 * This function checks if a component exists in the circuit
 * Throws an exception if the component is unknown
 * @param tmp - The component name
 * @param circuit - The circuit to check against
 * @throw nts::Error If the component doesn't exist
 */
void Parse::checkComponent(std::string tmp, Circuit& circuit)
{
    if (circuit.checkNameIfExists(tmp))
        throw nts::Error("Unknown component");
}

/**
 * This function parses a string and updates the circuit connections
 * @param pin - The pin to check
 * @param type - The type
 * @throw nts::Error If the pins don't exist
 */
void checkPins(std::size_t pin, const std::string &type)
{
    std::map<std::string , std::list<std::size_t>> _maxPin = {
            {"InputComponent" , {1}}, {"TrueComponent", {1}}, {"FalseComponent", {1}}, {"OutputComponent", {1}}, {"ClockComponent", {1}},
            {"NotComponent", {1, 2}},
            {"XorComponent", {1, 2, 3}},
            {"OrComponent", {1,2,3}},
            {"AndComponent", {1,2,3}},
            {"LoggerComponent", {1,2,3,4,5,6,7,8,9,10}},
            {"Component4013", {1,2,3,4,5,6,7,8,9,10, 11, 12, 13}},
            {"Component4081", {1,2,3,4,5,6,8,9,10, 11, 12, 13}},
            {"Component4071", {1,2,3,4,5,6,8,9,10, 11, 12, 13}},
            {"Component4069", {1,2,3,4,5,6,8,9,10, 11, 12, 13}},
            {"Component4030", {1,2,3,4,5,6,8,9,10, 11, 12, 13}},
            {"Component4011", {1,2,3,4,5,6,8,9,10, 11, 12, 13}},
            {"Component4001", {1,2,3,4,5,6,8,9,10, 11, 12, 13}},
            {"Component4512", {1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15}},
            {"Component4094", {1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15}},
            {"Component4040", {1,2,3,4,5,6,7,9,10, 11, 12, 13, 14, 15}},
            {"Component4017", {1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15}},
            {"Component4008", {1,2,3,4,5,6,7,9,10, 11, 12, 13, 14, 15}},
            {"Component4801", {1,2,3,4,5,6,7,8,9,10, 11, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23}},
            {"Component4514", {1,2,3,4,5,6,7,8,9,10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}},
            {"Component2716", {1,2,3,4,5,6,7,8,9,10, 11, 13, 14, 15, 16, 17, 18, 20, 22, 23}}
    };
    auto it = _maxPin.find(type);
    if (it == _maxPin.end()) {
        throw nts::Error("unknown type");
    }

    const std::list<std::size_t>& validPins = it->second;
    if (std::find(validPins.begin(), validPins.end(), pin) == validPins.end()) {
        throw nts::Error("pin is not within the limits");
    }
}

/**
 * check if gate (4000) is not link with an another gate (4000)
 * @param type1 str of type
 * @param type2 str of type
 */
void Parse::checkLinksComponent(const std::string& type1, const std::string& type2)
{
    std::vector<std::string> _listOfGate = {"Component4030", "Component4069", "Component4001", "Component4011", "Component4081", "Component4071"};

    bool found1 = std::find(_listOfGate.begin(), _listOfGate.end(), type1) != _listOfGate.end();
    bool found2 = std::find(_listOfGate.begin(), _listOfGate.end(), type2) != _listOfGate.end();

    if (found1 && found2) {
        throw nts::Error("You can't link two gates together");
    }

};

/**
 * This function parses a string and updates the circuit connections
 * Splits the string into components and pins, validates them, and creates links in the circuit
 * @param content - The content to parse
 * @param circuit - The circuit to update
 * @throw nts::Error If an invalid component or pin is found
 */
void Parse::strToWordArray(std::string content, Circuit& circuit)
{
    cleanString(content);
    std::istringstream stream(content);
    std::array<std::string , 4> array;

    std::getline(stream, array[0], ':');
    std::getline(stream, array[1], ' ');
    std::getline(stream, array[2], ':');
    std::getline(stream, array[3], ' ');

    checkComponent(array[0], circuit);
    checkComponent(array[2], circuit);
    nts::IComponent &tmp = *circuit.getCircuit().at(array[0]).second.get();
    nts::IComponent &tmp2 = *circuit.getCircuit().at(array[2]).second.get();

    std::size_t value1;
    std::size_t value2;
    try {
        value1 = std::stoi(array[3]);
        value2 = std::stoi(array[1]);
    } catch (const std::exception& e) {
        throw nts::Error("Error of conversion stoi");
    }
    checkPins(value1, tmp2.getType());
    checkPins(value2, tmp.getType());
    checkLinksComponent(tmp.getType(), tmp2.getType());
    circuit.getCircuit().at(array[2]).second->setLink(value1, tmp, value2);
    circuit.getCircuit().at(array[0]).second->setLink(value2, tmp2, value1);
    if (tmp.getType() == "TrueComponent" && tmp2.getType() == "OutputComponent")
        tmp2.simulate(0);
    if (tmp.getType() == "FalseComponent" && tmp2.getType() == "OutputComponent")
        tmp2.simulate(0);
}

/**
 * This function reads and parses the file
 * Iterates through the file line by line, processing components and links
 * @param circuit - The circuit to populate
 * @return 0 on success else 84
 * @throw nts::Error If the file is empty or contains invalid data
 */
int Parse::readFile(Circuit& circuit)
{
    std::string content;
    bool chipsetExists = false;

    while (getline (this->_openFile, content)) {
        if(checkComment(content))
            continue;
        removeComment(content);
        if (checkLinks(content, chipsetExists))
            continue;
        if (this->_chipset) {
            chipsetExists = true;
            circuit.addComponent(content);
        }
        if (this->_links) {
            strToWordArray(content, circuit);
        }
        checkChipset(content);
    }
    if (!chipsetExists)
        throw nts::Error("The file is empty");
    return 0;
}

/**
 * This function closes the currently opened file
 */
void Parse::closeFile()
{
    this->_openFile.close();
}
