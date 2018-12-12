#include "bprint.h"

int main() {

	cout << "This program creates a big console print of your input, type EXIT at anytime to quit.\n";

	while (true) {
		cout << "> ";
		string input;
		getline(cin, input);

		if (input.empty()) input = "boring...";
		if (input == "EXIT") break;

		big_print(input);

		getchar();
		system("cls");

	}
}