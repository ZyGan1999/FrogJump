#include "FrogDFSSolver.h"
#include "FrogBFSSolver.h"
#include "FrogNode.h"
#include <iostream>
using namespace std;
int main()
{
	int frognum;
	cin >> frognum;
	//FrogDFSSolver s(frognum);
	FrogBFSSolver s(frognum);
	s.solve();

	while (1);
	//FrogNode * n1 = new FrogNode(6); FrogNode n2 = n1->createChdByJump(2); FrogNode n3 = n2.createChdByJump(1);
	//auto nx = &n3; 
	//while (nx != nullptr) {
	//	nx->getState().printState();
	//	nx = nx->getParent();
	//}

	//while (1);
    return 0;
}

