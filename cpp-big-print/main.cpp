#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <chrono>
#include <thread>
#include <Windows.h>

using std::vector;
using std::string;
using std::bitset;
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::size_t;
using std::transform;

class BinaryChars {

public:
	vector<int> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, space, bang, dash, plus, equal, dot;

	BinaryChars() {

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

	~BinaryChars() {

	}



};

vector<string> split_string(const string& str, int split_length)
{
	int num_sub_strings = str.length() / split_length;
	vector<string> sub_strs;

	for (auto i = 0; i < num_sub_strings; i++)
		sub_strs.push_back(str.substr(i * split_length, split_length));
	
	if (str.length() % split_length != 0)
		sub_strs.push_back(str.substr(split_length * num_sub_strings));
	
	return sub_strs;
}

void create_matrix(const BinaryChars bc, string input, vector< vector<int> >(&v)) {


	for (char &ch : input)
		switch (ch) {
		case 'a': v.push_back(bc.a); break;
		case 'b': v.push_back(bc.b); break;
		case 'c': v.push_back(bc.c); break;
		case 'd': v.push_back(bc.d); break;
		case 'e': v.push_back(bc.e); break;
		case 'f': v.push_back(bc.f); break;
		case 'g': v.push_back(bc.g); break;
		case 'h': v.push_back(bc.h); break;
		case 'i': v.push_back(bc.i); break;
		case 'j': v.push_back(bc.j); break;
		case 'k': v.push_back(bc.k); break;
		case 'l': v.push_back(bc.l); break;
		case 'm': v.push_back(bc.m); break;
		case 'n': v.push_back(bc.n); break;
		case 'o': v.push_back(bc.o); break;
		case 'p': v.push_back(bc.p); break;
		case 'q': v.push_back(bc.q); break;
		case 'r': v.push_back(bc.r); break;
		case 's': v.push_back(bc.s); break;
		case 't': v.push_back(bc.t); break;
		case 'u': v.push_back(bc.u); break;
		case 'v': v.push_back(bc.v); break;
		case 'w': v.push_back(bc.w); break;
		case 'x': v.push_back(bc.x); break;
		case 'y': v.push_back(bc.y); break;
		case 'z': v.push_back(bc.z); break;
		case ' ': v.push_back(bc.space); break;
		case '!': v.push_back(bc.bang); break;
		case '-': v.push_back(bc.dash); break;
		case '+': v.push_back(bc.plus); break;
		case '=': v.push_back(bc.equal); break;
		case '.': v.push_back(bc.dot); break;
		default: cout << "Sorry! Can't print that.\n";
			getchar(); exit(0);
		}
}

void convert_to_output_matrix(vector< vector<int> >(&v1), const vector< vector<int> >(&v2)) {


	unsigned int i = 0, j = 0;


	for (auto &row : v1) {
		for (auto &k : v2) {
			v1[j].push_back(v2[i][j]);

			i++;
		}
		j++; i = 0;
	}
}

void bit_printer(const vector< vector<int>>(&v)) {

	string bin_line;

	for (const auto &row : v) {
		for (const auto &dec_line : row) {
			bin_line = bitset<15>(dec_line).to_string('*', ' ');
			cout << bin_line;

			std::this_thread::sleep_for(std::chrono::milliseconds(4));
		}
		cout << endl;
	}
}

unsigned int get_max_bin_chars() {

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	unsigned int columns;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	return columns / 15;
}

void big_print(string input) {

	system("cls");

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	unsigned int max_bin_chars = get_max_bin_chars();

	vector<string> sub_strs = split_string(input, max_bin_chars);

	BinaryChars bc;
	vector<vector<int> > temp_input_matrix;
	vector< vector< vector<  int> > > input_vector_of_vectors;

	for (auto str : sub_strs) {
		create_matrix(bc, str, temp_input_matrix);
		input_vector_of_vectors.push_back(temp_input_matrix);
		temp_input_matrix.clear();
	}

	vector< vector<int> > temp_output_vector(12);
	vector< vector< vector< int > > > output_vector_of_vectors;

	for (auto vec : input_vector_of_vectors) {
		convert_to_output_matrix(temp_output_vector, vec);
		output_vector_of_vectors.push_back(temp_output_vector);
		temp_output_vector.clear();
		temp_output_vector.resize(12);
	}

	for (auto vec : output_vector_of_vectors) {
		bit_printer(vec); cout << endl;
	}

}

int main() {

	string input;
	getline(cin, input);
	
	if (input.empty()) input = "boring.";

	big_print(input);

	std::getchar();
}



