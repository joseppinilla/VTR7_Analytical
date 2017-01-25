#include <iostream>
//#include "/usr/include/c++/4.8/bits/stl_vector.h"
#include <vector>
#include <complex>
#include "../Eigen/Dense"
#include "../Eigen/Sparse"
#include "../Eigen/Core"
#include "../Eigen/SparseQR"

#include "quadratic.h"

using namespace std;
using namespace Eigen;

void solve_linear_system(double *sol, double *matrix, double *vector, int N){

	int i;

	MatrixXd A(N, N);

	A = Map<MatrixXd>(matrix,N,N);

	std::cout << A << "\n";

	VectorXd b(N);

	b = Map<VectorXd>(vector,N);

	std::cout << b << "\n";

	VectorXd X = A.jacobiSvd(ComputeThinU | ComputeThinV).solve(b);

	for (i = 0; i < N; i++) {
		sol[i] = X.data()[i];
	}

}
