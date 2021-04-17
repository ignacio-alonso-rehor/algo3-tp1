#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>
#include <chrono>
#include <string>

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
	int R, n;
	std::string alg = argv[1]; 

	if (read_vector(S, R, argv[2]) != 0) {
		std::cerr << "Error al abrir el archivo\n";
		return EXIT_FAILURE;
	}

	n = S.size();
	// for (pair p : S) {
	// 	std::cout << '(' << p.first << ", " << p.second << ")\n";
	// }
	


	int res = 0;

	auto start = std::chrono::steady_clock::now();

	if (alg.compare("BF") == 0)
		res = jt_bf(n, R, std::numeric_limits<int>::max(), S);
	else if (alg.compare("BT") == 0)
		res = jt_bt(n, R, std::numeric_limits<int>::max(), 0, S);
	else if (alg.compare("DP") == 0) {
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