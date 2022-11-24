#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class AddException {
public:
	virtual void show() = 0;
};

class NoParenthesis : public AddException {
	Lexema l;
public:
	NoParenthesis(Lexema _l) : l(_l) {};
	void show() {
		cout << "No pair was found for the " << "'" << l.getStr() << "'" << " at position " << l.getPos() + 1 << endl;
	}
};

class NoOperands : public AddException {
	double p;
public:
	NoOperands(double _p) : p(_p) {};
	void show() {
		cout << "There is no pair for operand " << "'" << p << "'" << endl;
	}
};