#pragma once
class FrogSolver
{
public:
	FrogSolver(int size);
	~FrogSolver();
	virtual void solve() = 0;
protected:
	int _size;
};

