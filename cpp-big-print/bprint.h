#pragma once

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
	vector<int>
		a, b, c, d, e, f, g, h, i, j, k, l, m,
		n, o, p, q, r, s, t, u, v, w, x, y, z,
		space, bang, dash, plus, equal, dot;

	BinaryChars();

	~BinaryChars();
};

vector<string> split_string(const string& str, int split_length);
void create_matrix(const BinaryChars bc, string input, vector< vector<int> >(&v));
void convert_to_output_matrix(vector< vector<int> >(&v1), const vector< vector<int> >(&v2));
void bit_printer(const vector< vector<int>>(&v));
unsigned int get_max_bin_chars();
void big_print(string input);