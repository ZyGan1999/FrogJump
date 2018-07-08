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
	FrogNode * getParent();
private:
	FrogState _state;
	FrogNode * parent;
};

