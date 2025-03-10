/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** error.hpp
*/
#ifndef ERROR_H
	#define ERROR_H
	#include "../Component/IComponent.hpp"

namespace nts {
	class Error : public std::exception {
	public:
		Error(const std::string &message) : _message(message) {}
		const char *throwError() const noexcept;

	private:
		std::string _message;
	};
}

#endif //ERROR_H
