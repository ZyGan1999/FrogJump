#include "FrogDFSSolver.h"
#include "FrogBFSSolver.h"
#include <iostream>
using namespace std;
int main()
{
	int frognum;
	cin >> frognum;
	FrogDFSSolver s(frognum);
	//FrogBFSSolver s(frognum);
	s.solve();

	while (1);
    return 0;
}

