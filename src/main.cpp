#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>
#include <chrono>

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
	if (argc < 3) {
		std::cerr << "Cantidad de parámetros incorrecta.\n";
		return EXIT_FAILURE;
	}

	std::vector<pair> S;
	int R;

	if (read_vector(S, R, argv[1]) != 0) {
		std::cerr << "Error al abrir el archivo\n";
		return EXIT_FAILURE;
	}

	/*
	for (pair p : S) {
		std::cout << '(' << p.first << ", " << p.second << ")\n";
	}
	*/

	auto start = std::chrono::steady_clock::now();

	int res = jt_bf(S.size(), R, std::numeric_limits<int>::max(), S);
	
	// switch (argv[2]) {
	// 	case "bf":
	// 		break;
	// 	case "bt":
	// 		break;
	// 	case "dp":
	// 		break;
	// }

	auto end = std::chrono::steady_clock::now();
	double total_time = std::chrono::duration<double, std::milli>(end - start).count();

	std::clog << total_time << std::endl;
	std::cout << res << std::endl;

	return EXIT_SUCCESS;
}