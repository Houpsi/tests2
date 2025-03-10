/*
** EPITECH PROJECT, 2025
** Oriented Object Programming
** File description:
** error.hpp
*/
#include "error.hpp"

/**
* This function return the error message
* return A string containing the error message
*/
const char *nts::Error::throwError() const noexcept
{
	return this->_message.c_str();
}
