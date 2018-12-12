#pragma once
#include <vector>
#include <string>


class BigPrint {

private:

	std::vector<int>
		a, b, c, d, e, f, g, h, i, j, k, l, m,
		n, o, p, q, r, s, t, u, v, w, x, y, z,
		space, bang, dash, plus, equal, dot;

	std::vector<std::vector<int>> temp_input_matrix, temp_output_matrix;
	std::vector<std::vector<std::vector<int>>> input_matrix, output_matrix;
	
	std::vector<std::string> split_string(const std::string& str, int split_length);
	void create_matrix(std::string str);
	void convert_to_output_matrix(const std::vector<std::vector<int> >(&m));
	void bit_printer(const std::vector< std::vector<int>>(&m));
	size_t get_max_bin_chars();

public:

	BigPrint();
	~BigPrint();
	void driver(std::string input);

};


void big_print(std::string input);