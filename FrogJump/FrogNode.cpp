#include "FrogNode.h"

FrogNode::FrogNode(int size):_state(size){
	parent = nullptr;
}

FrogNode::~FrogNode(){}

FrogNode::FrogNode(const FrogNode & node):_state(node._state){
	if (node.parent != nullptr) parent = new FrogNode(*(node.parent));
	//parent = node.parent;
}

FrogNode FrogNode::createChdByJump(int i)
{
	FrogNode child(*this);
	child._state.jump(i);
	child.parent = this;
	//printf("create----%p\n", &child);
	return child;
}

FrogState & FrogNode::getState()
{
	return _state;
}

FrogNode * FrogNode::getParent()
{
	return parent;
}
