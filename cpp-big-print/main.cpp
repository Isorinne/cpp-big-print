#include <iostream>
#include "bprint.h"


int main() {

	std::cout << "This program creates a big console print of your input, type 'EXIT' or 'exit' to quit.";

	while (true) {
		std::cout << "\n> ";
		
		std::string input;
		std::getline(std::cin, input);
		system("cls");

		if (input.empty()) input = "abrakadabrazimzalabim!";
		if (input == "EXIT" or input == "exit") break;

		big_print(input);
	}
}