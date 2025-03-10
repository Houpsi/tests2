##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## go go
##

SRC 	=	main.cpp	\
			Circuit/Circuit.cpp \
			Component/AComponent.cpp \
			Component/specialComponent/OutputComponent.cpp	\
			Component/specialComponent/InputComponent.cpp \
			Component/elementaryComponent/AndComponent.cpp	\
			Component/specialComponent/FalseComponent.cpp	\
			Component/specialComponent/TrueComponent.cpp	\
			Component/elementaryComponent/XorComponent.cpp	\
			Component/elementaryComponent/OrComponent.cpp	\
			Component/elementaryComponent/NotComponent.cpp 	\
			Component/advancedComponent/LoggerComponent.cpp \
			Component/specialComponent/ClockComponent.cpp 	\
			Component/gateComponent/Component4001.cpp	\
			Component/gateComponent/Component4081.cpp	\
			Component/gateComponent/Component4011.cpp \
			Component/gateComponent/Component4071.cpp	\
			Component/gateComponent/Component4069.cpp	\
			Component/gateComponent/Component4030.cpp	\
			Factory/Factory.cpp	\
			Parse/Parser.cpp	\
			Shell/Shell.cpp	\
			Error/error.cpp
SRC2 	=	Circuit/Circuit.cpp \
			Component/AComponent.cpp \
			Component/specialComponent/OutputComponent.cpp	\
			Component/specialComponent/InputComponent.cpp \
			Component/elementaryComponent/AndComponent.cpp	\
			Component/specialComponent/FalseComponent.cpp	\
			Component/specialComponent/TrueComponent.cpp	\
			Component/elementaryComponent/XorComponent.cpp	\
			Component/elementaryComponent/OrComponent.cpp	\
			Component/elementaryComponent/NotComponent.cpp 	\
			Component/advancedComponent/LoggerComponent.cpp \
			Component/specialComponent/ClockComponent.cpp 	\
			Component/gateComponent/Component4001.cpp	\
			Component/gateComponent/Component4081.cpp	\
			Component/gateComponent/Component4011.cpp \
			Component/gateComponent/Component4071.cpp	\
			Component/gateComponent/Component4069.cpp	\
			Component/gateComponent/Component4030.cpp	\
			Factory/Factory.cpp	\
			Parse/Parser.cpp	\
			Shell/Shell.cpp	\
			Error/error.cpp
SRC_MAIN = main.cpp
SRC_TESTS = tests/test_and.cpp	\
			tests/test_or.cpp	\
			tests/test_not.cpp	\
			tests/test_xor.cpp	\
			tests/test_4001.cpp	\
			tests/tests_unitaire_and.cpp	\
			tests/tests_unitaire_or.cpp	\
			tests/tests_unitaire_xor.cpp	\
			tests/tests_unitaire_not.cpp	\
			tests/tests_unitaire_4001.cpp	\
			tests/tests_unitaire_4011.cpp	\
			tests/tests_unitaire_4030.cpp	\
			tests/tests_unitaire_4069.cpp	\
			tests/tests_unitaire_4071.cpp	\
			tests/tests_unitaire_4081.cpp	\
			tests/tests_unitaire_parser.cpp	\
			tests/tests_unitaire_factory.cpp

OBJ 	= 	$(SRC:.cpp=.o)
OBJ2 	= 	$(SRC2:.cpp=.o)
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_TESTS 	= 	$(SRC_TESTS:.cpp=.o)

NAME 	=	nanotekspice

CPPFLAGS += -std=c++20 -Wall -Wextra -Werror

all: 	$(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ)  $(CPPFLAGS)

doc:
	doxygen documentation.doxy

tests_run:
	g++ -o unit_tests $(SRC2) $(SRC_TESTS) -lcriterion --coverage $(CPPFLAGS) -fprofile-arcs -ftest-coverage
	./unit_tests
	gcovr  --exclude tests/
	gcovr --exclude tests/ --branches --txt

clean :
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.html
	rm -f *.css

fclean: clean
	rm -f $(NAME)

re : 	fclean all