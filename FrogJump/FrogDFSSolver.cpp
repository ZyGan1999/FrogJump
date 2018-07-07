#include "FrogDFSSolver.h"
#include "FrogNode.h"
#include <stack>
using namespace std;
FrogDFSSolver::FrogDFSSolver(int size):FrogSolver(size){}

FrogDFSSolver::~FrogDFSSolver(){}

void FrogDFSSolver::solve()
{
	int num = 0;
	stack<FrogNode> nodes;
	FrogNode n0(6);
	nodes.push(n0);
	while (!nodes.empty()) {
		FrogNode crntNode = nodes.top();
		nodes.pop();
		FrogState st = crntNode.getState();
		//st.printState();
		if (st.isTarget()) {
			//st.printState();
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
