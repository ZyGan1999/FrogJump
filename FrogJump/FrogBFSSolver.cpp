#include "FrogBFSSolver.h"
#include "FrogNode.h"
#include <queue>
using namespace std;
FrogBFSSolver::FrogBFSSolver(int size):FrogSolver(size){}

FrogBFSSolver::~FrogBFSSolver(){}

void FrogBFSSolver::solve()
{
	long long num = 0;
	queue<FrogNode> nodes;
	FrogNode n0(_size);
	nodes.push(n0);
	while (!nodes.empty()) {
		FrogNode crntNode = nodes.front();
		nodes.pop();
		FrogState st = crntNode.getState();
		if (st.isTarget()) {
			continue;
		}
		for (int i = 0; i < _size + 1; i++) {
			if (st.canJump(i)) {
				num++;
				FrogNode child = crntNode.createChdByJump(i);
				nodes.push(child);
			}
		}
	}
	cout << num << endl;
}
