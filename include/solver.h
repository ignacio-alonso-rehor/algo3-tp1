#ifndef SOLVER_H_
#define SOLVER_H_

#include <vector>
#include "types.h"

// Complejidad: O(2^n)
// jt : {0, ..., n} x Z x Z ---> {0, ..., n} 
int jt_bf(int, int, int, std::vector<pair>&);


// Complejidad: O(2^n)
int jt_bt(int i, int r, int min_r, int k, std::vector<pair>& S);

int jt_dp(int i, int m, std::vector<pair>& S, matrix& memo);

#endif /* SOLVER_H_ */