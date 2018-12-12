#include "bprint.h"
#include <iostream>
#include <bitset>
#include <algorithm>
#include <chrono>
#include <thread>
#include <Windows.h>

BigPrint::BigPrint() {

	a = { 32767, 28679, 24579, 25571, 25571, 25571, 24579, 24579, 25571, 25571, 25571, 32767 };
	b = { 32767, 24583, 24579, 25571, 25571, 24583, 24579, 25571, 25571, 24579, 24583, 32767 };
	c = { 32767, 28679, 24579, 25571, 25571, 25599, 25599, 25571, 25571, 24579, 28679, 32767 };
	d = { 32767, 24583, 24579, 25571, 25571, 25571, 25571, 25571, 25571, 24579, 24583, 32767 };
	e = { 32767, 24579, 24579, 25599, 25599, 24583, 24583, 25599, 25599, 24579, 24579, 32767 };
	f = { 32767, 24579, 24579, 25599, 25599, 24583, 24583, 25599, 25599, 25599, 25599, 32767 };
	g = { 32767, 28679, 24579, 25571, 25599, 25475, 25475, 25571, 25571, 24579, 28679, 32767 };
	h = { 32767, 25571, 25571, 25571, 25571, 24579, 24579, 25571, 25571, 25571, 25571, 32767 };
	i = { 32767, 24579, 24579, 32319, 32319, 32319, 32319, 32319, 32319, 24579, 24579, 32767 };
	j = { 32767, 30723, 30723, 32739, 32739, 32739, 32739, 25571, 25571, 24579, 28679, 32767 };
	k = { 32767, 25571, 25543, 25487, 25375, 24639, 24639, 25375, 25487, 25543, 25571, 32767 };
	l = { 32767, 25599, 25599, 25599, 25599, 25599, 25599, 25599, 25599, 24579, 24579, 32767 };
	m = { 32767, 25571, 25027, 24707, 25123, 25443, 25571, 25571, 25571, 25571, 25571, 32767 };
	n = { 32767, 25571, 25059, 24803, 24675, 25123, 25475, 25539, 25571, 25571, 25571, 32767 };
	o = { 32767, 28679, 24579, 25571, 25571, 25571, 25571, 25571, 25571, 24579, 28679, 32767 };
	p = { 32767, 24583, 24579, 25571, 25571, 25571, 24583, 24591, 25599, 25599, 25599, 32767 };
	q = { 32767, 28679, 24579, 25571, 25571, 25571, 25123, 25347, 25479, 28675, 31779, 32767 };
	r = { 32767, 24583, 24579, 25571, 25571, 25543, 24591, 24607, 25487, 25543, 25571, 32767 };
	s = { 32767, 28679, 24579, 25571, 25599, 24583, 28675, 32739, 25571, 24579, 28679, 32767 };
	t = { 32767, 24579, 24579, 32319, 32319, 32319, 32319, 32319, 32319, 32319, 32319, 32767 };
	u = { 32767, 25571, 25571, 25571, 25571, 25571, 25571, 25571, 25571, 24579, 28679, 32767 };
	v = { 32767, 25571, 25571, 25571, 25571, 25571, 25571, 25571, 29127, 30735, 32319, 32767 };
	w = { 32767, 25571, 25571, 25571, 25571, 25571, 25443, 25123, 24707, 25027, 25571, 32767 };
	x = { 32767, 25571, 29127, 30863, 31775, 32319, 31775, 30863, 29127, 25571, 25571, 32767 };
	y = { 32767, 25571, 29127, 30863, 31775, 32319, 32319, 32319, 32319, 32319, 32319, 32767 };
	z = { 32767, 24579, 24583, 32655, 32543, 32319, 31871, 30975, 29183, 24579, 24579, 32767 };
	space = { 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767 };
	bang = { 32767, 32319, 32319, 32319, 32319, 32319, 32319, 32319, 32767, 32319, 32319, 32767 };
	dash = { 32767, 32767, 32767, 32767, 32767, 24579, 24579, 32767, 32767, 32767, 32767, 32767 };
	plus = { 32767, 32767, 32767, 32319, 32319, 24579, 24579, 32319, 32319, 32767, 32767, 32767 };
	equal = { 32767, 32767, 32767, 32767, 24579, 24579, 32767, 24579, 24579, 32767, 32767, 32767 };
	dot = { 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32319, 32319, 32767 };

}

BigPrint::~BigPrint() {

}

std::vector<std::string> BigPrint::split_string(const std::string& str, int split_length)
{
	int num_sub_strings = str.length() / split_length;
	std::vector<std::string> sub_strs;

	for (auto i = 0; i < num_sub_strings; i++)
		sub_strs.push_back(str.substr(i * split_length, split_length));

	if (str.length() % split_length != 0)
		sub_strs.push_back(str.substr(split_length * num_sub_strings));

	return sub_strs;
}

void BigPrint::create_matrix(std::string str) {

	for (char &ch : str)
		switch (ch) {
		case 'a': temp_input_matrix.push_back(a); break;
		case 'b': temp_input_matrix.push_back(b); break;
		case 'c': temp_input_matrix.push_back(c); break;
		case 'd': temp_input_matrix.push_back(d); break;
		case 'e': temp_input_matrix.push_back(e); break;
		case 'f': temp_input_matrix.push_back(f); break;
		case 'g': temp_input_matrix.push_back(g); break;
		case 'h': temp_input_matrix.push_back(h); break;
		case 'i': temp_input_matrix.push_back(i); break;
		case 'j': temp_input_matrix.push_back(j); break;
		case 'k': temp_input_matrix.push_back(k); break;
		case 'l': temp_input_matrix.push_back(l); break;
		case 'm': temp_input_matrix.push_back(m); break;
		case 'n': temp_input_matrix.push_back(n); break;
		case 'o': temp_input_matrix.push_back(o); break;
		case 'p': temp_input_matrix.push_back(p); break;
		case 'q': temp_input_matrix.push_back(q); break;
		case 'r': temp_input_matrix.push_back(r); break;
		case 's': temp_input_matrix.push_back(s); break;
		case 't': temp_input_matrix.push_back(t); break;
		case 'u': temp_input_matrix.push_back(u); break;
		case 'v': temp_input_matrix.push_back(v); break;
		case 'w': temp_input_matrix.push_back(w); break;
		case 'x': temp_input_matrix.push_back(x); break;
		case 'y': temp_input_matrix.push_back(y); break;
		case 'z': temp_input_matrix.push_back(z); break;
		case ' ': temp_input_matrix.push_back(space); break;
		case '!': temp_input_matrix.push_back(bang); break;
		case '-': temp_input_matrix.push_back(dash); break;
		case '+': temp_input_matrix.push_back(plus); break;
		case '=': temp_input_matrix.push_back(equal); break;
		case '.': temp_input_matrix.push_back(dot); break;
		default: break;
		}
}

void BigPrint::convert_to_output_matrix(const std::vector<std::vector<int> >(&m)) {

	unsigned int i = 0, j = 0;

	for (auto &row : temp_output_matrix) {
		for (auto &k : m) {
			temp_output_matrix[j].push_back(m[i][j]);
			i++;
		}
		j++; i = 0;
	}
}

void BigPrint::bit_printer(const std::vector<std::vector<int>>(&m)) {

	std::string bin_line;

	for (const auto &row : m) {
		for (const auto &dec_line : row) {
			bin_line = std::bitset<15>(dec_line).to_string('*', ' ');
			std::cout << bin_line;

			std::this_thread::sleep_for(std::chrono::milliseconds(4));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::size_t BigPrint::get_max_bin_chars() {

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	std::size_t columns;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	return columns / 15;
}

void BigPrint::driver(std::string input) {

	transform(input.begin(), input.end(), input.begin(), ::tolower);
	std::size_t max_bin_chars = get_max_bin_chars();
	std::vector<std::string> sub_strs = split_string(input, max_bin_chars);

	for (auto str : sub_strs) {
		create_matrix(str);
		input_matrix.push_back(temp_input_matrix);
		temp_input_matrix.clear();
	}

	for (auto m : input_matrix) {
		temp_output_matrix.resize(12);
		convert_to_output_matrix(m);
		output_matrix.push_back(temp_output_matrix);

		temp_output_matrix.clear();
	}
	input_matrix.clear();

	for (auto m : output_matrix) bit_printer(m);
	
	output_matrix.clear();

}

void big_print(std::string input) {

	BigPrint printer; 
	printer.driver(input);

}