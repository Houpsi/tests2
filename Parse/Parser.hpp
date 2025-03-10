/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** Parse.cpp
*/
#ifndef PARSE_HPP
	#define PARSE_HPP
	#include "../Factory/Factory.hpp"
	#include <sstream>
	#include <iostream>
    #include <fstream>
	#include <cstring>
	#include <cstring>
	#include <sstream>
	#include <string>
	#include <array>
	#include "../Circuit/Circuit.hpp"
	#include <algorithm>

class Parse {
	public:
		Parse(std::string filename, Circuit& circuit);
		~Parse() {};
		void openFile(std::string fileName);
		int readFile(Circuit& circuit);
		void closeFile();
		bool checkComment(std::string content);
		void checkChipset(std::string content);
		bool checkLinks(std::string content, bool chipsetExists);
		void setChipset(bool chipset);
		void checkComponent(std::string content, Circuit& circuit);
		void strToWordArray(std::string content, Circuit& circuit);
		void cleanString(std::string& content);
        void checkLinksComponent(const std::string& type1, const std::string& type2);
		void removeComment(std::string& content);
		std::string trim(const std::string& str);

private:
    	Factory _factory;
        std::ifstream _openFile;
        bool _chipset;
        bool _links;
};

#endif //PARSE_HPP
