#include "Lexema.h"

Lexema& Lexema::operator=(const Lexema& p) {
	if (this == &p) {
		return *this;
	}
	str = p.str;
	type = p.type;
	position = p.position;
	return *this;
}

bool Lexema::operator==(const Lexema& v) {
	if (type == v.type) {
		if (str == v.str) {
			return true;
		}
	}
	return false;
}
