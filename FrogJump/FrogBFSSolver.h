#pragma once
#include"FrogSolver.h"
class FrogBFSSolver:public FrogSolver
{
public:
	FrogBFSSolver(int size);
	~FrogBFSSolver();
	void solve();
};

