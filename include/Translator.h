#pragma once
#include "Lexema.h"
#include "Queue.h"
#include "Stack.h"
#include "Exception.h"
class Translator {
	double res;
public:
	void �alculate(Queue<Lexema>pz);
	double getResult() { return res; }
};