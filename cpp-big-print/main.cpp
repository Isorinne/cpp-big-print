#include "bprint.h"

int main() {

	string input;
	getline(cin, input);
	
	if (input.empty()) input = "boring.";

	big_print(input);

	getchar();
}