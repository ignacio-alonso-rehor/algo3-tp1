#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>
#include <chrono>
#include <string>
#include <map>

#include "types.h"
#include "solver.h"

int read_vector (std::vector<pair>& v, int& R, char* file) {
	std::fstream fs;
	fs.open(file, std::fstream::in);
	if (!fs.is_open()) return -1;

	int n, w, r;

	fs >> n >> R;

	for (int i = 0; i < n; i++) {
		fs >> w >> r;
		v.emplace_back(w, r);
	}

	fs.close();
	return 0;
}

int main(int argc, char** argv) {
	std::map<std::string, std::string> m_algoritmos_implementados = {
		{"BF", "Fuerza Bruta"},
		{"BT", "Backtracking"},
		{"BT-F", "Backtracking con poda por factibilidad"},
		{"BT-O", "Backtracking con poda por optimalidad"},
		{"DP", "Programación Dinámica"},
	};

	std::string s_input_algoritmo = argv[1];

	if (argc < 3 || m_algoritmos_implementados.count(s_input_algoritmo) == 0) {
		std::cerr << 
			"Los parámetros ingresados son incorrectos. " <<
			"Uso correcto: ./jt algoritmo archivo_entrada\n" <<
			"Las opciones para el argumento algoritmo son:\n";

		for (auto& e : m_algoritmos_implementados)
			std::cerr << "\t- " << e.first << ": " << e.second << '\n';

		return EXIT_FAILURE;
	}

	std::vector<pair> S;
	int R, n;

	if (read_vector(S, R, argv[2]) != 0) {
		std::cerr << "Error al abrir el archivo\n";
		return EXIT_FAILURE;
	}

	n = S.size();

	int res = 0;

	auto start = std::chrono::steady_clock::now();

	if (s_input_algoritmo.compare("BF") == 0)
		res = jt_bf(0, R, S);
	else if (s_input_algoritmo.compare("BT") == 0)
		res = jt_bt(0, R, 0, S, 0);
	else if (s_input_algoritmo.compare("BT-F") == 0)
		res = jt_bt(0, R, 0, S, 1);
	else if (s_input_algoritmo.compare("BT-O") == 0)
		res = jt_bt(0, R, 0, S, -1);	
	else if (s_input_algoritmo.compare("DP") == 0) {
		matrix memo;

		for (int i = 0; i < n + 1; ++i)
			memo.emplace_back(R + 1, -1);

		res = jt_dp(0, n, R, S, memo);
	}
	auto end = std::chrono::steady_clock::now();
	double total_time = std::chrono::duration<double, std::milli>(end - start).count();

	std::clog << total_time << std::endl;
	std::cout << res << std::endl;

	return EXIT_SUCCESS;
}