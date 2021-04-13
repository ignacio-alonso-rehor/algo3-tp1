#ifndef SOLVER_H_
#define SOLVER_H_

#include <vector>
#include "types.h"

// Complejidad: O(2^n)
// jt : {0, ..., n} x Z x Z ---> {0, ..., n} 
int jt_bf(int, int, int, std::vector<pair>&);

#endif /* SOLVER_H_ */