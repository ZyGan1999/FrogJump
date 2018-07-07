#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
class FrogState
{
public:
	FrogState(int size);
	FrogState(const FrogState & st);
	void jump(int i);
	void printState();
	bool canJump(int i);//第i只青蛙能不能动
	bool isTarget();
	~FrogState();
private:
	int * _sln;
	int _frognum;
};

