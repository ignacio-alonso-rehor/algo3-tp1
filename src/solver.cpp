#include "solver.h"
#include <limits>
#include <iostream>

int max = 0;

int jt_bf(int i, int r, int m, std::vector<pair>& S) {
	if (i == 0) {
		if (r >= 0 && m >= 0) return 0;
		else return std::numeric_limits<int>::min();
	}
	if (S[i].second < m) {
		return std::max(1 + jt_bf(i - 1, r - S[i - 1].first, S[i -1].second, S), jt_bf(i - 1, r, m, S));
	}
	return std::max(1 + jt_bf(i - 1, r - S[i - 1].first, m - S[i - 1].first, S), jt_bf(i - 1, r, m, S));
}

int jt_bt(int i, int r, int min_r, int k, std::vector<pair>& S) {

	std::cout << '[' << i << "] - " << "min : " << min_r << "; res = " << r << '\n';

	// Poda por factibilidad
	if (r < 0 || min_r < 0)
		return std::numeric_limits<int>::min();
	// Poda por optimalidad
	if (k + i <= max)
		return std::numeric_limits<int>::min();

	if (k > max) max = k;

	if (i == 0)
		return 0;

	if (S[i].second < min_r)
		return std::max(1 + jt_bt(i - 1, r - S[i - 1].first, S[i -1].second, k + 1, S), jt_bt(i - 1, r, min_r, k, S));

	return std::max(1 + jt_bt(i - 1, r - S[i - 1].first, min_r - S[i - 1].first, k + 1, S), jt_bt(i - 1, r, min_r, k, S));
}

int jt_dp(int i, int m, std::vector<pair>& S, matrix& memo) {

	std::cout << '(' << i << ", " << m << ") ";

	if (m < 0) return std::numeric_limits<int>::min(); 

	if (memo[i][m] == -1) {
		if (i == 0)
			memo[i][m] = 0;

		else {
			int min = std:min:(m - S[i-1].first, S[i - 1].second);
			std::cout << "min: " << min << '\n';
			memo[i][m] = std::max(1 + jt_dp(i - 1, min, S, memo), jt_dp(i - 1, m, S, memo));
		}
			
	}
		return memo[i][m];
}