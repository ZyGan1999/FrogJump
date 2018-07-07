#include "FrogState.h"

FrogState::FrogState(int size)
{
	this->_frognum = size;
	_sln = new int[size + 1];
	for (int i = 0; i < _frognum / 2; i++) {
		_sln[i] = 1;
	}
	_sln[_frognum / 2] = 0;
	for (int i = _frognum / 2 + 1; i < _frognum + 1; i++) {
		_sln[i] = 2;
	}
}

FrogState::FrogState(const FrogState & st)
{
	this->_frognum = st._frognum;
	this->_sln = new int[this->_frognum + 1];
	for (int i = 0; i < _frognum + 1; i++) {
		this->_sln[i] = st._sln[i];
	}
}

void FrogState::jump(int i)
{
	assert(i >= 0 && i < this->_frognum + 1);
	if (_sln[i] == 1 && canJump(i)) {
		if (_sln[i + 1] == 0) {
			_sln[i] = 0;
			_sln[i + 1] = 1;
		}
		else if (_sln[i + 2] == 0) {
			_sln[i] = 0;
			_sln[i + 2] = 1;
		}
	}
	if (_sln[i] == 2 && canJump(i)) {
		if (_sln[i - 1] == 0) {
			_sln[i] = 0;
			_sln[i - 1] = 2;
		}
		else if (_sln[i - 2] == 0) {
			_sln[i] = 0;
			_sln[i - 2] = 2;
		}
	}
}

void FrogState::printState()
{
	for (int i = 0; i < _frognum + 1; i++) {
		cout << _sln[i] << ' ';
	}
	cout << endl;
}

bool FrogState::canJump(int i)
{
	if (_sln[i] == 0) return false;
	else if (_sln[i] == 1) {
		if (i >= _frognum) return false;
		if (_sln[i + 1] == 0 || (_sln[i + 2] == 0 && i <= _frognum - 2)) {
			return true;
		}
		return false;
	}
	else if (_sln[i] == 2) {
		if (i <= 0) return false;
		if (_sln[i - 1] == 0 || (_sln[i - 2] == 0 && i >= 2)) {
			return true;
		}
		return false;
	}
}

bool FrogState::isTarget()
{
	for (int i = 0; i < _frognum / 2; i++) {
		if (_sln[i] != 2) return false;
	}
	for (int i = _frognum / 2 + 1; i < _frognum + 1; i++) {
		if (_sln[i] != 1) return false;
	}
	return true;
}

FrogState::~FrogState()
{
	delete[] _sln;
}
