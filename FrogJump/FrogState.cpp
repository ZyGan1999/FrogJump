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
		_sln[i] = -1;
	}
	if (size == 6) {
		_sln[0] = 1; _sln[1] = 2; _sln[2] = 3;
		_sln[3] = 0; _sln[4] = -1; _sln[5] = -2; _sln[6] = -3;
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
	if (_sln[i] > 0 && canJump(i)) {
		if (_sln[i + 1] == 0) {
			int tmp = _sln[i + 1];
			_sln[i + 1] = _sln[i];
			_sln[i] = tmp;
		}
		else if (_sln[i + 2] == 0) {
			int tmp = _sln[i + 2];
			_sln[i + 2] = _sln[i];
			_sln[i] = tmp;
		}
	}
	if (_sln[i] < 0 && canJump(i)) {
		if (_sln[i - 1] == 0) {
			int tmp = _sln[i - 1];
			_sln[i - 1] = _sln[i];
			_sln[i] = tmp;
		}
		else if (_sln[i - 2] == 0) {
			int tmp = _sln[i - 2];
			_sln[i - 2] = _sln[i];
			_sln[i] = tmp;
		}
	}
}

void FrogState::printState()
{
	if (_frognum == 6) {
		for (int i = 0; i < _frognum + 1; i++) {
			switch (_sln[i]) {
			case 1: {cout << "A1 "; break; }
			case 2: {cout << "A2 "; break; }
			case 3: {cout << "A3 "; break; }
			case 0: {cout << "C "; break; }
			case -1: {cout << "B1 "; break; }
			case -2: {cout << "B2 "; break; }
			case -3: {cout << "B3 "; break; }
			}
		}
		cout << endl;
	}
	else{
		for (int i = 0; i < _frognum + 1; i++) {
			cout << _sln[i] << ' ';
		}
		cout << endl;
	}
}

bool FrogState::canJump(int i)
{
	if (_sln[i] == 0) return false;
	else if (_sln[i] > 0) {
		if (i >= _frognum) return false;
		if (_sln[i + 1] == 0 || (_sln[i + 2] == 0 && i <= _frognum - 2)) {
			return true;
		}
		return false;
	}
	else if (_sln[i] < 0) {
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
		if (_sln[i] >= 0) return false;
	}
	for (int i = _frognum / 2 + 1; i < _frognum + 1; i++) {
		if (_sln[i] <= 0) return false;
	}
	return true;
}

FrogState::~FrogState()
{
	delete[] _sln;
}
