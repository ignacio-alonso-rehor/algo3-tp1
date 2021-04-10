//R, S={<w1,r1>,...,<wn,rn>}
//max cantidad de prod en tubo sin aplastar

//sol candidata (a1,...,an) ; ai E {1,0}
//sol parcial (a1,...,ai) se extiende

//mientras quede R (resistencia del tubo) 

#include <tuple>

int productos = 0;
int i = 0;
vector<int> sol_parcial(n,0)
vector<int> peso_parcial //peso total hasta posicion i

int jambotubos(int R, int n, vector<tuple<int,int>> s, int j) {
	if (j == n) {
		return;
	}
	if (R>0) {
		sol_parcial[j] = 1;
		productos++;
		peso_parcial[j] += s[j].first(); 
		if (productos == maxProd(R,j)){
			return;
		} else { //tendria que mirar mas adelante
			sol_parcial[j] = 0;
			productos--;
			peso_parcial[j] -= s[j].first(); 
			return jambotubos(R, n, s, j+1);
		}
	} else {
		return jambotubos(R-s[j].first(),n,s,j+1);
	}

}

// maxima cantidad de productos de peso hasta R en 0..j 
//si agrego o me paso, o justo alcance o me falta
int maxProd(int R, int j){
	int m = j;
	if (j==0) return m;
	if (R > 0){
		if (s[j].first() > R) {
			m--;
			return maxProd(R, j-1);
		} else { //hay lugar en el tubo
			if (s[j].first() <= minResist()){ //no aplasta nada? -> es menor que la min r?
				return m - maxProd(R-s[j].first(), j-1);
			}
		}
	}
	return m;
}

int minResist(vector<int> sol, int j){	
	for (int i = 0; i<j ; i++){
		if (sol[i] == 1)
	} 
}