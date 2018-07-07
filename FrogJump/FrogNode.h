#pragma once
#include "FrogState.h"
using namespace std;
class FrogNode
{
public:
	FrogNode(int size);
	~FrogNode();
	FrogNode(const FrogNode & node);
	FrogNode createChdByJump(int i);
	FrogState & getState();
private:
	FrogState _state;
};

