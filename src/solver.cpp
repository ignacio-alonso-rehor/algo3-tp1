#include "solver.h"
#include <limits>

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