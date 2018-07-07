#pragma once
#include"FrogSolver.h"
class FrogDFSSolver:public FrogSolver
{
public:
	FrogDFSSolver(int size);
	~FrogDFSSolver();
	void solve();
};

