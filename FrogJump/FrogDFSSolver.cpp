#include "FrogDFSSolver.h"
#include "FrogNode.h"
#include <stack>
using namespace std;
FrogDFSSolver::FrogDFSSolver(int size):FrogSolver(size){}

FrogDFSSolver::~FrogDFSSolver(){}

void FrogDFSSolver::solve()
{
	long long num = 0;//计数
	stack<FrogNode> nodes;
	FrogNode n0(_size);//第一个节点
	nodes.push(n0);
	while (!nodes.empty()) {
		FrogNode crntNode = nodes.top();
		nodes.pop();
		FrogState st = crntNode.getState();
		//st.printState();
		if (st.isTarget()) {
			FrogNode * nx = &crntNode;
			stack<FrogNode> success;
			while (nx != nullptr) {
				success.push(*nx);
				//nx->getState().printState();
				nx = nx->getParent();
				//printf("%p\n", nx);
			}
			int StepCount = 1;
			while (!success.empty()) {
				auto cur = success.top();
				success.pop();
				cout << "State " << StepCount++ << ": ";
				cur.getState().printState();
			}
			//st.printState();
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
