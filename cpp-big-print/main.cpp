#include "bprint.h"

using std::cin;
using std::getline;

int main() {

	cout << "This program creates a big console print of your input, type 'EXIT' or 'exit' to quit.";

	while (true) {
		cout << "\n> ";
		
		string input;
		getline(cin, input);
		system("cls");

		if (input.empty()) input = "abrakadabrazimzalabim!";
		if (input == "EXIT" or input == "exit") break;

		big_print(input);
	}
}