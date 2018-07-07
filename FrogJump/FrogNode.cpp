#include "FrogNode.h"

FrogNode::FrogNode(int size):_state(size){}

FrogNode::~FrogNode(){}

FrogNode::FrogNode(const FrogNode & node):_state(node._state){}

FrogNode FrogNode::createChdByJump(int i)
{
	FrogNode child(*this);
	child._state.jump(i);
	return child;
}

FrogState & FrogNode::getState()
{
	return _state;
}
