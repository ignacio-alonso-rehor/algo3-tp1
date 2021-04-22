#include "solver.h"
#include <limits>
#include <iostream>

int jt_bf(int i, int r, const std::vector<pair>& S) {
	if (i == (int) S.size()) {
		if (r >= 0) return 0;
		else return std::numeric_limits<int>::min();
	}

	/*
	* Obtenemos el minimo entre la resistencia restante del tubo, y la del último
	* elemento agregado.
	*/
	int min = std::min(r - S[i].first, S[i].second);

	return std::max(1 + jt_bf(i+1, min, S), jt_bf(i+1, r, S));
}

int max = -1;

int jt_bt(int i, int r, int count, const std::vector<pair>& S, const int& p) {
	// Poda por factibilidad
	if (p != -1 && r < 0)
		return std::numeric_limits<int>::min();
	
	if (i == (int) S.size())
		return 0;

	// Poda por optimalidad
	int restantes = (int) S.size() - i;
	if (p != 1 && count + restantes <= max)
		return std::numeric_limits<int>::min();

	if (count > max)
		max = count;

	/*
	* Obtenemos el minimo entre la resistencia restante del tubo, y la del último
	* elemento agregado.
	*/
	int min = std::min(r - S[i].first, S[i].second);

	return std::max(1 + jt_bt(i+1, min, count+1, S, p), jt_bt(i+1, r, count, S, p));
}

int jt_dp(int i, int n, int m, const std::vector<pair>& S, matrix& memo){
	if (m < 0) return std::numeric_limits<int>::min(); 

	if (memo[i][m] == -1) {
		if (i == n)
			memo[i][m] = 0;

		else {
			int min = std::min(m - S[i+1].first, S[i + 1].second);
			memo[i][m] = std::max(1 + jt_dp(i + 1, n, min, S, memo), jt_dp(i + 1, n, m, S, memo));
		}
	}
		return memo[i][m];
}