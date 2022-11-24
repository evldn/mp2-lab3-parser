#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
enum TypeElement {
	Operation,
	Value,
	None
};

class Lexema {
	string str;
	TypeElement type;
	int position;
public:
	Lexema() : type(None), position(-1) {};
	Lexema(string _str, TypeElement _type, int pos) : str(_str), type(_type), position(pos) {};
	Lexema(const Lexema& p) : str(p.str), type(p.type), position(p.position) {};
	Lexema& operator=(const Lexema& p);
	string getStr() { return str; }
	int getPos() { return position; }
	TypeElement getType() { return type; }
	bool operator==(const Lexema& v);
	friend ostream& operator << (ostream& out, const Lexema& p) {
		out << "{" << p.str << ", ";
		if (p.type == Operation) {
			out << "operation";
		}
		else if (p.type == Value) {
			out << "value";
		};
		out << "}";
		return out;
	}
};