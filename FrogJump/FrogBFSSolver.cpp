#include "FrogBFSSolver.h"
#include "FrogNode.h"
#include <queue>
using namespace std;
FrogBFSSolver::FrogBFSSolver(int size):FrogSolver(size){}

FrogBFSSolver::~FrogBFSSolver(){}

void FrogBFSSolver::solve()
{
	int num = 0;
	queue<FrogNode> nodes;
	FrogNode n0(6);
	nodes.push(n0);
	while (!nodes.empty()) {
		FrogNode crntNode = nodes.front();
		nodes.pop();
		FrogState st = crntNode.getState();
		if (st.isTarget()) {
			num++;
			continue;
		}
		for (int i = 0; i < 7; i++) {
			if (st.canJump(i)) {
				FrogNode child = crntNode.createChdByJump(i);
				nodes.push(child);
			}
		}
	}
	cout << num << endl;
}
